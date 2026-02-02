// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cora_msgs:msg/TargetedPoseStamped.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "cora_msgs/msg/targeted_pose_stamped.hpp"


#ifndef CORA_MSGS__MSG__DETAIL__TARGETED_POSE_STAMPED__TRAITS_HPP_
#define CORA_MSGS__MSG__DETAIL__TARGETED_POSE_STAMPED__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cora_msgs/msg/detail/targeted_pose_stamped__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose_stamped__traits.hpp"

namespace cora_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const TargetedPoseStamped & msg,
  std::ostream & out)
{
  out << "{";
  // member: target_frame
  {
    out << "target_frame: ";
    rosidl_generator_traits::value_to_yaml(msg.target_frame, out);
    out << ", ";
  }

  // member: pose
  {
    out << "pose: ";
    to_flow_style_yaml(msg.pose, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TargetedPoseStamped & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: target_frame
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_frame: ";
    rosidl_generator_traits::value_to_yaml(msg.target_frame, out);
    out << "\n";
  }

  // member: pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose:\n";
    to_block_style_yaml(msg.pose, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TargetedPoseStamped & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace cora_msgs

namespace rosidl_generator_traits
{

[[deprecated("use cora_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cora_msgs::msg::TargetedPoseStamped & msg,
  std::ostream & out, size_t indentation = 0)
{
  cora_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cora_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const cora_msgs::msg::TargetedPoseStamped & msg)
{
  return cora_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<cora_msgs::msg::TargetedPoseStamped>()
{
  return "cora_msgs::msg::TargetedPoseStamped";
}

template<>
inline const char * name<cora_msgs::msg::TargetedPoseStamped>()
{
  return "cora_msgs/msg/TargetedPoseStamped";
}

template<>
struct has_fixed_size<cora_msgs::msg::TargetedPoseStamped>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cora_msgs::msg::TargetedPoseStamped>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<cora_msgs::msg::TargetedPoseStamped>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CORA_MSGS__MSG__DETAIL__TARGETED_POSE_STAMPED__TRAITS_HPP_
