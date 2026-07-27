# ODrive.Controller.Error — bitmask. Constants match the official enum values;
# use bitwise AND against `error` to test individual flags, e.g.:
#   (msg.error & msg.SPINOUT_DETECTED) != 0

# Actual error
uint32 error

# Error codes
uint32 OVERSPEED=1
uint32 INVALID_INPUT_MODE=2
uint32 UNSTABLE_GAIN=4
uint32 INVALID_MIRROR_AXIS=8
uint32 INVALID_LOAD_ENCODER=16
uint32 INVALID_ESTIMATE=32
uint32 INVALID_CIRCULAR_RANGE=64
uint32 SPINOUT_DETECTED=128
