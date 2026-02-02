// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cora_msgs:msg/TargetedPoseStamped.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "cora_msgs/msg/targeted_pose_stamped.h"


#ifndef CORA_MSGS__MSG__DETAIL__TARGETED_POSE_STAMPED__STRUCT_H_
#define CORA_MSGS__MSG__DETAIL__TARGETED_POSE_STAMPED__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'target_frame'
#include "rosidl_runtime_c/string.h"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose_stamped__struct.h"

/// Struct defined in msg/TargetedPoseStamped in the package cora_msgs.
typedef struct cora_msgs__msg__TargetedPoseStamped
{
  /// name of Dummy link to select as frame.
  /// 'Gripper' or 'Camera' or 'endeffector'
  rosidl_runtime_c__String target_frame;
  geometry_msgs__msg__PoseStamped pose;
} cora_msgs__msg__TargetedPoseStamped;

// Struct for a sequence of cora_msgs__msg__TargetedPoseStamped.
typedef struct cora_msgs__msg__TargetedPoseStamped__Sequence
{
  cora_msgs__msg__TargetedPoseStamped * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cora_msgs__msg__TargetedPoseStamped__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CORA_MSGS__MSG__DETAIL__TARGETED_POSE_STAMPED__STRUCT_H_
