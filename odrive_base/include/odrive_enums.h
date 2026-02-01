
#ifndef ODriveEnums_h
#define ODriveEnums_h

// ODrive.GpioMode
enum ODriveGpioMode {
    GPIO_MODE_DIGITAL                        = 0,
    GPIO_MODE_DIGITAL_PULL_UP                = 1,
    GPIO_MODE_DIGITAL_PULL_DOWN              = 2,
    GPIO_MODE_ANALOG_IN                      = 3,
    GPIO_MODE_UART_A                         = 4,
    GPIO_MODE_UART_B                         = 5,
    GPIO_MODE_UART_C                         = 6,
    GPIO_MODE_CAN_A                          = 7,
    GPIO_MODE_I2C_A                          = 8,
    GPIO_MODE_SPI_A                          = 9,
    GPIO_MODE_PWM                            = 10,
    GPIO_MODE_ENC0                           = 11,
    GPIO_MODE_ENC1                           = 12,
    GPIO_MODE_ENC2                           = 13,
    GPIO_MODE_MECH_BRAKE                     = 14,
    GPIO_MODE_STATUS                         = 15,
};

// ODrive.StreamProtocolType
enum ODriveStreamProtocolType {
    STREAM_PROTOCOL_TYPE_FIBRE               = 0,
    STREAM_PROTOCOL_TYPE_ASCII               = 1,
    STREAM_PROTOCOL_TYPE_STDOUT              = 2,
    STREAM_PROTOCOL_TYPE_ASCII_AND_STDOUT    = 3,
};

// ODrive.Can.Protocol
enum ODriveProtocol {
    PROTOCOL_NONE                            = 0x00000000,
    PROTOCOL_SIMPLE                          = 0x00000001,
};

// ODrive.Axis.AxisState
enum ODriveAxisState {
    AXIS_STATE_UNDEFINED                     = 0,
    AXIS_STATE_IDLE                          = 1,
    AXIS_STATE_STARTUP_SEQUENCE              = 2,
    AXIS_STATE_FULL_CALIBRATION_SEQUENCE     = 3,
    AXIS_STATE_MOTOR_CALIBRATION             = 4,
    AXIS_STATE_ENCODER_INDEX_SEARCH          = 6,
    AXIS_STATE_ENCODER_OFFSET_CALIBRATION    = 7,
    AXIS_STATE_CLOSED_LOOP_CONTROL           = 8,
    AXIS_STATE_LOCKIN_SPIN                   = 9,
    AXIS_STATE_ENCODER_DIR_FIND              = 10,
    AXIS_STATE_HOMING                        = 11,
    AXIS_STATE_ENCODER_HALL_POLARITY_CALIBRATION = 12,
    AXIS_STATE_ENCODER_HALL_PHASE_CALIBRATION = 13,
};

// ODrive.Controller.ControlMode
enum ODriveControlMode {
    CONTROL_MODE_VOLTAGE_CONTROL             = 0,
    CONTROL_MODE_TORQUE_CONTROL              = 1,
    CONTROL_MODE_VELOCITY_CONTROL            = 2,
    CONTROL_MODE_POSITION_CONTROL            = 3,
};

// ODrive.Error
enum ODriveError {
    ODRIVE_ERROR_NONE                        = 0x00000000,
    ODRIVE_ERROR_CONTROL_ITERATION_MISSED    = 0x00000001,
    ODRIVE_ERROR_DC_BUS_UNDER_VOLTAGE        = 0x00000002,
    ODRIVE_ERROR_DC_BUS_OVER_VOLTAGE         = 0x00000004,
    ODRIVE_ERROR_DC_BUS_OVER_REGEN_CURRENT   = 0x00000008,
    ODRIVE_ERROR_DC_BUS_OVER_CURRENT         = 0x00000010,
    ODRIVE_ERROR_BRAKE_DEADTIME_VIOLATION    = 0x00000020,
    ODRIVE_ERROR_BRAKE_DUTY_CYCLE_NAN        = 0x00000040,
    ODRIVE_ERROR_INVALID_BRAKE_RESISTANCE    = 0x00000080,
};

// ODrive.Encoder.Mode
enum ODriveSpiEncoderMode {
    ENCODER_MODE_INCREMENTAL                 = 0,
    ENCODER_MODE_HALL                        = 1,
    ENCODER_MODE_SINCOS                      = 2,
    ENCODER_MODE_SPI_ABS_CUI                 = 256,
    ENCODER_MODE_SPI_ABS_AMS                 = 257,
    ENCODER_MODE_SPI_ABS_AEAT                = 258,
    ENCODER_MODE_SPI_ABS_RLS                 = 259,
    ENCODER_MODE_SPI_ABS_MA732               = 260,
};

// ODrive.Controller.InputMode
enum ODriveInputMode {
    INPUT_MODE_INACTIVE                      = 0,
    INPUT_MODE_PASSTHROUGH                   = 1,
    INPUT_MODE_VEL_RAMP                      = 2,
    INPUT_MODE_POS_FILTER                    = 3,
    INPUT_MODE_MIX_CHANNELS                  = 4,
    INPUT_MODE_TRAP_TRAJ                     = 5,
    INPUT_MODE_TORQUE_RAMP                   = 6,
    INPUT_MODE_MIRROR                        = 7,
    INPUT_MODE_TUNING                        = 8,
};

// ODrive.Motor.MotorType
enum ODriveMotorType {
    MOTOR_TYPE_HIGH_CURRENT                  = 0,
    MOTOR_TYPE_GIMBAL                        = 2,
    MOTOR_TYPE_ACIM                          = 3,
};

// ODrive.Can.Error
enum ODriveCanError {
    CAN_ERROR_DUPLICATE_CAN_IDS              = 0x00000001,
};

#endif