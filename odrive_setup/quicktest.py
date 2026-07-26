#!/usr/bin/env python3
"""
test_axis.py — Quick sanity check for a calibrated ODrive axis.

Connects, checks for existing errors, enters closed loop control,
commands a small back-and-forth position move, watches current draw,
then returns to idle. Meant to be run right after quicksetup.py, before
a board goes into the arm.

Usage:
    python3 test_axis.py --axis 0
    python3 test_axis.py --axis 0 --serial-number 3355365D3334
    python3 test_axis.py --axis 0 --turns 0.25 --current-limit 5.0
"""
import argparse
import time

import odrive
from odrive import enums
from odrive.utils import dump_errors


def main():
    parser = argparse.ArgumentParser(description="Quick ODrive axis sanity test")
    parser.add_argument("--axis", type=int, choices=[0, 1], default=0)
    parser.add_argument("--serial-number", help="Target a specific ODrive")
    parser.add_argument("--turns", type=float, default=0.25, help="Move size in turns (default: 0.25)")
    parser.add_argument("--current-limit", type=float, default=None,
                         help="Temporarily cap motor.config.current_lim for this test (amps)")
    parser.add_argument("--settle-time", type=float, default=2.0, help="Seconds to hold each position")
    args = parser.parse_args()

    print("Connecting...")
    odrv = odrive.find_any(serial_number=args.serial_number) if args.serial_number else odrive.find_any()
    print(f"Connected to {odrv.serial_number:012X}")

    axis = getattr(odrv, f"axis{args.axis}")

    if axis.motor.error != 0 or axis.encoder.error != 0 or axis.error != 0:
        print("Axis already has errors before starting — aborting test.")
        dump_errors(odrv)
        return

    if not axis.motor.config.pre_calibrated or not axis.encoder.config.pre_calibrated:
        print("WARNING: axis is not marked pre_calibrated — proceeding anyway, but this may run calibration on entry.")

    original_current_lim = axis.motor.config.current_lim
    if args.current_limit is not None:
        print(f"Temporarily setting current_lim to {args.current_limit}A for this test")
        axis.motor.config.current_lim = args.current_limit

    try:
        print("Entering closed loop control...")
        axis.requested_state = enums.AxisState.CLOSED_LOOP_CONTROL
        time.sleep(0.5)

        if axis.current_state != enums.AxisState.CLOSED_LOOP_CONTROL:
            print("Failed to enter closed loop control.")
            dump_errors(odrv)
            return

        start_pos = axis.pos_estimate

        for target in (start_pos + args.turns, start_pos):
            print(f"Commanding position {target:.3f} turns...")
            axis.controller.input_pos = target

            t0 = time.time()
            max_current = 0.0
            while time.time() - t0 < args.settle_time:
                max_current = max(max_current, abs(axis.motor.current_control.Iq_measured))
                if axis.error != 0 or axis.motor.error != 0:
                    print("Error occurred mid-move:")
                    dump_errors(odrv)
                    return
                time.sleep(0.05)

            print(f"  reached {axis.pos_estimate:.3f} turns, peak current ~{max_current:.2f}A")

        print("Test complete, no errors. Returning to idle.")

    finally:
        axis.requested_state = enums.AxisState.IDLE
        if args.current_limit is not None:
            axis.motor.config.current_lim = original_current_lim


if __name__ == "__main__":
    main()