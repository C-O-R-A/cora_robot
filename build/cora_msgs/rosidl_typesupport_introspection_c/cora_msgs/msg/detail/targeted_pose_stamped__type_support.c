// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from cora_msgs:msg/TargetedPoseStamped.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "cora_msgs/msg/detail/targeted_pose_stamped__rosidl_typesupport_introspection_c.h"
#include "cora_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "cora_msgs/msg/detail/targeted_pose_stamped__functions.h"
#include "cora_msgs/msg/detail/targeted_pose_stamped__struct.h"


// Include directives for member types
// Member `target_frame`
#include "rosidl_runtime_c/string_functions.h"
// Member `pose`
#include "geometry_msgs/msg/pose_stamped.h"
// Member `pose`
#include "geometry_msgs/msg/detail/pose_stamped__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void cora_msgs__msg__TargetedPoseStamped__rosidl_typesupport_introspection_c__TargetedPoseStamped_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  cora_msgs__msg__TargetedPoseStamped__init(message_memory);
}

void cora_msgs__msg__TargetedPoseStamped__rosidl_typesupport_introspection_c__TargetedPoseStamped_fini_function(void * message_memory)
{
  cora_msgs__msg__TargetedPoseStamped__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember cora_msgs__msg__TargetedPoseStamped__rosidl_typesupport_introspection_c__TargetedPoseStamped_message_member_array[2] = {
  {
    "target_frame",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cora_msgs__msg__TargetedPoseStamped, target_frame),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cora_msgs__msg__TargetedPoseStamped, pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers cora_msgs__msg__TargetedPoseStamped__rosidl_typesupport_introspection_c__TargetedPoseStamped_message_members = {
  "cora_msgs__msg",  // message namespace
  "TargetedPoseStamped",  // message name
  2,  // number of fields
  sizeof(cora_msgs__msg__TargetedPoseStamped),
  false,  // has_any_key_member_
  cora_msgs__msg__TargetedPoseStamped__rosidl_typesupport_introspection_c__TargetedPoseStamped_message_member_array,  // message members
  cora_msgs__msg__TargetedPoseStamped__rosidl_typesupport_introspection_c__TargetedPoseStamped_init_function,  // function to initialize message memory (memory has to be allocated)
  cora_msgs__msg__TargetedPoseStamped__rosidl_typesupport_introspection_c__TargetedPoseStamped_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t cora_msgs__msg__TargetedPoseStamped__rosidl_typesupport_introspection_c__TargetedPoseStamped_message_type_support_handle = {
  0,
  &cora_msgs__msg__TargetedPoseStamped__rosidl_typesupport_introspection_c__TargetedPoseStamped_message_members,
  get_message_typesupport_handle_function,
  &cora_msgs__msg__TargetedPoseStamped__get_type_hash,
  &cora_msgs__msg__TargetedPoseStamped__get_type_description,
  &cora_msgs__msg__TargetedPoseStamped__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_cora_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cora_msgs, msg, TargetedPoseStamped)() {
  cora_msgs__msg__TargetedPoseStamped__rosidl_typesupport_introspection_c__TargetedPoseStamped_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, PoseStamped)();
  if (!cora_msgs__msg__TargetedPoseStamped__rosidl_typesupport_introspection_c__TargetedPoseStamped_message_type_support_handle.typesupport_identifier) {
    cora_msgs__msg__TargetedPoseStamped__rosidl_typesupport_introspection_c__TargetedPoseStamped_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &cora_msgs__msg__TargetedPoseStamped__rosidl_typesupport_introspection_c__TargetedPoseStamped_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
