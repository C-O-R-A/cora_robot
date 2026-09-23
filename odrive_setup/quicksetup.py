#!/usr/bin/env python3
"""
setup_odrive.py — Automates ODrive v3.6 setup + calibration.

Order matters here: restore-config runs as the FIRST thing, via a plain
odrivetool subprocess, before any Python-side odrive.find_any() connection
is ever opened. Opening a Python connection first and then shelling out to
odrivetool while that connection was still alive caused persistent
"Could not claim interface" USB conflicts — the two processes fought over
the same USB device. Doing restore first, with no competing connection to
fight, avoids the problem structurally rather than trying to explicitly
release a connection object afterward (which did not reliably work).

Steps:
    1. restore-config (subprocess, no Python connection open yet)
    2. save + reboot (via a fresh Python connection)
    3. full calibration
    4. set pre_calibrated flags
    5. save + reboot
    6. reconnect, clear errors, restart clean

Usage:
    python3 quicksetup.py configs/closed_loop_6354.json --axis 0
    python3 quicksetup.py configs/closed_loop_5065.json --axis 0
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
    """Poll until an ODrive USB device re-enumerates, rather than guessing with a fixed sleep."""
    start = time.time()
    while time.time() - start < timeout:
        result = subprocess.run(["lsusb"], capture_output=True, text=True)
        if ODRIVE_USB_ID in result.stdout:
            return
        time.sleep(poll_interval)
    raise TimeoutError(f"ODrive USB device did not re-enumerate within {timeout}s")


def wait_for_state(axis, target_state, timeout=90):
    start = time.time()
    while axis.current_state != target_state:
        if time.time() - start > timeout:
            raise TimeoutError(f"Timed out waiting for axis state {target_state}")
        time.sleep(0.1)


def run_calibration(odrv, axis_num):
    axis = getattr(odrv, f"axis{axis_num}")

    print(f"[axis{axis_num}] Running full calibration sequence...")
    axis.requested_state = enums.AxisState.FULL_CALIBRATION_SEQUENCE
    wait_for_state(axis, enums.AxisState.IDLE)

    if axis.error != 0 or axis.motor.error != 0 or axis.encoder.error != 0:
        dump_errors(odrv)
        raise RuntimeError(f"axis{axis_num} calibration failed — see errors above")

    print(f"[axis{axis_num}] Calibration OK, setting pre_calibrated flags")
    axis.motor.config.pre_calibrated = True
    axis.encoder.config.pre_calibrated = True


def diagnose_calibration_failure(odrv, axis_num):
    axis = getattr(odrv, f"axis{axis_num}")
    print(f"\n[axis{axis_num}] Calibration failure diagnosis:")
    print("  - PHASE_RESISTANCE_OUT_OF_RANGE usually means the motor is not a valid 3-phase BLDC for this axis,")
    print("      the phase leads are disconnected or miswired, the motor is damaged, or the board is seeing a bad load.")
    print("  - CURRENT_MEASUREMENT_TIMEOUT on another axis usually points to a shared power issue on the ODrive board,")
    print("      such as bad DC bus wiring, a short, a weak supply, or one motor drawing too much current.")
    print("  - Check: motor phase ordering, correct pole_pairs value, clean power supply, no short between phases,")
    print("      and test each axis separately if both axes are connected at once.")
    if axis.motor.error != 0:
        print(f"  - axis{axis_num} motor error bits: {axis.motor.error}")
    if axis.error != 0:
        print(f"  - axis{axis_num} axis error bits: {axis.error}")


def reconnect(serial_number, timeout=15):
    start = time.time()
    while True:
        try:
            return odrive.find_any(serial_number=serial_number) if serial_number else odrive.find_any(timeout=timeout)
        except Exception:
            if time.time() - start > timeout:
                raise
            time.sleep(0.5)


def find_odrivetool_executable():
    """Return a path to the odrivetool executable.

    Prefer an `odrivetool` installed alongside the current Python executable (virtualenv),
    then fall back to `shutil.which('odrivetool')`.
    """
    venv_bin = os.path.dirname(sys.executable)
    candidate = os.path.join(venv_bin, "odrivetool")
    if os.path.isfile(candidate) and os.access(candidate, os.X_OK):
        return candidate

    which_path = shutil.which("odrivetool")
    if which_path:
        return which_path

    return None


def main():
    parser = argparse.ArgumentParser(description="Automated ODrive v3.6 setup + calibration")
    parser.add_argument("config", help="Path to config json (e.g. closed_loop_6354.json)")
    parser.add_argument("--axis", type=int, choices=[0, 1], default=0, help="Axis to calibrate (default: 0)")
    parser.add_argument("--serial-number", help="Target a specific ODrive — required if more than one board is plugged in at once")
    parser.add_argument("--max-attempts", type=int, default=10, help="Give up after this many failed calibration attempts (default: 10)")
    parser.add_argument("--can-node-id", type=int, default=1, help="CAN node ID to apply to this joint/axis (default: 1)")
    args = parser.parse_args()

    odrivetool_exe = find_odrivetool_executable()
    if not odrivetool_exe:
        raise RuntimeError(
            "odrivetool not found. Install it in your virtualenv or system PATH, "
            "or run the script with the virtualenv python (e.g. /path/to/.venv/bin/python quicksetup.py ...)"
        )

    # --- Step 1: restore-config, BEFORE any Python connection is opened ---
    # No odrive.find_any() has run yet in this process, so there is nothing
    # for this subprocess to conflict with over the USB interface.
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
        raise RuntimeError(f"restore-config failed after {restore_attempts} attempts — check hardware/USB connection.")

    print("Configuration restored. Waiting for board to settle after its own reboot...")
    time.sleep(3)
    wait_for_odrive_usb()

    # --- Step 2 onward: now safe to open the one and only Python connection ---
    print("Connecting...")
    odrv = odrive.find_any(serial_number=args.serial_number) if args.serial_number else odrive.find_any()
    print(f"Connected to {odrv.serial_number:012X}")

    if hasattr(odrv.config, "enable_brake_resistor") and hasattr(odrv.config, "brake_resistance"):
        if odrv.config.enable_brake_resistor and odrv.config.brake_resistance > 0.0:
            print("WARNING: brake resistor is enabled in config. Boards without a physical brake resistor can trip BRAKE_RESISTOR_DISARMED during calibration.")

    axis = getattr(odrv, f"axis{args.axis}")

    print("Clearing any existing errors...")
    axis.clear_errors()

    print(f"vbus_voltage before calibration: {odrv.vbus_voltage:.2f}V")

    for attempt in range(1, args.max_attempts + 1):
        print(f"Calibration attempt {attempt}/{args.max_attempts}...")
        try:
            run_calibration(odrv, args.axis)
            break  # success — fall through to save/reboot below
        except RuntimeError as e:
            print(f"  attempt {attempt} failed: {e}")
            diagnose_calibration_failure(odrv, args.axis)
            axis.clear_errors()
            time.sleep(1.0)
    else:
        raise RuntimeError(
            f"Calibration did not succeed after {args.max_attempts} attempts — "
            "stopping rather than retrying forever. Check hardware before trying again."
        )

    # Apply selected CAN node ID to this joint/axis before saving.
    can_id = input(f"Enter CAN node ID for this joint/axis (default {args.can_node_id}): ")
    if can_id.strip():
        try:
            args.can_node_id = int(can_id)
        except ValueError:
            print(f"Invalid CAN node ID '{can_id}', using default {args.can_node_id}.")
    odrv.axis0.config.can_node_id = args.can_node_id
    print(f"Set CAN node ID to {args.can_node_id} for this ODrive axis/joint.")

    print("Saving configuration (device will reboot)...")
    try:
        odrv.save_configuration()
    except Exception:
        pass  # save_configuration() reboots and drops the connection — expected

    print("Waiting for board to come back up...")
    wait_for_odrive_usb()

    print("Reconnecting to clear errors...")
    odrv = reconnect(args.serial_number)
    getattr(odrv, f"axis{args.axis}").clear_errors()

    print("Restarting board...")
    try:
        odrv.reboot()
    except Exception:
        pass  # reboot() drops the connection — expected, not an error

    print("Done. Board is calibrated, errors cleared, and will boot pre_calibrated from now on.")


if __name__ == "__main__":
    main()