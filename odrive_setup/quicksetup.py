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
    python3 setup_odrive.py closed_loop_6354.json
    python3 setup_odrive.py closed_loop_5065.json --axis 0
    python3 setup_odrive.py closed_loop_6354.json --serial-number 336436543334
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
    args = parser.parse_args()

    print("Connecting for initial cleanup...")
    odrv = odrive.find_any(serial_number=args.serial_number) if args.serial_number else odrive.find_any()
    print(f"Connected to {odrv.serial_number:012X}")

    print("Clearing any existing errors...")
    odrv.axis0.clear_errors()

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

    print("Connecting...")
    odrv = odrive.find_any(serial_number=args.serial_number) if args.serial_number else odrive.find_any()
    print(f"Connected to {odrv.serial_number:012X}")

    run_calibration(odrv, args.axis)

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
    odrv.axis0.clear_errors()

    print("Restarting board...")
    try:
        odrv.reboot()
    except Exception:
        # reboot() drops the connection — expected, not an error
        pass

    print("Done. Board is calibrated, errors cleared, and will boot pre_calibrated from now on.")


if __name__ == "__main__":
    main()