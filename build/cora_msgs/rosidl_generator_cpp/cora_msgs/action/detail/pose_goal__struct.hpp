// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cora_msgs:action/PoseGoal.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "cora_msgs/action/pose_goal.hpp"


#ifndef CORA_MSGS__ACTION__DETAIL__POSE_GOAL__STRUCT_HPP_
#define CORA_MSGS__ACTION__DETAIL__POSE_GOAL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'pose_goal'
#include "cora_msgs/msg/detail/targeted_pose_stamped__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__cora_msgs__action__PoseGoal_Goal __attribute__((deprecated))
#else
# define DEPRECATED__cora_msgs__action__PoseGoal_Goal __declspec(deprecated)
#endif

namespace cora_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PoseGoal_Goal_
{
  using Type = PoseGoal_Goal_<ContainerAllocator>;

  explicit PoseGoal_Goal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose_goal(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->predefined_pose = "";
      this->space = "";
      this->interface_type = "";
    }
  }

  explicit PoseGoal_Goal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose_goal(_alloc, _init),
    predefined_pose(_alloc),
    space(_alloc),
    interface_type(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->predefined_pose = "";
      this->space = "";
      this->interface_type = "";
    }
  }

  // field types and members
  using _pose_goal_type =
    cora_msgs::msg::TargetedPoseStamped_<ContainerAllocator>;
  _pose_goal_type pose_goal;
  using _joint_goal_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _joint_goal_type joint_goal;
  using _predefined_pose_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _predefined_pose_type predefined_pose;
  using _space_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _space_type space;
  using _interface_type_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _interface_type_type interface_type;

  // setters for named parameter idiom
  Type & set__pose_goal(
    const cora_msgs::msg::TargetedPoseStamped_<ContainerAllocator> & _arg)
  {
    this->pose_goal = _arg;
    return *this;
  }
  Type & set__joint_goal(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->joint_goal = _arg;
    return *this;
  }
  Type & set__predefined_pose(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->predefined_pose = _arg;
    return *this;
  }
  Type & set__space(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->space = _arg;
    return *this;
  }
  Type & set__interface_type(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->interface_type = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cora_msgs::action::PoseGoal_Goal_<ContainerAllocator> *;
  using ConstRawPtr =
    const cora_msgs::action::PoseGoal_Goal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cora_msgs::action::PoseGoal_Goal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cora_msgs::action::PoseGoal_Goal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cora_msgs::action::PoseGoal_Goal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cora_msgs::action::PoseGoal_Goal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cora_msgs::action::PoseGoal_Goal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cora_msgs::action::PoseGoal_Goal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cora_msgs::action::PoseGoal_Goal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cora_msgs::action::PoseGoal_Goal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cora_msgs__action__PoseGoal_Goal
    std::shared_ptr<cora_msgs::action::PoseGoal_Goal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cora_msgs__action__PoseGoal_Goal
    std::shared_ptr<cora_msgs::action::PoseGoal_Goal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PoseGoal_Goal_ & other) const
  {
    if (this->pose_goal != other.pose_goal) {
      return false;
    }
    if (this->joint_goal != other.joint_goal) {
      return false;
    }
    if (this->predefined_pose != other.predefined_pose) {
      return false;
    }
    if (this->space != other.space) {
      return false;
    }
    if (this->interface_type != other.interface_type) {
      return false;
    }
    return true;
  }
  bool operator!=(const PoseGoal_Goal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PoseGoal_Goal_

// alias to use template instance with default allocator
using PoseGoal_Goal =
  cora_msgs::action::PoseGoal_Goal_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace cora_msgs


// Include directives for member types
// Member 'pose_result'
#include "geometry_msgs/msg/detail/pose_stamped__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__cora_msgs__action__PoseGoal_Result __attribute__((deprecated))
#else
# define DEPRECATED__cora_msgs__action__PoseGoal_Result __declspec(deprecated)
#endif

namespace cora_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PoseGoal_Result_
{
  using Type = PoseGoal_Result_<ContainerAllocator>;

  explicit PoseGoal_Result_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose_result(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status_result = "";
      this->success = false;
    }
  }

  explicit PoseGoal_Result_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose_result(_alloc, _init),
    status_result(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status_result = "";
      this->success = false;
    }
  }

  // field types and members
  using _pose_result_type =
    geometry_msgs::msg::PoseStamped_<ContainerAllocator>;
  _pose_result_type pose_result;
  using _joint_result_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _joint_result_type joint_result;
  using _status_result_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _status_result_type status_result;
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__pose_result(
    const geometry_msgs::msg::PoseStamped_<ContainerAllocator> & _arg)
  {
    this->pose_result = _arg;
    return *this;
  }
  Type & set__joint_result(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->joint_result = _arg;
    return *this;
  }
  Type & set__status_result(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->status_result = _arg;
    return *this;
  }
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cora_msgs::action::PoseGoal_Result_<ContainerAllocator> *;
  using ConstRawPtr =
    const cora_msgs::action::PoseGoal_Result_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cora_msgs::action::PoseGoal_Result_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cora_msgs::action::PoseGoal_Result_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cora_msgs::action::PoseGoal_Result_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cora_msgs::action::PoseGoal_Result_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cora_msgs::action::PoseGoal_Result_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cora_msgs::action::PoseGoal_Result_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cora_msgs::action::PoseGoal_Result_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cora_msgs::action::PoseGoal_Result_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cora_msgs__action__PoseGoal_Result
    std::shared_ptr<cora_msgs::action::PoseGoal_Result_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cora_msgs__action__PoseGoal_Result
    std::shared_ptr<cora_msgs::action::PoseGoal_Result_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PoseGoal_Result_ & other) const
  {
    if (this->pose_result != other.pose_result) {
      return false;
    }
    if (this->joint_result != other.joint_result) {
      return false;
    }
    if (this->status_result != other.status_result) {
      return false;
    }
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const PoseGoal_Result_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PoseGoal_Result_

// alias to use template instance with default allocator
using PoseGoal_Result =
  cora_msgs::action::PoseGoal_Result_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace cora_msgs


// Include directives for member types
// Member 'pose_feedback'
// already included above
// #include "geometry_msgs/msg/detail/pose_stamped__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__cora_msgs__action__PoseGoal_Feedback __attribute__((deprecated))
#else
# define DEPRECATED__cora_msgs__action__PoseGoal_Feedback __declspec(deprecated)
#endif

namespace cora_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PoseGoal_Feedback_
{
  using Type = PoseGoal_Feedback_<ContainerAllocator>;

  explicit PoseGoal_Feedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose_feedback(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = "";
    }
  }

  explicit PoseGoal_Feedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose_feedback(_alloc, _init),
    status(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = "";
    }
  }

  // field types and members
  using _pose_feedback_type =
    geometry_msgs::msg::PoseStamped_<ContainerAllocator>;
  _pose_feedback_type pose_feedback;
  using _status_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _status_type status;

  // setters for named parameter idiom
  Type & set__pose_feedback(
    const geometry_msgs::msg::PoseStamped_<ContainerAllocator> & _arg)
  {
    this->pose_feedback = _arg;
    return *this;
  }
  Type & set__status(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->status = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cora_msgs::action::PoseGoal_Feedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const cora_msgs::action::PoseGoal_Feedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cora_msgs::action::PoseGoal_Feedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cora_msgs::action::PoseGoal_Feedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cora_msgs::action::PoseGoal_Feedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cora_msgs::action::PoseGoal_Feedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cora_msgs::action::PoseGoal_Feedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cora_msgs::action::PoseGoal_Feedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cora_msgs::action::PoseGoal_Feedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cora_msgs::action::PoseGoal_Feedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cora_msgs__action__PoseGoal_Feedback
    std::shared_ptr<cora_msgs::action::PoseGoal_Feedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cora_msgs__action__PoseGoal_Feedback
    std::shared_ptr<cora_msgs::action::PoseGoal_Feedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PoseGoal_Feedback_ & other) const
  {
    if (this->pose_feedback != other.pose_feedback) {
      return false;
    }
    if (this->status != other.status) {
      return false;
    }
    return true;
  }
  bool operator!=(const PoseGoal_Feedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PoseGoal_Feedback_

// alias to use template instance with default allocator
using PoseGoal_Feedback =
  cora_msgs::action::PoseGoal_Feedback_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace cora_msgs


// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'goal'
#include "cora_msgs/action/detail/pose_goal__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__cora_msgs__action__PoseGoal_SendGoal_Request __attribute__((deprecated))
#else
# define DEPRECATED__cora_msgs__action__PoseGoal_SendGoal_Request __declspec(deprecated)
#endif

namespace cora_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PoseGoal_SendGoal_Request_
{
  using Type = PoseGoal_SendGoal_Request_<ContainerAllocator>;

  explicit PoseGoal_SendGoal_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    goal(_init)
  {
    (void)_init;
  }

  explicit PoseGoal_SendGoal_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    goal(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _goal_type =
    cora_msgs::action::PoseGoal_Goal_<ContainerAllocator>;
  _goal_type goal;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__goal(
    const cora_msgs::action::PoseGoal_Goal_<ContainerAllocator> & _arg)
  {
    this->goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cora_msgs::action::PoseGoal_SendGoal_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const cora_msgs::action::PoseGoal_SendGoal_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cora_msgs::action::PoseGoal_SendGoal_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cora_msgs::action::PoseGoal_SendGoal_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cora_msgs::action::PoseGoal_SendGoal_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cora_msgs::action::PoseGoal_SendGoal_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cora_msgs::action::PoseGoal_SendGoal_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cora_msgs::action::PoseGoal_SendGoal_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cora_msgs::action::PoseGoal_SendGoal_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cora_msgs::action::PoseGoal_SendGoal_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cora_msgs__action__PoseGoal_SendGoal_Request
    std::shared_ptr<cora_msgs::action::PoseGoal_SendGoal_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cora_msgs__action__PoseGoal_SendGoal_Request
    std::shared_ptr<cora_msgs::action::PoseGoal_SendGoal_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PoseGoal_SendGoal_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->goal != other.goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const PoseGoal_SendGoal_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PoseGoal_SendGoal_Request_

// alias to use template instance with default allocator
using PoseGoal_SendGoal_Request =
  cora_msgs::action::PoseGoal_SendGoal_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace cora_msgs


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__cora_msgs__action__PoseGoal_SendGoal_Response __attribute__((deprecated))
#else
# define DEPRECATED__cora_msgs__action__PoseGoal_SendGoal_Response __declspec(deprecated)
#endif

namespace cora_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PoseGoal_SendGoal_Response_
{
  using Type = PoseGoal_SendGoal_Response_<ContainerAllocator>;

  explicit PoseGoal_SendGoal_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit PoseGoal_SendGoal_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  // field types and members
  using _accepted_type =
    bool;
  _accepted_type accepted;
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;

  // setters for named parameter idiom
  Type & set__accepted(
    const bool & _arg)
  {
    this->accepted = _arg;
    return *this;
  }
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cora_msgs::action::PoseGoal_SendGoal_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const cora_msgs::action::PoseGoal_SendGoal_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cora_msgs::action::PoseGoal_SendGoal_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cora_msgs::action::PoseGoal_SendGoal_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cora_msgs::action::PoseGoal_SendGoal_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cora_msgs::action::PoseGoal_SendGoal_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cora_msgs::action::PoseGoal_SendGoal_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cora_msgs::action::PoseGoal_SendGoal_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cora_msgs::action::PoseGoal_SendGoal_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cora_msgs::action::PoseGoal_SendGoal_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cora_msgs__action__PoseGoal_SendGoal_Response
    std::shared_ptr<cora_msgs::action::PoseGoal_SendGoal_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cora_msgs__action__PoseGoal_SendGoal_Response
    std::shared_ptr<cora_msgs::action::PoseGoal_SendGoal_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PoseGoal_SendGoal_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const PoseGoal_SendGoal_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PoseGoal_SendGoal_Response_

// alias to use template instance with default allocator
using PoseGoal_SendGoal_Response =
  cora_msgs::action::PoseGoal_SendGoal_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace cora_msgs


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__cora_msgs__action__PoseGoal_SendGoal_Event __attribute__((deprecated))
#else
# define DEPRECATED__cora_msgs__action__PoseGoal_SendGoal_Event __declspec(deprecated)
#endif

namespace cora_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PoseGoal_SendGoal_Event_
{
  using Type = PoseGoal_SendGoal_Event_<ContainerAllocator>;

  explicit PoseGoal_SendGoal_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit PoseGoal_SendGoal_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<cora_msgs::action::PoseGoal_SendGoal_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<cora_msgs::action::PoseGoal_SendGoal_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<cora_msgs::action::PoseGoal_SendGoal_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<cora_msgs::action::PoseGoal_SendGoal_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<cora_msgs::action::PoseGoal_SendGoal_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<cora_msgs::action::PoseGoal_SendGoal_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<cora_msgs::action::PoseGoal_SendGoal_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<cora_msgs::action::PoseGoal_SendGoal_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cora_msgs::action::PoseGoal_SendGoal_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const cora_msgs::action::PoseGoal_SendGoal_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cora_msgs::action::PoseGoal_SendGoal_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cora_msgs::action::PoseGoal_SendGoal_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cora_msgs::action::PoseGoal_SendGoal_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cora_msgs::action::PoseGoal_SendGoal_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cora_msgs::action::PoseGoal_SendGoal_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cora_msgs::action::PoseGoal_SendGoal_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cora_msgs::action::PoseGoal_SendGoal_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cora_msgs::action::PoseGoal_SendGoal_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cora_msgs__action__PoseGoal_SendGoal_Event
    std::shared_ptr<cora_msgs::action::PoseGoal_SendGoal_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cora_msgs__action__PoseGoal_SendGoal_Event
    std::shared_ptr<cora_msgs::action::PoseGoal_SendGoal_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PoseGoal_SendGoal_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const PoseGoal_SendGoal_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PoseGoal_SendGoal_Event_

// alias to use template instance with default allocator
using PoseGoal_SendGoal_Event =
  cora_msgs::action::PoseGoal_SendGoal_Event_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace cora_msgs

namespace cora_msgs
{

namespace action
{

struct PoseGoal_SendGoal
{
  using Request = cora_msgs::action::PoseGoal_SendGoal_Request;
  using Response = cora_msgs::action::PoseGoal_SendGoal_Response;
  using Event = cora_msgs::action::PoseGoal_SendGoal_Event;
};

}  // namespace action

}  // namespace cora_msgs


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__cora_msgs__action__PoseGoal_GetResult_Request __attribute__((deprecated))
#else
# define DEPRECATED__cora_msgs__action__PoseGoal_GetResult_Request __declspec(deprecated)
#endif

namespace cora_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PoseGoal_GetResult_Request_
{
  using Type = PoseGoal_GetResult_Request_<ContainerAllocator>;

  explicit PoseGoal_GetResult_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init)
  {
    (void)_init;
  }

  explicit PoseGoal_GetResult_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cora_msgs::action::PoseGoal_GetResult_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const cora_msgs::action::PoseGoal_GetResult_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cora_msgs::action::PoseGoal_GetResult_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cora_msgs::action::PoseGoal_GetResult_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cora_msgs::action::PoseGoal_GetResult_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cora_msgs::action::PoseGoal_GetResult_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cora_msgs::action::PoseGoal_GetResult_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cora_msgs::action::PoseGoal_GetResult_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cora_msgs::action::PoseGoal_GetResult_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cora_msgs::action::PoseGoal_GetResult_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cora_msgs__action__PoseGoal_GetResult_Request
    std::shared_ptr<cora_msgs::action::PoseGoal_GetResult_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cora_msgs__action__PoseGoal_GetResult_Request
    std::shared_ptr<cora_msgs::action::PoseGoal_GetResult_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PoseGoal_GetResult_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const PoseGoal_GetResult_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PoseGoal_GetResult_Request_

// alias to use template instance with default allocator
using PoseGoal_GetResult_Request =
  cora_msgs::action::PoseGoal_GetResult_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace cora_msgs


// Include directives for member types
// Member 'result'
// already included above
// #include "cora_msgs/action/detail/pose_goal__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__cora_msgs__action__PoseGoal_GetResult_Response __attribute__((deprecated))
#else
# define DEPRECATED__cora_msgs__action__PoseGoal_GetResult_Response __declspec(deprecated)
#endif

namespace cora_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PoseGoal_GetResult_Response_
{
  using Type = PoseGoal_GetResult_Response_<ContainerAllocator>;

  explicit PoseGoal_GetResult_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  explicit PoseGoal_GetResult_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  // field types and members
  using _status_type =
    int8_t;
  _status_type status;
  using _result_type =
    cora_msgs::action::PoseGoal_Result_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__status(
    const int8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__result(
    const cora_msgs::action::PoseGoal_Result_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cora_msgs::action::PoseGoal_GetResult_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const cora_msgs::action::PoseGoal_GetResult_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cora_msgs::action::PoseGoal_GetResult_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cora_msgs::action::PoseGoal_GetResult_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cora_msgs::action::PoseGoal_GetResult_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cora_msgs::action::PoseGoal_GetResult_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cora_msgs::action::PoseGoal_GetResult_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cora_msgs::action::PoseGoal_GetResult_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cora_msgs::action::PoseGoal_GetResult_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cora_msgs::action::PoseGoal_GetResult_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cora_msgs__action__PoseGoal_GetResult_Response
    std::shared_ptr<cora_msgs::action::PoseGoal_GetResult_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cora_msgs__action__PoseGoal_GetResult_Response
    std::shared_ptr<cora_msgs::action::PoseGoal_GetResult_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PoseGoal_GetResult_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const PoseGoal_GetResult_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PoseGoal_GetResult_Response_

// alias to use template instance with default allocator
using PoseGoal_GetResult_Response =
  cora_msgs::action::PoseGoal_GetResult_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace cora_msgs


// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__cora_msgs__action__PoseGoal_GetResult_Event __attribute__((deprecated))
#else
# define DEPRECATED__cora_msgs__action__PoseGoal_GetResult_Event __declspec(deprecated)
#endif

namespace cora_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PoseGoal_GetResult_Event_
{
  using Type = PoseGoal_GetResult_Event_<ContainerAllocator>;

  explicit PoseGoal_GetResult_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit PoseGoal_GetResult_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<cora_msgs::action::PoseGoal_GetResult_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<cora_msgs::action::PoseGoal_GetResult_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<cora_msgs::action::PoseGoal_GetResult_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<cora_msgs::action::PoseGoal_GetResult_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<cora_msgs::action::PoseGoal_GetResult_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<cora_msgs::action::PoseGoal_GetResult_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<cora_msgs::action::PoseGoal_GetResult_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<cora_msgs::action::PoseGoal_GetResult_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cora_msgs::action::PoseGoal_GetResult_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const cora_msgs::action::PoseGoal_GetResult_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cora_msgs::action::PoseGoal_GetResult_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cora_msgs::action::PoseGoal_GetResult_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cora_msgs::action::PoseGoal_GetResult_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cora_msgs::action::PoseGoal_GetResult_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cora_msgs::action::PoseGoal_GetResult_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cora_msgs::action::PoseGoal_GetResult_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cora_msgs::action::PoseGoal_GetResult_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cora_msgs::action::PoseGoal_GetResult_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cora_msgs__action__PoseGoal_GetResult_Event
    std::shared_ptr<cora_msgs::action::PoseGoal_GetResult_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cora_msgs__action__PoseGoal_GetResult_Event
    std::shared_ptr<cora_msgs::action::PoseGoal_GetResult_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PoseGoal_GetResult_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const PoseGoal_GetResult_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PoseGoal_GetResult_Event_

// alias to use template instance with default allocator
using PoseGoal_GetResult_Event =
  cora_msgs::action::PoseGoal_GetResult_Event_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace cora_msgs

namespace cora_msgs
{

namespace action
{

struct PoseGoal_GetResult
{
  using Request = cora_msgs::action::PoseGoal_GetResult_Request;
  using Response = cora_msgs::action::PoseGoal_GetResult_Response;
  using Event = cora_msgs::action::PoseGoal_GetResult_Event;
};

}  // namespace action

}  // namespace cora_msgs


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'feedback'
// already included above
// #include "cora_msgs/action/detail/pose_goal__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__cora_msgs__action__PoseGoal_FeedbackMessage __attribute__((deprecated))
#else
# define DEPRECATED__cora_msgs__action__PoseGoal_FeedbackMessage __declspec(deprecated)
#endif

namespace cora_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PoseGoal_FeedbackMessage_
{
  using Type = PoseGoal_FeedbackMessage_<ContainerAllocator>;

  explicit PoseGoal_FeedbackMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    feedback(_init)
  {
    (void)_init;
  }

  explicit PoseGoal_FeedbackMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    feedback(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _feedback_type =
    cora_msgs::action::PoseGoal_Feedback_<ContainerAllocator>;
  _feedback_type feedback;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__feedback(
    const cora_msgs::action::PoseGoal_Feedback_<ContainerAllocator> & _arg)
  {
    this->feedback = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cora_msgs::action::PoseGoal_FeedbackMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const cora_msgs::action::PoseGoal_FeedbackMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cora_msgs::action::PoseGoal_FeedbackMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cora_msgs::action::PoseGoal_FeedbackMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cora_msgs::action::PoseGoal_FeedbackMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cora_msgs::action::PoseGoal_FeedbackMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cora_msgs::action::PoseGoal_FeedbackMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cora_msgs::action::PoseGoal_FeedbackMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cora_msgs::action::PoseGoal_FeedbackMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cora_msgs::action::PoseGoal_FeedbackMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cora_msgs__action__PoseGoal_FeedbackMessage
    std::shared_ptr<cora_msgs::action::PoseGoal_FeedbackMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cora_msgs__action__PoseGoal_FeedbackMessage
    std::shared_ptr<cora_msgs::action::PoseGoal_FeedbackMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PoseGoal_FeedbackMessage_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->feedback != other.feedback) {
      return false;
    }
    return true;
  }
  bool operator!=(const PoseGoal_FeedbackMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PoseGoal_FeedbackMessage_

// alias to use template instance with default allocator
using PoseGoal_FeedbackMessage =
  cora_msgs::action::PoseGoal_FeedbackMessage_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace cora_msgs

#include "action_msgs/srv/cancel_goal.hpp"
#include "action_msgs/msg/goal_info.hpp"
#include "action_msgs/msg/goal_status_array.hpp"

namespace cora_msgs
{

namespace action
{

struct PoseGoal
{
  /// The goal message defined in the action definition.
  using Goal = cora_msgs::action::PoseGoal_Goal;
  /// The result message defined in the action definition.
  using Result = cora_msgs::action::PoseGoal_Result;
  /// The feedback message defined in the action definition.
  using Feedback = cora_msgs::action::PoseGoal_Feedback;

  struct Impl
  {
    /// The send_goal service using a wrapped version of the goal message as a request.
    using SendGoalService = cora_msgs::action::PoseGoal_SendGoal;
    /// The get_result service using a wrapped version of the result message as a response.
    using GetResultService = cora_msgs::action::PoseGoal_GetResult;
    /// The feedback message with generic fields which wraps the feedback message.
    using FeedbackMessage = cora_msgs::action::PoseGoal_FeedbackMessage;

    /// The generic service to cancel a goal.
    using CancelGoalService = action_msgs::srv::CancelGoal;
    /// The generic message for the status of a goal.
    using GoalStatusMessage = action_msgs::msg::GoalStatusArray;
  };
};

typedef struct PoseGoal PoseGoal;

}  // namespace action

}  // namespace cora_msgs

#endif  // CORA_MSGS__ACTION__DETAIL__POSE_GOAL__STRUCT_HPP_
