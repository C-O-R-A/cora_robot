// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cora_msgs:action/PoseGoal.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "cora_msgs/action/pose_goal.h"


#ifndef CORA_MSGS__ACTION__DETAIL__POSE_GOAL__STRUCT_H_
#define CORA_MSGS__ACTION__DETAIL__POSE_GOAL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'pose_goal'
#include "cora_msgs/msg/detail/targeted_pose_stamped__struct.h"
// Member 'joint_goal'
#include "rosidl_runtime_c/primitives_sequence.h"
// Member 'predefined_pose'
// Member 'space'
// Member 'interface_type'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/PoseGoal in the package cora_msgs.
typedef struct cora_msgs__action__PoseGoal_Goal
{
  /// Goal
  cora_msgs__msg__TargetedPoseStamped pose_goal;
  /// [J1, J2, J3, J4, J5, J6]
  rosidl_runtime_c__double__Sequence joint_goal;
  /// 'standby' or 'straight', see srdf for more details
  rosidl_runtime_c__String predefined_pose;
  /// 'TS' or 'JS'
  rosidl_runtime_c__String space;
  /// 'position' or 'velocity' or 'acceleration' or 'effort'
  rosidl_runtime_c__String interface_type;
} cora_msgs__action__PoseGoal_Goal;

// Struct for a sequence of cora_msgs__action__PoseGoal_Goal.
typedef struct cora_msgs__action__PoseGoal_Goal__Sequence
{
  cora_msgs__action__PoseGoal_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cora_msgs__action__PoseGoal_Goal__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'pose_result'
#include "geometry_msgs/msg/detail/pose_stamped__struct.h"
// Member 'joint_result'
// already included above
// #include "rosidl_runtime_c/primitives_sequence.h"
// Member 'status_result'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/PoseGoal in the package cora_msgs.
typedef struct cora_msgs__action__PoseGoal_Result
{
  geometry_msgs__msg__PoseStamped pose_result;
  rosidl_runtime_c__double__Sequence joint_result;
  rosidl_runtime_c__String status_result;
  bool success;
} cora_msgs__action__PoseGoal_Result;

// Struct for a sequence of cora_msgs__action__PoseGoal_Result.
typedef struct cora_msgs__action__PoseGoal_Result__Sequence
{
  cora_msgs__action__PoseGoal_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cora_msgs__action__PoseGoal_Result__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'pose_feedback'
// already included above
// #include "geometry_msgs/msg/detail/pose_stamped__struct.h"
// Member 'status'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/PoseGoal in the package cora_msgs.
typedef struct cora_msgs__action__PoseGoal_Feedback
{
  geometry_msgs__msg__PoseStamped pose_feedback;
  rosidl_runtime_c__String status;
} cora_msgs__action__PoseGoal_Feedback;

// Struct for a sequence of cora_msgs__action__PoseGoal_Feedback.
typedef struct cora_msgs__action__PoseGoal_Feedback__Sequence
{
  cora_msgs__action__PoseGoal_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cora_msgs__action__PoseGoal_Feedback__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "cora_msgs/action/detail/pose_goal__struct.h"

/// Struct defined in action/PoseGoal in the package cora_msgs.
typedef struct cora_msgs__action__PoseGoal_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  cora_msgs__action__PoseGoal_Goal goal;
} cora_msgs__action__PoseGoal_SendGoal_Request;

// Struct for a sequence of cora_msgs__action__PoseGoal_SendGoal_Request.
typedef struct cora_msgs__action__PoseGoal_SendGoal_Request__Sequence
{
  cora_msgs__action__PoseGoal_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cora_msgs__action__PoseGoal_SendGoal_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/PoseGoal in the package cora_msgs.
typedef struct cora_msgs__action__PoseGoal_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} cora_msgs__action__PoseGoal_SendGoal_Response;

// Struct for a sequence of cora_msgs__action__PoseGoal_SendGoal_Response.
typedef struct cora_msgs__action__PoseGoal_SendGoal_Response__Sequence
{
  cora_msgs__action__PoseGoal_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cora_msgs__action__PoseGoal_SendGoal_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  cora_msgs__action__PoseGoal_SendGoal_Event__request__MAX_SIZE = 1
};
// response
enum
{
  cora_msgs__action__PoseGoal_SendGoal_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/PoseGoal in the package cora_msgs.
typedef struct cora_msgs__action__PoseGoal_SendGoal_Event
{
  service_msgs__msg__ServiceEventInfo info;
  cora_msgs__action__PoseGoal_SendGoal_Request__Sequence request;
  cora_msgs__action__PoseGoal_SendGoal_Response__Sequence response;
} cora_msgs__action__PoseGoal_SendGoal_Event;

// Struct for a sequence of cora_msgs__action__PoseGoal_SendGoal_Event.
typedef struct cora_msgs__action__PoseGoal_SendGoal_Event__Sequence
{
  cora_msgs__action__PoseGoal_SendGoal_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cora_msgs__action__PoseGoal_SendGoal_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/PoseGoal in the package cora_msgs.
typedef struct cora_msgs__action__PoseGoal_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} cora_msgs__action__PoseGoal_GetResult_Request;

// Struct for a sequence of cora_msgs__action__PoseGoal_GetResult_Request.
typedef struct cora_msgs__action__PoseGoal_GetResult_Request__Sequence
{
  cora_msgs__action__PoseGoal_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cora_msgs__action__PoseGoal_GetResult_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "cora_msgs/action/detail/pose_goal__struct.h"

/// Struct defined in action/PoseGoal in the package cora_msgs.
typedef struct cora_msgs__action__PoseGoal_GetResult_Response
{
  int8_t status;
  cora_msgs__action__PoseGoal_Result result;
} cora_msgs__action__PoseGoal_GetResult_Response;

// Struct for a sequence of cora_msgs__action__PoseGoal_GetResult_Response.
typedef struct cora_msgs__action__PoseGoal_GetResult_Response__Sequence
{
  cora_msgs__action__PoseGoal_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cora_msgs__action__PoseGoal_GetResult_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  cora_msgs__action__PoseGoal_GetResult_Event__request__MAX_SIZE = 1
};
// response
enum
{
  cora_msgs__action__PoseGoal_GetResult_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/PoseGoal in the package cora_msgs.
typedef struct cora_msgs__action__PoseGoal_GetResult_Event
{
  service_msgs__msg__ServiceEventInfo info;
  cora_msgs__action__PoseGoal_GetResult_Request__Sequence request;
  cora_msgs__action__PoseGoal_GetResult_Response__Sequence response;
} cora_msgs__action__PoseGoal_GetResult_Event;

// Struct for a sequence of cora_msgs__action__PoseGoal_GetResult_Event.
typedef struct cora_msgs__action__PoseGoal_GetResult_Event__Sequence
{
  cora_msgs__action__PoseGoal_GetResult_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cora_msgs__action__PoseGoal_GetResult_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "cora_msgs/action/detail/pose_goal__struct.h"

/// Struct defined in action/PoseGoal in the package cora_msgs.
typedef struct cora_msgs__action__PoseGoal_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  cora_msgs__action__PoseGoal_Feedback feedback;
} cora_msgs__action__PoseGoal_FeedbackMessage;

// Struct for a sequence of cora_msgs__action__PoseGoal_FeedbackMessage.
typedef struct cora_msgs__action__PoseGoal_FeedbackMessage__Sequence
{
  cora_msgs__action__PoseGoal_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cora_msgs__action__PoseGoal_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CORA_MSGS__ACTION__DETAIL__POSE_GOAL__STRUCT_H_
