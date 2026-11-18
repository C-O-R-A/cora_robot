# Resources

## Odrive

Odrive home:

Odrive api:
    https://docs.odriverobotics.com/v/0.5.6/fibre_types/com_odriverobotics_ODrive.html

Odrive Hoverboard Motor Setup:
    https://docs.odriverobotics.com/v/0.5.6/hoverboard.html#hoverboard-doc

Odrive homing:
    https://docs.odriverobotics.com/v/0.5.6/endstops.html

Odrive sensorless:
    https://docs.odriverobotics.com/v/0.5.6/commands.html#sensorless-setup

    ```python
        odrv0.axis0.config.startup_sensorless_control = True
        odrv0.axis0.controller.config.vel_gain = 0.1
        odrv0.axis0.controller.config.vel_integrator_gain=0.05

        odrv0.axis0.controller.config.control_mode = CONTROL_MODE_VELOCITY_CONTROL
        odrv0.axis0.controller.config.vel_limit = 20
        odrv0.axis0.motor.config.current_lim = 50
        odrv0.axis0.sensorless_estimator.config.pm_flux_linkage = 5.51328895422 / (7 * 270)
        odrv0.axis0.requested_state = AXIS_STATE_CLOSED_LOOP_CONTROL
        odrv0.axis0.config.sensorless_ramp.finish_on_vel=False
        odrv0.axis0.config.sensorless_ramp.finish_on_distance=True
        odrv0.axis0.config.sensorless_ramp.accel = 5
        odrv0.axis0.config.sensorless_ramp.vel = 10
    ```