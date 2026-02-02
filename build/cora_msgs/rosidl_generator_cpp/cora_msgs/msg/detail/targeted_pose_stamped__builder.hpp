// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cora_msgs:msg/TargetedPoseStamped.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "cora_msgs/msg/targeted_pose_stamped.hpp"


#ifndef CORA_MSGS__MSG__DETAIL__TARGETED_POSE_STAMPED__BUILDER_HPP_
#define CORA_MSGS__MSG__DETAIL__TARGETED_POSE_STAMPED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cora_msgs/msg/detail/targeted_pose_stamped__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cora_msgs
{

namespace msg
{

namespace builder
{

class Init_TargetedPoseStamped_pose
{
public:
  explicit Init_TargetedPoseStamped_pose(::cora_msgs::msg::TargetedPoseStamped & msg)
  : msg_(msg)
  {}
  ::cora_msgs::msg::TargetedPoseStamped pose(::cora_msgs::msg::TargetedPoseStamped::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cora_msgs::msg::TargetedPoseStamped msg_;
};

class Init_TargetedPoseStamped_target_frame
{
public:
  Init_TargetedPoseStamped_target_frame()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TargetedPoseStamped_pose target_frame(::cora_msgs::msg::TargetedPoseStamped::_target_frame_type arg)
  {
    msg_.target_frame = std::move(arg);
    return Init_TargetedPoseStamped_pose(msg_);
  }

private:
  ::cora_msgs::msg::TargetedPoseStamped msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cora_msgs::msg::TargetedPoseStamped>()
{
  return cora_msgs::msg::builder::Init_TargetedPoseStamped_target_frame();
}

}  // namespace cora_msgs

#endif  // CORA_MSGS__MSG__DETAIL__TARGETED_POSE_STAMPED__BUILDER_HPP_
