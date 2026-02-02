// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cora_msgs:msg/TargetedPoseStamped.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "cora_msgs/msg/targeted_pose_stamped.hpp"


#ifndef CORA_MSGS__MSG__DETAIL__TARGETED_POSE_STAMPED__STRUCT_HPP_
#define CORA_MSGS__MSG__DETAIL__TARGETED_POSE_STAMPED__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose_stamped__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__cora_msgs__msg__TargetedPoseStamped __attribute__((deprecated))
#else
# define DEPRECATED__cora_msgs__msg__TargetedPoseStamped __declspec(deprecated)
#endif

namespace cora_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TargetedPoseStamped_
{
  using Type = TargetedPoseStamped_<ContainerAllocator>;

  explicit TargetedPoseStamped_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->target_frame = "";
    }
  }

  explicit TargetedPoseStamped_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : target_frame(_alloc),
    pose(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->target_frame = "";
    }
  }

  // field types and members
  using _target_frame_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _target_frame_type target_frame;
  using _pose_type =
    geometry_msgs::msg::PoseStamped_<ContainerAllocator>;
  _pose_type pose;

  // setters for named parameter idiom
  Type & set__target_frame(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->target_frame = _arg;
    return *this;
  }
  Type & set__pose(
    const geometry_msgs::msg::PoseStamped_<ContainerAllocator> & _arg)
  {
    this->pose = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cora_msgs::msg::TargetedPoseStamped_<ContainerAllocator> *;
  using ConstRawPtr =
    const cora_msgs::msg::TargetedPoseStamped_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cora_msgs::msg::TargetedPoseStamped_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cora_msgs::msg::TargetedPoseStamped_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cora_msgs::msg::TargetedPoseStamped_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cora_msgs::msg::TargetedPoseStamped_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cora_msgs::msg::TargetedPoseStamped_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cora_msgs::msg::TargetedPoseStamped_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cora_msgs::msg::TargetedPoseStamped_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cora_msgs::msg::TargetedPoseStamped_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cora_msgs__msg__TargetedPoseStamped
    std::shared_ptr<cora_msgs::msg::TargetedPoseStamped_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cora_msgs__msg__TargetedPoseStamped
    std::shared_ptr<cora_msgs::msg::TargetedPoseStamped_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TargetedPoseStamped_ & other) const
  {
    if (this->target_frame != other.target_frame) {
      return false;
    }
    if (this->pose != other.pose) {
      return false;
    }
    return true;
  }
  bool operator!=(const TargetedPoseStamped_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TargetedPoseStamped_

// alias to use template instance with default allocator
using TargetedPoseStamped =
  cora_msgs::msg::TargetedPoseStamped_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace cora_msgs

#endif  // CORA_MSGS__MSG__DETAIL__TARGETED_POSE_STAMPED__STRUCT_HPP_
