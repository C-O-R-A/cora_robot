#!/usr/bin/env python3
"""
test_axis.py — Quick sanity check for a calibrated ODrive axis.

Restarts the board for a clean state, checks for existing errors, enters
closed loop control, runs either a position step-and-back or a velocity
ramp test, watching current draw, then returns to idle. Meant to be run
right after quicksetup.py, before a board goes into the arm.

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


def reconnect(serial_number, timeout=15):
    start = time.time()
    while True:
        try:
            return odrive.find_any(serial_number=serial_number) if serial_number else odrive.find_any(timeout=timeout)
        except Exception:
            if time.time() - start > timeout:
                raise
            time.sleep(0.5)


def run_position_test(odrv, axis, args):
    start_pos = axis.encoder.pos_estimate

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

        print(f"  reached {axis.encoder.pos_estimate:.3f} turns, peak current ~{max_current:.2f}A")

    print("Position test complete, no errors.")


def run_velocity_ramp_test(odrv, axis, args):
    axis.controller.config.control_mode = enums.ControlMode.VELOCITY_CONTROL

    steps = max(int(args.ramp_time / args.ramp_dt), 1)

    def ramp(from_vel, to_vel, label):
        print(f"Ramping {label}: {from_vel:.2f} -> {to_vel:.2f} turns/s over {args.ramp_time:.1f}s...")
        max_current = 0.0
        for i in range(steps + 1):
            target = from_vel + (to_vel - from_vel) * (i / steps)
            axis.controller.input_vel = target
            max_current = max(max_current, abs(axis.motor.current_control.Iq_measured))
            if axis.error != 0 or axis.motor.error != 0:
                print(f"Error occurred mid-ramp ({label}):")
                dump_errors(odrv)
                return False, max_current
            time.sleep(args.ramp_dt)
        print(f"  {label} complete, vel_estimate={axis.encoder.vel_estimate:.2f} turns/s, "
              f"peak current ~{max_current:.2f}A")
        return True, max_current

    ok, _ = ramp(0.0, args.max_vel, "ramp up")
    if not ok:
        return

    print(f"Holding at {args.max_vel:.2f} turns/s for {args.hold_time:.1f}s...")
    t0 = time.time()
    while time.time() - t0 < args.hold_time:
        if axis.error != 0 or axis.motor.error != 0:
            print("Error occurred during hold:")
            dump_errors(odrv)
            return
        time.sleep(0.05)

    ok, _ = ramp(args.max_vel, 0.0, "ramp down")
    if not ok:
        return

    print("Velocity ramp test complete, no errors.")


def main():
    parser = argparse.ArgumentParser(description="Quick ODrive axis sanity test")
    parser.add_argument("--axis", type=int, choices=[0, 1], default=0)
    parser.add_argument("--serial-number", help="Target a specific ODrive")
    parser.add_argument("--mode", choices=["position", "velocity"], default="position",
                         help="Test type: position step-and-back, or velocity ramp up/down (default: position)")
    parser.add_argument("--no-restart", dest="restart", action="store_false",
                         help="Skip rebooting the board before the test (restarts by default for a clean state)")
    parser.set_defaults(restart=True)
    # Position test args
    parser.add_argument("--turns", type=float, default=0.25, help="Move size in turns (default: 0.25)")
    parser.add_argument("--settle-time", type=float, default=2.0, help="Seconds to hold each position")
    # Velocity ramp test args
    parser.add_argument("--max-vel", type=float, default=8.0, help="Peak velocity in turns/s for ramp test")
    parser.add_argument("--ramp-time", type=float, default=20.0, help="Seconds for each ramp up/down leg")
    parser.add_argument("--ramp-dt", type=float, default=0.02, help="Step interval during ramp (seconds)")
    parser.add_argument("--hold-time", type=float, default=1.0, help="Seconds to hold at max_vel before ramping down")
    parser.add_argument("--current-limit", type=float, default=None,
                         help="Temporarily cap motor.config.current_lim for this test (amps)")
    args = parser.parse_args()

    print("Connecting...")
    odrv = odrive.find_any(serial_number=args.serial_number) if args.serial_number else odrive.find_any()
    print(f"Connected to {odrv.serial_number:012X}")

    if args.restart:
        print("Restarting board for a clean state before testing...")
        try:
            odrv.reboot()
        except Exception:
            pass  # reboot() drops the connection — expected, not an error

        print("Waiting for board to come back up...")
        time.sleep(5)

        print("Reconnecting...")
        odrv = reconnect(args.serial_number)
        print(f"Connected to {odrv.serial_number:012X}")

    axis = getattr(odrv, f"axis{args.axis}")

    if axis.motor.error != 0 or axis.encoder.error != 0 or axis.error != 0:
        print("Clearing existing errors before starting...")
        axis.clear_errors()
        time.sleep(0.1)

    if axis.motor.error != 0 or axis.encoder.error != 0 or axis.error != 0:
        print("Errors still present after clear_errors() — aborting test.")
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

        run_velocity_ramp_test(odrv, axis, args)

    finally:
        axis.controller.input_vel = 0.0
        axis.requested_state = enums.AxisState.IDLE
        if args.current_limit is not None:
            axis.motor.config.current_lim = original_current_lim


if __name__ == "__main__":
    main()