# Command Notes

## ROS commands

Publish a joint trajectory:

```bash
ros2 topic pub --once /joint_trajectory_controller/joint_trajectory \
  trajectory_msgs/msg/JointTrajectory \
  "{
    joint_names: ['J1', 'J2', 'J3'],
    points: [
      {
        positions: [0.0, 0.0, 0.0],
        time_from_start: {sec: 0, nanosec: 0}
      },
      {
        positions: [0.5, 0.5, 0.5],
        time_from_start: {sec: 20, nanosec: 0}
      },
      {
        positions: [0.0, 0.0, 0.0],
        time_from_start: {sec: 40, nanosec: 0}
      }
    ]
  }"
```

Launch the joint trajectory controller GUI:

```bash
ros2 run rqt_joint_trajectory_controller rqt_joint_trajectory_controller
```

## odrivecli commands

Restore or back up an ODrive configuration:

```bash
odrivetool restore-config closed_loop_6354.json
odrivetool backup-config my_odrive_backup.json
```

In the ODrive CLI, inspect and clear errors, save configuration, or reboot:

```python
dump_errors(odrv0)
odrv0.axis0.clear_errors()
odrv0.save_configuration()
odrv0.reboot()
```

Set the axis control mode (`1` = torque, `2` = velocity, `3` = position) and requested state (`1` = idle, `8` = closed-loop control):

```python
odrv0.axis0.controller.config.control_mode = ...
odrv0.axis0.requested_state = ...
```

Plot live ODrive properties:

```python
start_liveplotter(properties=[
    odrv0.axis0.encoder._vel_estimate_property,
    odrv0.axis0.motor.current_control._Ibus_property,
    odrv0.axis0.motor.current_control._Iq_measured_property
])
```

```python
start_liveplotter(properties=[
    odrv0.axis0.encoder._pos_estimate_property,
    odrv0.axis0.motor.current_control._Ibus_property,
    odrv0.axis0.motor.current_control._Iq_measured_property
])
```

```python
start_liveplotter(properties=[
    odrv0.axis0.motor.current_control._Ibus_property,
    odrv0.axis0.motor.current_control._Iq_measured_property
])
```
