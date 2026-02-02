// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from cora_msgs:msg/TargetedPoseStamped.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "cora_msgs/msg/targeted_pose_stamped.h"


#ifndef CORA_MSGS__MSG__DETAIL__TARGETED_POSE_STAMPED__FUNCTIONS_H_
#define CORA_MSGS__MSG__DETAIL__TARGETED_POSE_STAMPED__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "cora_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "cora_msgs/msg/detail/targeted_pose_stamped__struct.h"

/// Initialize msg/TargetedPoseStamped message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * cora_msgs__msg__TargetedPoseStamped
 * )) before or use
 * cora_msgs__msg__TargetedPoseStamped__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_cora_msgs
bool
cora_msgs__msg__TargetedPoseStamped__init(cora_msgs__msg__TargetedPoseStamped * msg);

/// Finalize msg/TargetedPoseStamped message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cora_msgs
void
cora_msgs__msg__TargetedPoseStamped__fini(cora_msgs__msg__TargetedPoseStamped * msg);

/// Create msg/TargetedPoseStamped message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * cora_msgs__msg__TargetedPoseStamped__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cora_msgs
cora_msgs__msg__TargetedPoseStamped *
cora_msgs__msg__TargetedPoseStamped__create(void);

/// Destroy msg/TargetedPoseStamped message.
/**
 * It calls
 * cora_msgs__msg__TargetedPoseStamped__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cora_msgs
void
cora_msgs__msg__TargetedPoseStamped__destroy(cora_msgs__msg__TargetedPoseStamped * msg);

/// Check for msg/TargetedPoseStamped message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cora_msgs
bool
cora_msgs__msg__TargetedPoseStamped__are_equal(const cora_msgs__msg__TargetedPoseStamped * lhs, const cora_msgs__msg__TargetedPoseStamped * rhs);

/// Copy a msg/TargetedPoseStamped message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_cora_msgs
bool
cora_msgs__msg__TargetedPoseStamped__copy(
  const cora_msgs__msg__TargetedPoseStamped * input,
  cora_msgs__msg__TargetedPoseStamped * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_cora_msgs
const rosidl_type_hash_t *
cora_msgs__msg__TargetedPoseStamped__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_cora_msgs
const rosidl_runtime_c__type_description__TypeDescription *
cora_msgs__msg__TargetedPoseStamped__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_cora_msgs
const rosidl_runtime_c__type_description__TypeSource *
cora_msgs__msg__TargetedPoseStamped__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_cora_msgs
const rosidl_runtime_c__type_description__TypeSource__Sequence *
cora_msgs__msg__TargetedPoseStamped__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of msg/TargetedPoseStamped messages.
/**
 * It allocates the memory for the number of elements and calls
 * cora_msgs__msg__TargetedPoseStamped__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_cora_msgs
bool
cora_msgs__msg__TargetedPoseStamped__Sequence__init(cora_msgs__msg__TargetedPoseStamped__Sequence * array, size_t size);

/// Finalize array of msg/TargetedPoseStamped messages.
/**
 * It calls
 * cora_msgs__msg__TargetedPoseStamped__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cora_msgs
void
cora_msgs__msg__TargetedPoseStamped__Sequence__fini(cora_msgs__msg__TargetedPoseStamped__Sequence * array);

/// Create array of msg/TargetedPoseStamped messages.
/**
 * It allocates the memory for the array and calls
 * cora_msgs__msg__TargetedPoseStamped__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cora_msgs
cora_msgs__msg__TargetedPoseStamped__Sequence *
cora_msgs__msg__TargetedPoseStamped__Sequence__create(size_t size);

/// Destroy array of msg/TargetedPoseStamped messages.
/**
 * It calls
 * cora_msgs__msg__TargetedPoseStamped__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cora_msgs
void
cora_msgs__msg__TargetedPoseStamped__Sequence__destroy(cora_msgs__msg__TargetedPoseStamped__Sequence * array);

/// Check for msg/TargetedPoseStamped message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cora_msgs
bool
cora_msgs__msg__TargetedPoseStamped__Sequence__are_equal(const cora_msgs__msg__TargetedPoseStamped__Sequence * lhs, const cora_msgs__msg__TargetedPoseStamped__Sequence * rhs);

/// Copy an array of msg/TargetedPoseStamped messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_cora_msgs
bool
cora_msgs__msg__TargetedPoseStamped__Sequence__copy(
  const cora_msgs__msg__TargetedPoseStamped__Sequence * input,
  cora_msgs__msg__TargetedPoseStamped__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // CORA_MSGS__MSG__DETAIL__TARGETED_POSE_STAMPED__FUNCTIONS_H_
