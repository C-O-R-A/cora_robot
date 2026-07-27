# ODrive.Encoder.Error — bitmask. Constants match the official enum values;
# use bitwise AND against `error` to test individual flags, e.g.:
#   (msg.error & msg.ILLEGAL_HALL_STATE) != 0

# Actual error
uint32 error

# Error codes
uint32 UNSTABLE_GAIN=1
uint32 CPR_POLEPAIRS_MISMATCH=2
uint32 NO_RESPONSE=4
uint32 UNSUPPORTED_ENCODER_MODE=8
uint32 ILLEGAL_HALL_STATE=16
uint32 INDEX_NOT_FOUND_YET=32
uint32 ABS_SPI_TIMEOUT=64
uint32 ABS_SPI_COM_FAIL=128
uint32 ABS_SPI_NOT_READY=256
uint32 HALL_NOT_CALIBRATED_YET=512
