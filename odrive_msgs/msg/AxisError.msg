# ODrive Axis Error codes
# Reference: https://docs.odriverobotics.com/v/0.5.6/fibre_types/com_odriverobotics_ODrive.html#ODrive.Axis.Error

# Actual error
uint32 error

# Error codes
uint32 INVALID_STATE = 1
uint32 MOTOR_FAILED = 64
uint32 SENSORLESS_ESTIMATOR_FAILED = 128
uint32 ENCODER_FAILED = 256
uint32 CONTROLLER_FAILED = 512
uint32 WATCHDOG_TIMER_EXPIRED = 2048
uint32 MIN_ENDSTOP_PRESSED = 4096
uint32 MAX_ENDSTOP_PRESSED = 8192
uint32 ESTOP_REQUESTED = 16384
uint32 HOMING_WITHOUT_ENDSTOP = 131072
uint32 OVER_TEMP = 262144
uint32 UNKNOWN_POSITION = 524288

