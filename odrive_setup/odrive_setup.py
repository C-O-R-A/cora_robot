import os
import sys
import time
from cmath import pi
from logging import exception

import odrive

def save_odrive(odrv):

    print("Saving ODrive")

    odrv.axis0.requested_state = 1
    odrv.axis1.requested_state = 1
    try:
        odrv.save_configuration()
        countdown(5)
    except Exception:
        countdown(5)
    print()

    odrv = odrive.find_any()
    odrv.axis0.requested_state = 1
    odrv.axis1.requested_state = 1

    return odrv

def countdown(t):

    for i in range(t):

        # write = sys.stdout.write
        # write('\b \b')
        if (t - i) > 1:
            print(f"Please wait {t - i} seconds  \t", end="\r")
        else:
            print("Please wait 1 second  \t", end="\r")
        time.sleep(1)
    print("                          ", end="\r")

def autoanticog(odrv, skip_full_cal=False):

    odrv.axis0.requested_state = 8
    odrv.axis0.controller.config.anticogging.pre_calibrated = False  # {False}
    odrv.axis0.controller.config.control_mode = 2  # velocity control {3}
    odrv.axis0.controller.config.input_mode = 1  # passthrough {1}
    odrv.axis0.controller.config.pos_gain = 10*20  # {20}
    odrv.axis0.controller.config.vel_integrator_gain = 10*0.3333  # {0.3333}

    odrv.axis0.controller.start_anticogging_calibration()

    t = time.time()
    i = odrv.axis0.encoder.pos_estimate_counts
    while odrv.axis0.controller.config.anticogging.calib_anticogging:
        dt = time.time() - t
        rem = 1 - abs(odrv.axis0.encoder.pos_estimate_counts - i) / 8192
        est = dt / rem
        print(f"Expected run time of {est:.1f} seconds (run time of {dt:.1f} seconds, {100 * rem:.1f}% complete", end="\r")
    print("                                           ", end="\r")

    odrv.axis0.controller.config.anticogging.pre_calibrated = True  # {False}
    odrv.axis1.controller.config.control_mode = 3  # position control {3}
    odrv.axis0.controller.config.input_mode = 5  # trapazoidal {1}
    odrv.axis0.controller.config.pos_gain = 20  # {20}
    odrv.axis0.controller.config.vel_integrator_gain = 0.3333  # {0.3333}

    # Save ODrive
    odrv = save_odrive(odrv)

    return odrv

def autocal_VSM(odrv, skip_full_cal=False):

    # Continue/cancel autodetection
    str_in = input(
        "Remove platform and center VSM prior to calibration\nPress ENTER to continue or X to cancel\n")

    if str_in in ["x", "X"]:
        print()
        return

    # look into anticogging
    # look into autotuning

    # Update parameters
    odrv.axis0.controller.config.input_mode = 5  # trapazoidal {1}
    odrv.axis0.controller.config.pos_gain = 20  # {20}
    odrv.axis0.controller.config.vel_gain = 0.1667  # {0.1667}
    odrv.axis0.controller.config.vel_integrator_gain = 0.3333  # {0.3333}
    odrv.axis0.controller.config.vel_limit = 114  # {2}
    odrv.axis0.encoder.config.pre_calibrated = False  # {False}
    odrv.axis0.encoder.config.use_index = True  # {False}
    odrv.axis0.motor.config.calibration_current = 20  # {10}
    odrv.axis0.motor.config.current_lim = 65  # {10}
    odrv.axis0.motor.config.current_lim_margin = 52  # {8}
    odrv.axis0.motor.config.pre_calibrated = False  # {False}
    odrv.axis0.motor.config.requested_current_range = 130  # {60}
    odrv.axis0.motor.config.torque_constant = 8.27/190  # {0.04}
    odrv.axis0.trap_traj.config.accel_limit = 114  # {0.5}
    odrv.axis0.trap_traj.config.decel_limit = 114  # {0.5}
    odrv.axis0.trap_traj.config.vel_limit = 114  # {2}

    # Save ODrive
    odrv = save_odrive(odrv)

    # Calibrate VSM motor
    print("Calibrating VSM")
    
    if skip_full_cal:
        # Hoverboard workaround: skip full calibration, use motor calibration only
        print("Using hoverboard hall sensor workaround (motor calibration only)")
        odrv.axis0.requested_state = 4  # motor calibration only (avoids hall sensor validation)
        countdown(10)
    else:
        odrv.axis0.requested_state = 3  # full calibration sequence
        countdown(20)
    print()

    # Error exit case
    if odrv.axis0.error:
        print("ERROR")
        sys.exit()

    # Update additional parameters
    odrv.axis0.config.startup_closed_loop_control = True  # {False}
    odrv.axis0.config.startup_encoder_index_search = True  # {False}
    odrv.axis0.encoder.config.pre_calibrated = True  # {False}
    odrv.axis0.motor.config.pre_calibrated = True  # {False}

    # Save ODrive
    odrv = save_odrive(odrv)

    str_in = input("Press ENTER to skip or Y to start VSM anticogging\n")
    if str_in in ["y", "Y"]:
        print()
        odrv = autoanticog(odrv, skip_full_cal)
        return

    return odrv

def autocal_belt(odrv, skip_full_cal=False):

    # Continue/cancel autodetection
    str_in = input(
        "Remove roller gear prior to calibration\nPress ENTER to continue or X to cancel\n")

    if str_in in ["x", "X"]:
        print()
        return

    # Update parameters
    odrv.axis1.controller.config.control_mode = 2  # velocity control {3}
    odrv.axis1.controller.config.input_mode = 2  # velocity ramp {3}
    odrv.axis1.controller.config.vel_gain = 0.1667  # {0.1667}
    odrv.axis1.controller.config.vel_integrator_gain = 0.3333  # {0.3333}
    odrv.axis1.controller.config.vel_limit = 114  # {2}
    odrv.axis1.controller.config.vel_ramp_rate = 5  # {1}
    odrv.axis1.encoder.config.pre_calibrated = False  # {False}
    odrv.axis1.encoder.config.use_index = True  # {False}
    odrv.axis1.motor.config.calibration_current = 20  # {10}
    odrv.axis1.motor.config.current_lim = 100  # {10}
    odrv.axis1.motor.config.current_lim_margin = 80  # {8}
    odrv.axis1.motor.config.pre_calibrated = False  # {False}
    odrv.axis1.motor.config.requested_current_range = 200  # {60}
    odrv.axis1.motor.config.torque_constant = 8.27/190  # {0.04}

    # Save ODrive
    odrv = save_odrive(odrv)

    # Calibrate velt motor
    print("Calibrating Belt motor")
    
    if skip_full_cal:
        # Hoverboard workaround: skip full calibration, use motor calibration only
        print("Using hoverboard hall sensor workaround (motor calibration only)")
        odrv.axis1.requested_state = 4  # motor calibration only (avoids hall sensor validation)
        countdown(10)
    else:
        odrv.axis1.requested_state = 3  # full calibration sequence
        countdown(20)
    print()

    # Error exit case
    if odrv.axis0.error:
        print("ERROR")
        sys.exit()

    # Update additional parameters
    odrv.axis1.config.startup_closed_loop_control = True  # {False}
    odrv.axis1.config.startup_encoder_index_search = True  # {False}
    odrv.axis1.encoder.config.pre_calibrated = True  # {False}
    odrv.axis1.motor.config.pre_calibrated = True  # {False}

    # Save ODrive
    odrv = save_odrive(odrv)

    return odrv

def autocal(odrv, use_hoverboard_workaround=False):

    # Find ODrive
    odrv.axis0.requested_state = 1
    odrv.axis1.requested_state = 1

    # Print Info
    print("Running Variable Stiffness Treadmill Autocalibrater v001")
    print(f"ODrive with hardware v{odrv.hw_version_major}.{odrv.hw_version_minor}-{odrv.hw_version_variant}V running firmware v{odrv.fw_version_major}.{odrv.fw_version_minor}.{odrv.fw_version_revision}.{odrv.fw_version_unreleased}")
    print(f"Pulling {odrv.ibus}A at {odrv.vbus_voltage}V\n")

    if use_hoverboard_workaround:
        print(">>> Using hoverboard hall sensor workaround (motor calibration only, skipping full calibration)\n")

    # Clear/erase ODrive
    str_in = input("Press ENTER to clear errors or E to erase configuration\n")

    if str_in in ["e", "E"]:
        print()
        print("Erasing ODrive")
        try:
            odrv.erase_configuration()
            countdown(5)
        except Exception:
            countdown(5)
        odrv = odrive.find_any()
        print()
    else:
        odrv.axis0.clear_errors()
        odrv.axis1.clear_errors()

    # Update parameters
    odrv.config.dc_max_positive_current = 20  # {inf}
    # odrv.config.enable_brake_resistor = False  # {False}  # Not available in this firmware version

    # Save ODrive
    odrv = save_odrive(odrv)

    # Autocalibrate VSM
    str_in = input(
        "Press ENTER to skip or Y to start VSM motor autocalibration\n")

    if str_in in ["y", "Y"]:
        print()
        odrv = autocal_VSM(odrv, use_hoverboard_workaround)

    # Autocalibrate belt
    str_in = input(
        "Press ENTER to skip or Y to start belt motor autocalibration\n")

    if str_in in ["y", "Y"]:
        print()
        odrv = autocal_belt(odrv, use_hoverboard_workaround)

    odrv.axis0.requested_state = 8
    odrv.axis1.requested_state = 8

def main():

    # Clear terminal
    os.system('clear' if os.name != 'nt' else 'cls')

    # Find ODrives
    odrv0 = odrive.find_any()

    # Check for hoverboard hall sensors early
    print("Detecting motor type...")
    use_hoverboard = input("Are you using hoverboard hall sensors? (Y/N, default N): ").lower() in ['y', 'yes']

    # Autocalibration sequence
    odrv0 = autocal(odrv0, use_hoverboard)

if __name__=='__main__':
    main()