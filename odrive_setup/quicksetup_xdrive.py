#!/usr/bin/env python3
"""
quicksetup_xdrive.py: automates ODrive v3.6 restore + calibration + save.

Flow:
    1. restore-config via odrivetool subprocess (no Python connection open yet,
       which avoids USB "Could not claim interface" conflicts)
    2. connect, optional encoder bandwidth override, encoder noise check
    3. full calibration (waits for it to really start AND really finish)
    4. verify calibration (no errors, motor direction != 0, motor/encoder ready)
    5. set pre_calibrated flags + CAN node ID (single save, single reboot)
    6. reconnect and verify the flags and settings survived the reboot

Usage:
    python3 quicksetup_xdrive.py configs/6354_270kv/6354_mks_xdrive.json --axis 0
    python3 quicksetup_xdrive.py configs/6354_270kv/6354_mks_xdrive.json --axis 0 --can-node-id 2
    python3 quicksetup_xdrive.py configs/6354_270kv/6354_mks_xdrive.json --axis 0 --encoder-bandwidth 300
"""
import argparse
import os
import shutil
import subprocess
import sys
import time

import odrive
from odrive import enums
from odrive.utils import dump_errors


ODRIVE_USB_ID = "1209:0d32"


def wait_for_odrive_usb(timeout=20, poll_interval=0.5):
    """Poll until an ODrive USB device enumerates, instead of guessing with a fixed sleep."""
    start = time.time()
    while time.time() - start < timeout:
        result = subprocess.run(["lsusb"], capture_output=True, text=True)
        if ODRIVE_USB_ID in result.stdout:
            return
        time.sleep(poll_interval)
    raise TimeoutError(f"ODrive USB device did not enumerate within {timeout}s")


def connect(serial_number=None, timeout=30):
    """Wait for the board to be on USB, then open a Python connection to it."""
    wait_for_odrive_usb()
    time.sleep(1.0)  # let the board finish booting after enumeration
    if serial_number:
        return odrive.find_any(serial_number=serial_number, timeout=timeout)
    return odrive.find_any(timeout=timeout)


def find_odrivetool_executable():
    """Prefer odrivetool next to the current python (venv), else look on PATH."""
    candidate = os.path.join(os.path.dirname(sys.executable), "odrivetool")
    if os.path.isfile(candidate) and os.access(candidate, os.X_OK):
        return candidate
    return shutil.which("odrivetool")


def any_axis_error(axis):
    return (
        axis.error != 0
        or axis.motor.error != 0
        or axis.encoder.error != 0
        or axis.controller.error != 0
    )


def check_encoder_noise(axis, samples=20, interval=0.05, warn_threshold=0.5):
    """With the motor idle and the shaft still, vel_estimate should sit near 0."""
    values = []
    for _ in range(samples):
        values.append(axis.encoder.vel_estimate)
        time.sleep(interval)
    worst = max(abs(v) for v in values)
    print(f"Encoder noise check (shaft must be still): max |vel_estimate| = {worst:.3f} turns/s")
    if worst > warn_threshold:
        print("WARNING: encoder velocity is noisy at rest. Closed loop will likely oscillate or run away.")
        print("         Try --encoder-bandwidth 300 (or 100), and check SPI wiring, CS pin and encoder mode.")
    return worst


def run_calibration(odrv, axis_num, timeout=90):
    axis = getattr(odrv, f"axis{axis_num}")
    axis.clear_errors()

    print(f"[axis{axis_num}] Running full calibration sequence (shaft must be free to turn)...")
    axis.requested_state = enums.AxisState.FULL_CALIBRATION_SEQUENCE

    # 1) Wait for the state to LEAVE idle. Without this, the next wait returns instantly
    #    because the state can still read IDLE right after the request.
    start = time.time()
    while axis.current_state == enums.AxisState.IDLE and time.time() - start < 5.0:
        time.sleep(0.05)

    # 2) Wait for the sequence to finish (back to idle).
    start = time.time()
    while axis.current_state != enums.AxisState.IDLE:
        if time.time() - start > timeout:
            raise TimeoutError(f"axis{axis_num} calibration did not finish within {timeout}s")
        time.sleep(0.1)

    # 3) Verify that it really worked.
    if any_axis_error(axis):
        dump_errors(odrv)
        raise RuntimeError(f"axis{axis_num} calibration failed, see errors above")
    if axis.motor.config.direction == 0:
        raise RuntimeError(f"axis{axis_num} calibration did not complete (motor direction is still 0)")
    if not (axis.motor.is_calibrated and axis.encoder.is_ready):
        raise RuntimeError(
            f"axis{axis_num} motor.is_calibrated={axis.motor.is_calibrated}, "
            f"encoder.is_ready={axis.encoder.is_ready}"
        )

    print(
        f"[axis{axis_num}] Calibration OK: direction={axis.motor.config.direction}, "
        f"offset_float={axis.encoder.config.offset_float:.4f}"
    )


def diagnose_calibration_failure(odrv, axis_num):
    axis = getattr(odrv, f"axis{axis_num}")
    print(f"\n[axis{axis_num}] Calibration failure diagnosis:")
    print("  - PHASE_RESISTANCE_OUT_OF_RANGE: motor not connected, phase leads miswired, or bad load.")
    print("  - CURRENT_MEASUREMENT_TIMEOUT: shared power issue (DC bus wiring, short, weak supply).")
    print("  - Encoder errors: check encoder mode, cpr, SPI wiring and chip select pin.")
    print("  - Also check pole_pairs and that the shaft is free to turn.")
    print(f"  - axis.error={axis.error} motor.error={axis.motor.error} "
          f"encoder.error={axis.encoder.error} controller.error={axis.controller.error}")


def apply_flags_and_save(odrv, axis_num, can_node_id, startup_closed_loop):
    """Set flags and CAN ID on the given axis, then save. The save reboots the board."""
    axis = getattr(odrv, f"axis{axis_num}")
    axis.motor.config.pre_calibrated = True
    axis.encoder.config.pre_calibrated = True
    axis.config.can_node_id = can_node_id
    axis.config.startup_closed_loop_control = startup_closed_loop
    print("Saving configuration (device will reboot)...")
    try:
        odrv.save_configuration()
    except Exception:
        pass  # save_configuration() reboots and drops the connection, expected


def verify_after_reboot(odrv, axis_num, can_node_id, startup_closed_loop, saved_offset):
    """Judge persistence by effect. Returns (problems, warnings)."""
    axis = getattr(odrv, f"axis{axis_num}")
    problems = []
    warnings = []
    if not axis.motor.config.pre_calibrated:
        problems.append("motor.config.pre_calibrated is False")
    if axis.motor.config.direction == 0:
        problems.append("motor.config.direction is 0")
    if not axis.motor.is_calibrated:
        problems.append("motor.is_calibrated is False after reboot")
    if axis.config.can_node_id != can_node_id:
        problems.append(f"can_node_id is {axis.config.can_node_id}, expected {can_node_id}")
    if axis.config.startup_closed_loop_control != startup_closed_loop:
        problems.append("startup_closed_loop_control did not persist")

    # Encoder: the flag alone is not what matters, a usable encoder with the saved offset is.
    offset_ok = abs(axis.encoder.config.offset_float - saved_offset) < 1e-3
    if not offset_ok:
        problems.append(
            f"encoder offset_float is {axis.encoder.config.offset_float:.4f}, expected {saved_offset:.4f}"
        )
    if not axis.encoder.config.pre_calibrated:
        if axis.encoder.is_ready and offset_ok:
            warnings.append(
                "encoder.config.pre_calibrated reads False after reboot, but encoder.is_ready is True "
                "and the saved offset is intact, so this firmware does not seem to need the flag."
            )
        else:
            problems.append("encoder.config.pre_calibrated is False and encoder.is_ready is False")
    return problems, warnings


def check_startup_closed_loop(odrv, axis_num, timeout=5.0):
    """Return None if the axis entered closed loop by itself after boot, else a description of why not."""
    axis = getattr(odrv, f"axis{axis_num}")
    start = time.time()
    while time.time() - start < timeout:
        if axis.current_state == enums.AxisState.CLOSED_LOOP_CONTROL:
            return None
        time.sleep(0.1)
    return (
        f"axis did not enter closed loop on boot: current_state={axis.current_state}, "
        f"axis.error={axis.error}, motor.error={axis.motor.error}, "
        f"encoder.error={axis.encoder.error}, controller.error={axis.controller.error}, "
        f"encoder.is_ready={axis.encoder.is_ready}"
    )


def main():
    parser = argparse.ArgumentParser(description="Automated ODrive v3.6 setup + calibration")
    parser.add_argument("config", help="Path to config json")
    parser.add_argument("--axis", type=int, choices=[0, 1], default=0, help="Axis to calibrate (default: 0)")
    parser.add_argument("--serial-number", help="Target a specific ODrive (needed if several are plugged in)")
    parser.add_argument("--max-attempts", type=int, default=3, help="Calibration attempts before giving up (default: 3)")
    parser.add_argument("--can-node-id", type=int, default=None,
                        help="CAN node ID for this axis. If omitted you are asked up front.")
    parser.add_argument("--encoder-bandwidth", type=float, default=None,
                        help="Override encoder.config.bandwidth before calibration (e.g. 300 to reduce noise)")
    parser.add_argument("--startup-closed-loop", action="store_true",
                        help="Enter closed loop automatically on boot (off by default, the axis powers up energized)")
    args = parser.parse_args()

    odrivetool_exe = find_odrivetool_executable()
    if not odrivetool_exe:
        raise RuntimeError(
            "odrivetool not found. Install it in your virtualenv or PATH, "
            "or run with the venv python (e.g. /path/to/.venv/bin/python quicksetup_xdrive.py ...)"
        )

    # Ask for the CAN node ID first so the rest of the run is unattended.
    if args.can_node_id is None:
        raw = input("Enter CAN node ID for this joint/axis (default 1): ").strip()
        try:
            args.can_node_id = int(raw) if raw else 1
        except ValueError:
            print(f"Invalid CAN node ID '{raw}', using 1.")
            args.can_node_id = 1

    # --- Step 1: restore-config BEFORE any Python connection is opened ---
    print(f"Restoring config from {args.config} (no Python connection open yet)...")
    restore_cmd = [odrivetool_exe, "restore-config", args.config]
    if args.serial_number:
        restore_cmd += ["--serial-number", args.serial_number]

    restore_attempts = 5
    for attempt in range(1, restore_attempts + 1):
        result = subprocess.run(restore_cmd)
        if result.returncode == 0:
            break
        print(f"  restore-config attempt {attempt}/{restore_attempts} failed (exit {result.returncode}), retrying...")
        wait_for_odrive_usb()
        time.sleep(1.5)
    else:
        raise RuntimeError(f"restore-config failed after {restore_attempts} attempts, check hardware/USB.")

    print("Config restored (read-only property warnings above are harmless). Waiting for board to settle...")
    time.sleep(3)

    # --- Step 2: the one Python connection ---
    print("Connecting...")
    odrv = connect(args.serial_number)
    serial = f"{odrv.serial_number:012X}"
    print(f"Connected to {serial}")

    if hasattr(odrv.config, "enable_brake_resistor") and hasattr(odrv.config, "brake_resistance"):
        if odrv.config.enable_brake_resistor and odrv.config.brake_resistance > 0.0:
            print("WARNING: brake resistor is enabled in config. Boards without a physical brake "
                  "resistor can trip BRAKE_RESISTOR_DISARMED during calibration.")

    axis = getattr(odrv, f"axis{args.axis}")
    axis.clear_errors()
    print(f"vbus_voltage before calibration: {odrv.vbus_voltage:.2f}V")

    if args.encoder_bandwidth is not None:
        axis.encoder.config.bandwidth = args.encoder_bandwidth
        print(f"Encoder bandwidth set to {args.encoder_bandwidth}")

    check_encoder_noise(axis)

    # --- Step 3: calibration with retries ---
    for attempt in range(1, args.max_attempts + 1):
        print(f"Calibration attempt {attempt}/{args.max_attempts}...")
        try:
            run_calibration(odrv, args.axis)
            break
        except (RuntimeError, TimeoutError) as e:
            print(f"  attempt {attempt} failed: {e}")
            diagnose_calibration_failure(odrv, args.axis)
            axis.clear_errors()
            time.sleep(1.0)
    else:
        raise RuntimeError(
            f"Calibration did not succeed after {args.max_attempts} attempts. "
            "Stopping, check hardware before trying again."
        )

    # --- Step 4: flags + CAN ID + ONE save/reboot, then verify (retry once if anything did not stick) ---
    saved_offset = axis.encoder.config.offset_float
    for save_attempt in (1, 2):
        apply_flags_and_save(odrv, args.axis, args.can_node_id, args.startup_closed_loop)
        print("Waiting for board to come back up...")
        odrv = connect(serial)
        problems, warnings = verify_after_reboot(
            odrv, args.axis, args.can_node_id, args.startup_closed_loop, saved_offset
        )
        for w in warnings:
            print(f"  note: {w}")
        if not problems:
            break
        print(f"  verification after reboot failed (save attempt {save_attempt}): {', '.join(problems)}")
        if save_attempt == 2:
            raise RuntimeError(
                "Settings did not persist after two saves. Check the tool/firmware versions and re-run."
            )

    axis = getattr(odrv, f"axis{args.axis}")
    if args.startup_closed_loop:
        msg = check_startup_closed_loop(odrv, args.axis)
        if msg:
            raise RuntimeError(msg)
        print("Axis entered closed loop by itself after reboot. Returning it to idle for safety "
              "(it will enter closed loop again on the next boot).")
        axis.requested_state = enums.AxisState.IDLE
        time.sleep(0.3)

    axis.clear_errors()

    print("Done. Board is calibrated, flags and CAN node ID persisted across reboot.")
    if args.startup_closed_loop:
        print("The axis will enter closed loop automatically on every boot.")
    else:
        print("Closed loop is NOT entered on boot. Request it with axis.requested_state = 8, "
              "or re-run with --startup-closed-loop.")


if __name__ == "__main__":
    main()