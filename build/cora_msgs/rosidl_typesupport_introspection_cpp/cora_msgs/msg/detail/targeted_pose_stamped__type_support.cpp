// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from cora_msgs:msg/TargetedPoseStamped.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "cora_msgs/msg/detail/targeted_pose_stamped__functions.h"
#include "cora_msgs/msg/detail/targeted_pose_stamped__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace cora_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void TargetedPoseStamped_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) cora_msgs::msg::TargetedPoseStamped(_init);
}

void TargetedPoseStamped_fini_function(void * message_memory)
{
  auto typed_message = static_cast<cora_msgs::msg::TargetedPoseStamped *>(message_memory);
  typed_message->~TargetedPoseStamped();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember TargetedPoseStamped_message_member_array[2] = {
  {
    "target_frame",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cora_msgs::msg::TargetedPoseStamped, target_frame),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "pose",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::PoseStamped>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cora_msgs::msg::TargetedPoseStamped, pose),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers TargetedPoseStamped_message_members = {
  "cora_msgs::msg",  // message namespace
  "TargetedPoseStamped",  // message name
  2,  // number of fields
  sizeof(cora_msgs::msg::TargetedPoseStamped),
  false,  // has_any_key_member_
  TargetedPoseStamped_message_member_array,  // message members
  TargetedPoseStamped_init_function,  // function to initialize message memory (memory has to be allocated)
  TargetedPoseStamped_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t TargetedPoseStamped_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &TargetedPoseStamped_message_members,
  get_message_typesupport_handle_function,
  &cora_msgs__msg__TargetedPoseStamped__get_type_hash,
  &cora_msgs__msg__TargetedPoseStamped__get_type_description,
  &cora_msgs__msg__TargetedPoseStamped__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace cora_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<cora_msgs::msg::TargetedPoseStamped>()
{
  return &::cora_msgs::msg::rosidl_typesupport_introspection_cpp::TargetedPoseStamped_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, cora_msgs, msg, TargetedPoseStamped)() {
  return &::cora_msgs::msg::rosidl_typesupport_introspection_cpp::TargetedPoseStamped_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
