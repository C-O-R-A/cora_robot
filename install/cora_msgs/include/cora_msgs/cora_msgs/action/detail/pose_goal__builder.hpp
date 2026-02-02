// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cora_msgs:action/PoseGoal.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "cora_msgs/action/pose_goal.hpp"


#ifndef CORA_MSGS__ACTION__DETAIL__POSE_GOAL__BUILDER_HPP_
#define CORA_MSGS__ACTION__DETAIL__POSE_GOAL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cora_msgs/action/detail/pose_goal__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cora_msgs
{

namespace action
{

namespace builder
{

class Init_PoseGoal_Goal_interface_type
{
public:
  explicit Init_PoseGoal_Goal_interface_type(::cora_msgs::action::PoseGoal_Goal & msg)
  : msg_(msg)
  {}
  ::cora_msgs::action::PoseGoal_Goal interface_type(::cora_msgs::action::PoseGoal_Goal::_interface_type_type arg)
  {
    msg_.interface_type = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cora_msgs::action::PoseGoal_Goal msg_;
};

class Init_PoseGoal_Goal_space
{
public:
  explicit Init_PoseGoal_Goal_space(::cora_msgs::action::PoseGoal_Goal & msg)
  : msg_(msg)
  {}
  Init_PoseGoal_Goal_interface_type space(::cora_msgs::action::PoseGoal_Goal::_space_type arg)
  {
    msg_.space = std::move(arg);
    return Init_PoseGoal_Goal_interface_type(msg_);
  }

private:
  ::cora_msgs::action::PoseGoal_Goal msg_;
};

class Init_PoseGoal_Goal_predefined_pose
{
public:
  explicit Init_PoseGoal_Goal_predefined_pose(::cora_msgs::action::PoseGoal_Goal & msg)
  : msg_(msg)
  {}
  Init_PoseGoal_Goal_space predefined_pose(::cora_msgs::action::PoseGoal_Goal::_predefined_pose_type arg)
  {
    msg_.predefined_pose = std::move(arg);
    return Init_PoseGoal_Goal_space(msg_);
  }

private:
  ::cora_msgs::action::PoseGoal_Goal msg_;
};

class Init_PoseGoal_Goal_joint_goal
{
public:
  explicit Init_PoseGoal_Goal_joint_goal(::cora_msgs::action::PoseGoal_Goal & msg)
  : msg_(msg)
  {}
  Init_PoseGoal_Goal_predefined_pose joint_goal(::cora_msgs::action::PoseGoal_Goal::_joint_goal_type arg)
  {
    msg_.joint_goal = std::move(arg);
    return Init_PoseGoal_Goal_predefined_pose(msg_);
  }

private:
  ::cora_msgs::action::PoseGoal_Goal msg_;
};

class Init_PoseGoal_Goal_pose_goal
{
public:
  Init_PoseGoal_Goal_pose_goal()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PoseGoal_Goal_joint_goal pose_goal(::cora_msgs::action::PoseGoal_Goal::_pose_goal_type arg)
  {
    msg_.pose_goal = std::move(arg);
    return Init_PoseGoal_Goal_joint_goal(msg_);
  }

private:
  ::cora_msgs::action::PoseGoal_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::cora_msgs::action::PoseGoal_Goal>()
{
  return cora_msgs::action::builder::Init_PoseGoal_Goal_pose_goal();
}

}  // namespace cora_msgs


namespace cora_msgs
{

namespace action
{

namespace builder
{

class Init_PoseGoal_Result_success
{
public:
  explicit Init_PoseGoal_Result_success(::cora_msgs::action::PoseGoal_Result & msg)
  : msg_(msg)
  {}
  ::cora_msgs::action::PoseGoal_Result success(::cora_msgs::action::PoseGoal_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cora_msgs::action::PoseGoal_Result msg_;
};

class Init_PoseGoal_Result_status_result
{
public:
  explicit Init_PoseGoal_Result_status_result(::cora_msgs::action::PoseGoal_Result & msg)
  : msg_(msg)
  {}
  Init_PoseGoal_Result_success status_result(::cora_msgs::action::PoseGoal_Result::_status_result_type arg)
  {
    msg_.status_result = std::move(arg);
    return Init_PoseGoal_Result_success(msg_);
  }

private:
  ::cora_msgs::action::PoseGoal_Result msg_;
};

class Init_PoseGoal_Result_joint_result
{
public:
  explicit Init_PoseGoal_Result_joint_result(::cora_msgs::action::PoseGoal_Result & msg)
  : msg_(msg)
  {}
  Init_PoseGoal_Result_status_result joint_result(::cora_msgs::action::PoseGoal_Result::_joint_result_type arg)
  {
    msg_.joint_result = std::move(arg);
    return Init_PoseGoal_Result_status_result(msg_);
  }

private:
  ::cora_msgs::action::PoseGoal_Result msg_;
};

class Init_PoseGoal_Result_pose_result
{
public:
  Init_PoseGoal_Result_pose_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PoseGoal_Result_joint_result pose_result(::cora_msgs::action::PoseGoal_Result::_pose_result_type arg)
  {
    msg_.pose_result = std::move(arg);
    return Init_PoseGoal_Result_joint_result(msg_);
  }

private:
  ::cora_msgs::action::PoseGoal_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::cora_msgs::action::PoseGoal_Result>()
{
  return cora_msgs::action::builder::Init_PoseGoal_Result_pose_result();
}

}  // namespace cora_msgs


namespace cora_msgs
{

namespace action
{

namespace builder
{

class Init_PoseGoal_Feedback_status
{
public:
  explicit Init_PoseGoal_Feedback_status(::cora_msgs::action::PoseGoal_Feedback & msg)
  : msg_(msg)
  {}
  ::cora_msgs::action::PoseGoal_Feedback status(::cora_msgs::action::PoseGoal_Feedback::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cora_msgs::action::PoseGoal_Feedback msg_;
};

class Init_PoseGoal_Feedback_pose_feedback
{
public:
  Init_PoseGoal_Feedback_pose_feedback()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PoseGoal_Feedback_status pose_feedback(::cora_msgs::action::PoseGoal_Feedback::_pose_feedback_type arg)
  {
    msg_.pose_feedback = std::move(arg);
    return Init_PoseGoal_Feedback_status(msg_);
  }

private:
  ::cora_msgs::action::PoseGoal_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::cora_msgs::action::PoseGoal_Feedback>()
{
  return cora_msgs::action::builder::Init_PoseGoal_Feedback_pose_feedback();
}

}  // namespace cora_msgs


namespace cora_msgs
{

namespace action
{

namespace builder
{

class Init_PoseGoal_SendGoal_Request_goal
{
public:
  explicit Init_PoseGoal_SendGoal_Request_goal(::cora_msgs::action::PoseGoal_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::cora_msgs::action::PoseGoal_SendGoal_Request goal(::cora_msgs::action::PoseGoal_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cora_msgs::action::PoseGoal_SendGoal_Request msg_;
};

class Init_PoseGoal_SendGoal_Request_goal_id
{
public:
  Init_PoseGoal_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PoseGoal_SendGoal_Request_goal goal_id(::cora_msgs::action::PoseGoal_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_PoseGoal_SendGoal_Request_goal(msg_);
  }

private:
  ::cora_msgs::action::PoseGoal_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::cora_msgs::action::PoseGoal_SendGoal_Request>()
{
  return cora_msgs::action::builder::Init_PoseGoal_SendGoal_Request_goal_id();
}

}  // namespace cora_msgs


namespace cora_msgs
{

namespace action
{

namespace builder
{

class Init_PoseGoal_SendGoal_Response_stamp
{
public:
  explicit Init_PoseGoal_SendGoal_Response_stamp(::cora_msgs::action::PoseGoal_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::cora_msgs::action::PoseGoal_SendGoal_Response stamp(::cora_msgs::action::PoseGoal_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cora_msgs::action::PoseGoal_SendGoal_Response msg_;
};

class Init_PoseGoal_SendGoal_Response_accepted
{
public:
  Init_PoseGoal_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PoseGoal_SendGoal_Response_stamp accepted(::cora_msgs::action::PoseGoal_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_PoseGoal_SendGoal_Response_stamp(msg_);
  }

private:
  ::cora_msgs::action::PoseGoal_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::cora_msgs::action::PoseGoal_SendGoal_Response>()
{
  return cora_msgs::action::builder::Init_PoseGoal_SendGoal_Response_accepted();
}

}  // namespace cora_msgs


namespace cora_msgs
{

namespace action
{

namespace builder
{

class Init_PoseGoal_SendGoal_Event_response
{
public:
  explicit Init_PoseGoal_SendGoal_Event_response(::cora_msgs::action::PoseGoal_SendGoal_Event & msg)
  : msg_(msg)
  {}
  ::cora_msgs::action::PoseGoal_SendGoal_Event response(::cora_msgs::action::PoseGoal_SendGoal_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cora_msgs::action::PoseGoal_SendGoal_Event msg_;
};

class Init_PoseGoal_SendGoal_Event_request
{
public:
  explicit Init_PoseGoal_SendGoal_Event_request(::cora_msgs::action::PoseGoal_SendGoal_Event & msg)
  : msg_(msg)
  {}
  Init_PoseGoal_SendGoal_Event_response request(::cora_msgs::action::PoseGoal_SendGoal_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_PoseGoal_SendGoal_Event_response(msg_);
  }

private:
  ::cora_msgs::action::PoseGoal_SendGoal_Event msg_;
};

class Init_PoseGoal_SendGoal_Event_info
{
public:
  Init_PoseGoal_SendGoal_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PoseGoal_SendGoal_Event_request info(::cora_msgs::action::PoseGoal_SendGoal_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_PoseGoal_SendGoal_Event_request(msg_);
  }

private:
  ::cora_msgs::action::PoseGoal_SendGoal_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::cora_msgs::action::PoseGoal_SendGoal_Event>()
{
  return cora_msgs::action::builder::Init_PoseGoal_SendGoal_Event_info();
}

}  // namespace cora_msgs


namespace cora_msgs
{

namespace action
{

namespace builder
{

class Init_PoseGoal_GetResult_Request_goal_id
{
public:
  Init_PoseGoal_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::cora_msgs::action::PoseGoal_GetResult_Request goal_id(::cora_msgs::action::PoseGoal_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cora_msgs::action::PoseGoal_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::cora_msgs::action::PoseGoal_GetResult_Request>()
{
  return cora_msgs::action::builder::Init_PoseGoal_GetResult_Request_goal_id();
}

}  // namespace cora_msgs


namespace cora_msgs
{

namespace action
{

namespace builder
{

class Init_PoseGoal_GetResult_Response_result
{
public:
  explicit Init_PoseGoal_GetResult_Response_result(::cora_msgs::action::PoseGoal_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::cora_msgs::action::PoseGoal_GetResult_Response result(::cora_msgs::action::PoseGoal_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cora_msgs::action::PoseGoal_GetResult_Response msg_;
};

class Init_PoseGoal_GetResult_Response_status
{
public:
  Init_PoseGoal_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PoseGoal_GetResult_Response_result status(::cora_msgs::action::PoseGoal_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_PoseGoal_GetResult_Response_result(msg_);
  }

private:
  ::cora_msgs::action::PoseGoal_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::cora_msgs::action::PoseGoal_GetResult_Response>()
{
  return cora_msgs::action::builder::Init_PoseGoal_GetResult_Response_status();
}

}  // namespace cora_msgs


namespace cora_msgs
{

namespace action
{

namespace builder
{

class Init_PoseGoal_GetResult_Event_response
{
public:
  explicit Init_PoseGoal_GetResult_Event_response(::cora_msgs::action::PoseGoal_GetResult_Event & msg)
  : msg_(msg)
  {}
  ::cora_msgs::action::PoseGoal_GetResult_Event response(::cora_msgs::action::PoseGoal_GetResult_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cora_msgs::action::PoseGoal_GetResult_Event msg_;
};

class Init_PoseGoal_GetResult_Event_request
{
public:
  explicit Init_PoseGoal_GetResult_Event_request(::cora_msgs::action::PoseGoal_GetResult_Event & msg)
  : msg_(msg)
  {}
  Init_PoseGoal_GetResult_Event_response request(::cora_msgs::action::PoseGoal_GetResult_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_PoseGoal_GetResult_Event_response(msg_);
  }

private:
  ::cora_msgs::action::PoseGoal_GetResult_Event msg_;
};

class Init_PoseGoal_GetResult_Event_info
{
public:
  Init_PoseGoal_GetResult_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PoseGoal_GetResult_Event_request info(::cora_msgs::action::PoseGoal_GetResult_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_PoseGoal_GetResult_Event_request(msg_);
  }

private:
  ::cora_msgs::action::PoseGoal_GetResult_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::cora_msgs::action::PoseGoal_GetResult_Event>()
{
  return cora_msgs::action::builder::Init_PoseGoal_GetResult_Event_info();
}

}  // namespace cora_msgs


namespace cora_msgs
{

namespace action
{

namespace builder
{

class Init_PoseGoal_FeedbackMessage_feedback
{
public:
  explicit Init_PoseGoal_FeedbackMessage_feedback(::cora_msgs::action::PoseGoal_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::cora_msgs::action::PoseGoal_FeedbackMessage feedback(::cora_msgs::action::PoseGoal_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cora_msgs::action::PoseGoal_FeedbackMessage msg_;
};

class Init_PoseGoal_FeedbackMessage_goal_id
{
public:
  Init_PoseGoal_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PoseGoal_FeedbackMessage_feedback goal_id(::cora_msgs::action::PoseGoal_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_PoseGoal_FeedbackMessage_feedback(msg_);
  }

private:
  ::cora_msgs::action::PoseGoal_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::cora_msgs::action::PoseGoal_FeedbackMessage>()
{
  return cora_msgs::action::builder::Init_PoseGoal_FeedbackMessage_goal_id();
}

}  // namespace cora_msgs

#endif  // CORA_MSGS__ACTION__DETAIL__POSE_GOAL__BUILDER_HPP_
