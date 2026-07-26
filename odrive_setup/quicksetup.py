#!/usr/bin/env python3
"""
setup_odrive.py — Automates ODrive v3.6 setup + calibration.

Replaces the manual odrivetool session:
    1. restore-config
    2. save + reboot
    3. full calibration
    4. set pre_calibrated flags
    5. save + reboot
    6. reconnect, clear errors, restart clean

Usage:
    python3 quicksetup.py configs/closed_loop_6354.json --axis 0
    python3 quicksetup.py configs/closed_loop_5065.json --axis 0
"""
import argparse
import subprocess
import time

import odrive
from odrive import enums
from odrive.utils import dump_errors


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


def run_anticogging_calibration(odrv, axis_num, timeout=180):
    axis = getattr(odrv, f"axis{axis_num}")

    print(f"[axis{axis_num}] Entering closed loop control for anticogging calibration...")
    axis.requested_state = enums.AxisState.CLOSED_LOOP_CONTROL
    time.sleep(0.3)
    if axis.current_state != enums.AxisState.CLOSED_LOOP_CONTROL:
        dump_errors(odrv)
        raise RuntimeError(f"axis{axis_num} failed to enter closed loop control for anticogging calibration")

    print(f"[axis{axis_num}] Starting anticogging calibration (axis will spin slowly)...")
    axis.controller.start_anticogging_calibration()
    time.sleep(0.3)  # let calib_anticogging flip True before we start polling for it going False

    start = time.time()
    
    while not axis.controller.config.anticogging.calib_anticogging:
        print("waiting to calibrate anticogging...")
        time.sleep(1)
    
    while axis.controller.config.anticogging.calib_anticogging:
        if axis.error != 0 or axis.motor.error != 0 or axis.controller.error != 0:
            dump_errors(odrv)
            raise RuntimeError(f"axis{axis_num} anticogging calibration failed — see errors above")
        if time.time() - start > timeout:
            raise TimeoutError(f"axis{axis_num} anticogging calibration did not finish within {timeout}s")
        time.sleep(0.2)

    axis.requested_state = enums.AxisState.IDLE

    print(f"[axis{axis_num}] Anticogging calibration OK, setting pre_calibrated flag")
    axis.controller.config.anticogging.pre_calibrated = True


def reconnect(serial_number, timeout=15):
    start = time.time()
    while True:
        try:
            return odrive.find_any(serial_number=serial_number) if serial_number else odrive.find_any(timeout=timeout)
        except Exception:
            if time.time() - start > timeout:
                raise
            time.sleep(0.5)


def main():
    parser = argparse.ArgumentParser(description="Automated ODrive v3.6 setup + calibration")
    parser.add_argument("config", help="Path to config json (e.g. closed_loop_6354.json)")
    parser.add_argument("--axis", type=int, choices=[0, 1], default=0, help="Axis to calibrate (default: 0)")
    parser.add_argument("--serial-number", help="Target a specific ODrive — required if more than one board is plugged in at once")
    parser.add_argument("--max-attempts", type=int, default=10, help="Give up after this many failed calibration attempts (default: 10)")
    parser.add_argument("--no-anticogging", dest="anticogging", action="store_false",
                         help="Skip anticogging calibration (runs by default after motor/encoder calibration succeeds)")
    parser.set_defaults(anticogging=False)
    args = parser.parse_args()

    print("Connecting for initial cleanup...")
    odrv = odrive.find_any(serial_number=args.serial_number) if args.serial_number else odrive.find_any()
    print(f"Connected to {odrv.serial_number:012X}")

    axis = getattr(odrv, f"axis{args.axis}")

    print("Clearing any existing errors...")
    axis.clear_errors()

    print("Restarting board (clean boot before restore)...")
    try:
        odrv.reboot()
    except Exception:
        # reboot() drops the connection — expected, not an error
        pass

    print("Waiting for board to come back up...")
    time.sleep(5)

    print(f"Restoring config from {args.config} ...")
    restore_cmd = ["odrivetool", "restore-config", args.config]
    if args.serial_number:
        restore_cmd += ["--serial-number", args.serial_number]
    subprocess.run(restore_cmd, check=True)
    time.sleep(3)  # restore-config triggers its own reboot; let it come back up

    # print("Connect Motor...")
    # while True:
    #     motor_connected_flag = input("motor connected? (y/n)")
    #     match motor_connected_flag:
    #         case "y":
    #             break
    #         case "n":
    #             continue
    #         case _:
    #             print("answer 'y' when connected")

    print("Connecting...")
    odrv = odrive.find_any(serial_number=args.serial_number) if args.serial_number else odrive.find_any()
    print(f"Connected to {odrv.serial_number:012X}")
    axis = getattr(odrv, f"axis{args.axis}")  # re-fetch — odrv is a new connection object

    print(f"vbus_voltage before calibration: {odrv.vbus_voltage:.2f}V")

    for attempt in range(1, args.max_attempts + 1):
        print(f"Calibration attempt {attempt}/{args.max_attempts}...")
        try:
            run_calibration(odrv, args.axis)
            break  # success — fall through to save/reboot below
        except RuntimeError as e:
            print(f"  attempt {attempt} failed: {e}")
            axis.clear_errors()
            time.sleep(1.0)
    else:
        raise RuntimeError(
            f"Calibration did not succeed after {args.max_attempts} attempts — "
            "stopping rather than retrying forever. Check hardware before trying again."
        )

    if args.anticogging:
        run_anticogging_calibration(odrv, args.axis)

    print("Saving configuration (device will reboot)...")
    try:
        odrv.save_configuration()
    except Exception:
        # save_configuration() reboots and drops the connection — expected, not an error
        pass

    print("Waiting for board to come back up...")
    time.sleep(5)

    print("Reconnecting to clear errors...")
    odrv = reconnect(args.serial_number)
    getattr(odrv, f"axis{args.axis}").clear_errors()

    print("Restarting board...")
    try:
        odrv.reboot()
    except Exception:
        # reboot() drops the connection — expected, not an error
        pass

    print("Done. Board is calibrated, errors cleared, and will boot pre_calibrated from now on.")


if __name__ == "__main__":
    main()