# Cora Robot packages

![Status](https://img.shields.io/badge/status-in%20progress-yellow)

ROS 2 Packages for the real cora robot.

## Odrive v3.6 setup

1. install odrivetool

    ```bash
    sudo pip install odrivetool
    ```

2. Load user config (6354 or 5065)

    ```bash
    odrivetool restore-config closed_loop_6354.json
    ```

3. Start odrivetool

    ```bash
    odrivetool
    ```

    ```bash
    ODrive control utility v0.6.10.post0
    Website: https://odriverobotics.com/
    Docs: https://docs.odriverobotics.com/
    Forums: https://discourse.odriverobotics.com/
    Discord: https://discord.gg/k3ZZ3mS
    GUI: https://gui.odriverobotics.com/

    Please connect your ODrive.
    You can also type help() or quit().
    Tip: `?` alone on a line will brings up IPython's help

    Connected to ODrive v3.6-24V 336436543334 (firmware v0.0.0) as odrv0
    ```

4. Save config and reboot

    ```python
    odrv0.save_configuration()
    odrv0.reboot()
    ```

5. Initiate full calibration

    ```python
    odrv0.axis0.requested_state = AXIS_STATE_FULL_CALIBRATION_SEQUENCE
    odrv0.axis0.requested_state = AXIS_STATE_IDLE
    ```

6. Set encoder and motor precalibration to true

    ```python
    odrv0.axis0.motor.config.pre_calibrated = True
    odrv0.axis0.encoder.config.pre_calibrated = True
    ```

7. Save config and reboot

    ```python
    odrv0.save_configuration()
    odrv0.reboot()
    ```

8. Run further setup using python script