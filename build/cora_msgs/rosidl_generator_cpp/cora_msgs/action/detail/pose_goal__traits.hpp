// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cora_msgs:action/PoseGoal.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "cora_msgs/action/pose_goal.hpp"


#ifndef CORA_MSGS__ACTION__DETAIL__POSE_GOAL__TRAITS_HPP_
#define CORA_MSGS__ACTION__DETAIL__POSE_GOAL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cora_msgs/action/detail/pose_goal__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'pose_goal'
#include "cora_msgs/msg/detail/targeted_pose_stamped__traits.hpp"

namespace cora_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const PoseGoal_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: pose_goal
  {
    out << "pose_goal: ";
    to_flow_style_yaml(msg.pose_goal, out);
    out << ", ";
  }

  // member: joint_goal
  {
    if (msg.joint_goal.size() == 0) {
      out << "joint_goal: []";
    } else {
      out << "joint_goal: [";
      size_t pending_items = msg.joint_goal.size();
      for (auto item : msg.joint_goal) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: predefined_pose
  {
    out << "predefined_pose: ";
    rosidl_generator_traits::value_to_yaml(msg.predefined_pose, out);
    out << ", ";
  }

  // member: space
  {
    out << "space: ";
    rosidl_generator_traits::value_to_yaml(msg.space, out);
    out << ", ";
  }

  // member: interface_type
  {
    out << "interface_type: ";
    rosidl_generator_traits::value_to_yaml(msg.interface_type, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PoseGoal_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pose_goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose_goal:\n";
    to_block_style_yaml(msg.pose_goal, out, indentation + 2);
  }

  // member: joint_goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.joint_goal.size() == 0) {
      out << "joint_goal: []\n";
    } else {
      out << "joint_goal:\n";
      for (auto item : msg.joint_goal) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: predefined_pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "predefined_pose: ";
    rosidl_generator_traits::value_to_yaml(msg.predefined_pose, out);
    out << "\n";
  }

  // member: space
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "space: ";
    rosidl_generator_traits::value_to_yaml(msg.space, out);
    out << "\n";
  }

  // member: interface_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "interface_type: ";
    rosidl_generator_traits::value_to_yaml(msg.interface_type, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PoseGoal_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace cora_msgs

namespace rosidl_generator_traits
{

[[deprecated("use cora_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cora_msgs::action::PoseGoal_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  cora_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cora_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const cora_msgs::action::PoseGoal_Goal & msg)
{
  return cora_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<cora_msgs::action::PoseGoal_Goal>()
{
  return "cora_msgs::action::PoseGoal_Goal";
}

template<>
inline const char * name<cora_msgs::action::PoseGoal_Goal>()
{
  return "cora_msgs/action/PoseGoal_Goal";
}

template<>
struct has_fixed_size<cora_msgs::action::PoseGoal_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cora_msgs::action::PoseGoal_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<cora_msgs::action::PoseGoal_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'pose_result'
#include "geometry_msgs/msg/detail/pose_stamped__traits.hpp"

namespace cora_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const PoseGoal_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: pose_result
  {
    out << "pose_result: ";
    to_flow_style_yaml(msg.pose_result, out);
    out << ", ";
  }

  // member: joint_result
  {
    if (msg.joint_result.size() == 0) {
      out << "joint_result: []";
    } else {
      out << "joint_result: [";
      size_t pending_items = msg.joint_result.size();
      for (auto item : msg.joint_result) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: status_result
  {
    out << "status_result: ";
    rosidl_generator_traits::value_to_yaml(msg.status_result, out);
    out << ", ";
  }

  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PoseGoal_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pose_result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose_result:\n";
    to_block_style_yaml(msg.pose_result, out, indentation + 2);
  }

  // member: joint_result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.joint_result.size() == 0) {
      out << "joint_result: []\n";
    } else {
      out << "joint_result:\n";
      for (auto item : msg.joint_result) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: status_result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status_result: ";
    rosidl_generator_traits::value_to_yaml(msg.status_result, out);
    out << "\n";
  }

  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PoseGoal_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace cora_msgs

namespace rosidl_generator_traits
{

[[deprecated("use cora_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cora_msgs::action::PoseGoal_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  cora_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cora_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const cora_msgs::action::PoseGoal_Result & msg)
{
  return cora_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<cora_msgs::action::PoseGoal_Result>()
{
  return "cora_msgs::action::PoseGoal_Result";
}

template<>
inline const char * name<cora_msgs::action::PoseGoal_Result>()
{
  return "cora_msgs/action/PoseGoal_Result";
}

template<>
struct has_fixed_size<cora_msgs::action::PoseGoal_Result>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cora_msgs::action::PoseGoal_Result>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<cora_msgs::action::PoseGoal_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'pose_feedback'
// already included above
// #include "geometry_msgs/msg/detail/pose_stamped__traits.hpp"

namespace cora_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const PoseGoal_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: pose_feedback
  {
    out << "pose_feedback: ";
    to_flow_style_yaml(msg.pose_feedback, out);
    out << ", ";
  }

  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PoseGoal_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pose_feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose_feedback:\n";
    to_block_style_yaml(msg.pose_feedback, out, indentation + 2);
  }

  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PoseGoal_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace cora_msgs

namespace rosidl_generator_traits
{

[[deprecated("use cora_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cora_msgs::action::PoseGoal_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  cora_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cora_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const cora_msgs::action::PoseGoal_Feedback & msg)
{
  return cora_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<cora_msgs::action::PoseGoal_Feedback>()
{
  return "cora_msgs::action::PoseGoal_Feedback";
}

template<>
inline const char * name<cora_msgs::action::PoseGoal_Feedback>()
{
  return "cora_msgs/action/PoseGoal_Feedback";
}

template<>
struct has_fixed_size<cora_msgs::action::PoseGoal_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cora_msgs::action::PoseGoal_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<cora_msgs::action::PoseGoal_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "cora_msgs/action/detail/pose_goal__traits.hpp"

namespace cora_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const PoseGoal_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PoseGoal_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PoseGoal_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace cora_msgs

namespace rosidl_generator_traits
{

[[deprecated("use cora_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cora_msgs::action::PoseGoal_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  cora_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cora_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const cora_msgs::action::PoseGoal_SendGoal_Request & msg)
{
  return cora_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<cora_msgs::action::PoseGoal_SendGoal_Request>()
{
  return "cora_msgs::action::PoseGoal_SendGoal_Request";
}

template<>
inline const char * name<cora_msgs::action::PoseGoal_SendGoal_Request>()
{
  return "cora_msgs/action/PoseGoal_SendGoal_Request";
}

template<>
struct has_fixed_size<cora_msgs::action::PoseGoal_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<cora_msgs::action::PoseGoal_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<cora_msgs::action::PoseGoal_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<cora_msgs::action::PoseGoal_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<cora_msgs::action::PoseGoal_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace cora_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const PoseGoal_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PoseGoal_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PoseGoal_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace cora_msgs

namespace rosidl_generator_traits
{

[[deprecated("use cora_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cora_msgs::action::PoseGoal_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  cora_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cora_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const cora_msgs::action::PoseGoal_SendGoal_Response & msg)
{
  return cora_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<cora_msgs::action::PoseGoal_SendGoal_Response>()
{
  return "cora_msgs::action::PoseGoal_SendGoal_Response";
}

template<>
inline const char * name<cora_msgs::action::PoseGoal_SendGoal_Response>()
{
  return "cora_msgs/action/PoseGoal_SendGoal_Response";
}

template<>
struct has_fixed_size<cora_msgs::action::PoseGoal_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<cora_msgs::action::PoseGoal_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<cora_msgs::action::PoseGoal_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace cora_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const PoseGoal_SendGoal_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PoseGoal_SendGoal_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PoseGoal_SendGoal_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace cora_msgs

namespace rosidl_generator_traits
{

[[deprecated("use cora_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cora_msgs::action::PoseGoal_SendGoal_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  cora_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cora_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const cora_msgs::action::PoseGoal_SendGoal_Event & msg)
{
  return cora_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<cora_msgs::action::PoseGoal_SendGoal_Event>()
{
  return "cora_msgs::action::PoseGoal_SendGoal_Event";
}

template<>
inline const char * name<cora_msgs::action::PoseGoal_SendGoal_Event>()
{
  return "cora_msgs/action/PoseGoal_SendGoal_Event";
}

template<>
struct has_fixed_size<cora_msgs::action::PoseGoal_SendGoal_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cora_msgs::action::PoseGoal_SendGoal_Event>
  : std::integral_constant<bool, has_bounded_size<cora_msgs::action::PoseGoal_SendGoal_Request>::value && has_bounded_size<cora_msgs::action::PoseGoal_SendGoal_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<cora_msgs::action::PoseGoal_SendGoal_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<cora_msgs::action::PoseGoal_SendGoal>()
{
  return "cora_msgs::action::PoseGoal_SendGoal";
}

template<>
inline const char * name<cora_msgs::action::PoseGoal_SendGoal>()
{
  return "cora_msgs/action/PoseGoal_SendGoal";
}

template<>
struct has_fixed_size<cora_msgs::action::PoseGoal_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<cora_msgs::action::PoseGoal_SendGoal_Request>::value &&
    has_fixed_size<cora_msgs::action::PoseGoal_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<cora_msgs::action::PoseGoal_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<cora_msgs::action::PoseGoal_SendGoal_Request>::value &&
    has_bounded_size<cora_msgs::action::PoseGoal_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<cora_msgs::action::PoseGoal_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<cora_msgs::action::PoseGoal_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<cora_msgs::action::PoseGoal_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace cora_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const PoseGoal_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PoseGoal_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PoseGoal_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace cora_msgs

namespace rosidl_generator_traits
{

[[deprecated("use cora_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cora_msgs::action::PoseGoal_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  cora_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cora_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const cora_msgs::action::PoseGoal_GetResult_Request & msg)
{
  return cora_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<cora_msgs::action::PoseGoal_GetResult_Request>()
{
  return "cora_msgs::action::PoseGoal_GetResult_Request";
}

template<>
inline const char * name<cora_msgs::action::PoseGoal_GetResult_Request>()
{
  return "cora_msgs/action/PoseGoal_GetResult_Request";
}

template<>
struct has_fixed_size<cora_msgs::action::PoseGoal_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<cora_msgs::action::PoseGoal_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<cora_msgs::action::PoseGoal_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "cora_msgs/action/detail/pose_goal__traits.hpp"

namespace cora_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const PoseGoal_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PoseGoal_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PoseGoal_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace cora_msgs

namespace rosidl_generator_traits
{

[[deprecated("use cora_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cora_msgs::action::PoseGoal_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  cora_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cora_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const cora_msgs::action::PoseGoal_GetResult_Response & msg)
{
  return cora_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<cora_msgs::action::PoseGoal_GetResult_Response>()
{
  return "cora_msgs::action::PoseGoal_GetResult_Response";
}

template<>
inline const char * name<cora_msgs::action::PoseGoal_GetResult_Response>()
{
  return "cora_msgs/action/PoseGoal_GetResult_Response";
}

template<>
struct has_fixed_size<cora_msgs::action::PoseGoal_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<cora_msgs::action::PoseGoal_Result>::value> {};

template<>
struct has_bounded_size<cora_msgs::action::PoseGoal_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<cora_msgs::action::PoseGoal_Result>::value> {};

template<>
struct is_message<cora_msgs::action::PoseGoal_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace cora_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const PoseGoal_GetResult_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PoseGoal_GetResult_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PoseGoal_GetResult_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace cora_msgs

namespace rosidl_generator_traits
{

[[deprecated("use cora_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cora_msgs::action::PoseGoal_GetResult_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  cora_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cora_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const cora_msgs::action::PoseGoal_GetResult_Event & msg)
{
  return cora_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<cora_msgs::action::PoseGoal_GetResult_Event>()
{
  return "cora_msgs::action::PoseGoal_GetResult_Event";
}

template<>
inline const char * name<cora_msgs::action::PoseGoal_GetResult_Event>()
{
  return "cora_msgs/action/PoseGoal_GetResult_Event";
}

template<>
struct has_fixed_size<cora_msgs::action::PoseGoal_GetResult_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cora_msgs::action::PoseGoal_GetResult_Event>
  : std::integral_constant<bool, has_bounded_size<cora_msgs::action::PoseGoal_GetResult_Request>::value && has_bounded_size<cora_msgs::action::PoseGoal_GetResult_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<cora_msgs::action::PoseGoal_GetResult_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<cora_msgs::action::PoseGoal_GetResult>()
{
  return "cora_msgs::action::PoseGoal_GetResult";
}

template<>
inline const char * name<cora_msgs::action::PoseGoal_GetResult>()
{
  return "cora_msgs/action/PoseGoal_GetResult";
}

template<>
struct has_fixed_size<cora_msgs::action::PoseGoal_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<cora_msgs::action::PoseGoal_GetResult_Request>::value &&
    has_fixed_size<cora_msgs::action::PoseGoal_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<cora_msgs::action::PoseGoal_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<cora_msgs::action::PoseGoal_GetResult_Request>::value &&
    has_bounded_size<cora_msgs::action::PoseGoal_GetResult_Response>::value
  >
{
};

template<>
struct is_service<cora_msgs::action::PoseGoal_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<cora_msgs::action::PoseGoal_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<cora_msgs::action::PoseGoal_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "cora_msgs/action/detail/pose_goal__traits.hpp"

namespace cora_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const PoseGoal_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PoseGoal_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PoseGoal_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace cora_msgs

namespace rosidl_generator_traits
{

[[deprecated("use cora_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cora_msgs::action::PoseGoal_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  cora_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cora_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const cora_msgs::action::PoseGoal_FeedbackMessage & msg)
{
  return cora_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<cora_msgs::action::PoseGoal_FeedbackMessage>()
{
  return "cora_msgs::action::PoseGoal_FeedbackMessage";
}

template<>
inline const char * name<cora_msgs::action::PoseGoal_FeedbackMessage>()
{
  return "cora_msgs/action/PoseGoal_FeedbackMessage";
}

template<>
struct has_fixed_size<cora_msgs::action::PoseGoal_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<cora_msgs::action::PoseGoal_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<cora_msgs::action::PoseGoal_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<cora_msgs::action::PoseGoal_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<cora_msgs::action::PoseGoal_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<cora_msgs::action::PoseGoal>
  : std::true_type
{
};

template<>
struct is_action_goal<cora_msgs::action::PoseGoal_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<cora_msgs::action::PoseGoal_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<cora_msgs::action::PoseGoal_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // CORA_MSGS__ACTION__DETAIL__POSE_GOAL__TRAITS_HPP_
