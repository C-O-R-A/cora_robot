// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from cora_msgs:action/PoseGoal.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "cora_msgs/action/detail/pose_goal__functions.h"
#include "cora_msgs/action/detail/pose_goal__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace cora_msgs
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _PoseGoal_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PoseGoal_Goal_type_support_ids_t;

static const _PoseGoal_Goal_type_support_ids_t _PoseGoal_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _PoseGoal_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PoseGoal_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PoseGoal_Goal_type_support_symbol_names_t _PoseGoal_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, cora_msgs, action, PoseGoal_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, cora_msgs, action, PoseGoal_Goal)),
  }
};

typedef struct _PoseGoal_Goal_type_support_data_t
{
  void * data[2];
} _PoseGoal_Goal_type_support_data_t;

static _PoseGoal_Goal_type_support_data_t _PoseGoal_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PoseGoal_Goal_message_typesupport_map = {
  2,
  "cora_msgs",
  &_PoseGoal_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_PoseGoal_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_PoseGoal_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PoseGoal_Goal_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PoseGoal_Goal_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &cora_msgs__action__PoseGoal_Goal__get_type_hash,
  &cora_msgs__action__PoseGoal_Goal__get_type_description,
  &cora_msgs__action__PoseGoal_Goal__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace cora_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<cora_msgs::action::PoseGoal_Goal>()
{
  return &::cora_msgs::action::rosidl_typesupport_cpp::PoseGoal_Goal_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, cora_msgs, action, PoseGoal_Goal)() {
  return get_message_type_support_handle<cora_msgs::action::PoseGoal_Goal>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "cora_msgs/action/detail/pose_goal__functions.h"
// already included above
// #include "cora_msgs/action/detail/pose_goal__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace cora_msgs
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _PoseGoal_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PoseGoal_Result_type_support_ids_t;

static const _PoseGoal_Result_type_support_ids_t _PoseGoal_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _PoseGoal_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PoseGoal_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PoseGoal_Result_type_support_symbol_names_t _PoseGoal_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, cora_msgs, action, PoseGoal_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, cora_msgs, action, PoseGoal_Result)),
  }
};

typedef struct _PoseGoal_Result_type_support_data_t
{
  void * data[2];
} _PoseGoal_Result_type_support_data_t;

static _PoseGoal_Result_type_support_data_t _PoseGoal_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PoseGoal_Result_message_typesupport_map = {
  2,
  "cora_msgs",
  &_PoseGoal_Result_message_typesupport_ids.typesupport_identifier[0],
  &_PoseGoal_Result_message_typesupport_symbol_names.symbol_name[0],
  &_PoseGoal_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PoseGoal_Result_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PoseGoal_Result_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &cora_msgs__action__PoseGoal_Result__get_type_hash,
  &cora_msgs__action__PoseGoal_Result__get_type_description,
  &cora_msgs__action__PoseGoal_Result__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace cora_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<cora_msgs::action::PoseGoal_Result>()
{
  return &::cora_msgs::action::rosidl_typesupport_cpp::PoseGoal_Result_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, cora_msgs, action, PoseGoal_Result)() {
  return get_message_type_support_handle<cora_msgs::action::PoseGoal_Result>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "cora_msgs/action/detail/pose_goal__functions.h"
// already included above
// #include "cora_msgs/action/detail/pose_goal__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace cora_msgs
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _PoseGoal_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PoseGoal_Feedback_type_support_ids_t;

static const _PoseGoal_Feedback_type_support_ids_t _PoseGoal_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _PoseGoal_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PoseGoal_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PoseGoal_Feedback_type_support_symbol_names_t _PoseGoal_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, cora_msgs, action, PoseGoal_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, cora_msgs, action, PoseGoal_Feedback)),
  }
};

typedef struct _PoseGoal_Feedback_type_support_data_t
{
  void * data[2];
} _PoseGoal_Feedback_type_support_data_t;

static _PoseGoal_Feedback_type_support_data_t _PoseGoal_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PoseGoal_Feedback_message_typesupport_map = {
  2,
  "cora_msgs",
  &_PoseGoal_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_PoseGoal_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_PoseGoal_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PoseGoal_Feedback_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PoseGoal_Feedback_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &cora_msgs__action__PoseGoal_Feedback__get_type_hash,
  &cora_msgs__action__PoseGoal_Feedback__get_type_description,
  &cora_msgs__action__PoseGoal_Feedback__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace cora_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<cora_msgs::action::PoseGoal_Feedback>()
{
  return &::cora_msgs::action::rosidl_typesupport_cpp::PoseGoal_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, cora_msgs, action, PoseGoal_Feedback)() {
  return get_message_type_support_handle<cora_msgs::action::PoseGoal_Feedback>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "cora_msgs/action/detail/pose_goal__functions.h"
// already included above
// #include "cora_msgs/action/detail/pose_goal__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace cora_msgs
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _PoseGoal_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PoseGoal_SendGoal_Request_type_support_ids_t;

static const _PoseGoal_SendGoal_Request_type_support_ids_t _PoseGoal_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _PoseGoal_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PoseGoal_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PoseGoal_SendGoal_Request_type_support_symbol_names_t _PoseGoal_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, cora_msgs, action, PoseGoal_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, cora_msgs, action, PoseGoal_SendGoal_Request)),
  }
};

typedef struct _PoseGoal_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _PoseGoal_SendGoal_Request_type_support_data_t;

static _PoseGoal_SendGoal_Request_type_support_data_t _PoseGoal_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PoseGoal_SendGoal_Request_message_typesupport_map = {
  2,
  "cora_msgs",
  &_PoseGoal_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_PoseGoal_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_PoseGoal_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PoseGoal_SendGoal_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PoseGoal_SendGoal_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &cora_msgs__action__PoseGoal_SendGoal_Request__get_type_hash,
  &cora_msgs__action__PoseGoal_SendGoal_Request__get_type_description,
  &cora_msgs__action__PoseGoal_SendGoal_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace cora_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<cora_msgs::action::PoseGoal_SendGoal_Request>()
{
  return &::cora_msgs::action::rosidl_typesupport_cpp::PoseGoal_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, cora_msgs, action, PoseGoal_SendGoal_Request)() {
  return get_message_type_support_handle<cora_msgs::action::PoseGoal_SendGoal_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "cora_msgs/action/detail/pose_goal__functions.h"
// already included above
// #include "cora_msgs/action/detail/pose_goal__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace cora_msgs
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _PoseGoal_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PoseGoal_SendGoal_Response_type_support_ids_t;

static const _PoseGoal_SendGoal_Response_type_support_ids_t _PoseGoal_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _PoseGoal_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PoseGoal_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PoseGoal_SendGoal_Response_type_support_symbol_names_t _PoseGoal_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, cora_msgs, action, PoseGoal_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, cora_msgs, action, PoseGoal_SendGoal_Response)),
  }
};

typedef struct _PoseGoal_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _PoseGoal_SendGoal_Response_type_support_data_t;

static _PoseGoal_SendGoal_Response_type_support_data_t _PoseGoal_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PoseGoal_SendGoal_Response_message_typesupport_map = {
  2,
  "cora_msgs",
  &_PoseGoal_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_PoseGoal_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_PoseGoal_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PoseGoal_SendGoal_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PoseGoal_SendGoal_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &cora_msgs__action__PoseGoal_SendGoal_Response__get_type_hash,
  &cora_msgs__action__PoseGoal_SendGoal_Response__get_type_description,
  &cora_msgs__action__PoseGoal_SendGoal_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace cora_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<cora_msgs::action::PoseGoal_SendGoal_Response>()
{
  return &::cora_msgs::action::rosidl_typesupport_cpp::PoseGoal_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, cora_msgs, action, PoseGoal_SendGoal_Response)() {
  return get_message_type_support_handle<cora_msgs::action::PoseGoal_SendGoal_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "cora_msgs/action/detail/pose_goal__functions.h"
// already included above
// #include "cora_msgs/action/detail/pose_goal__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace cora_msgs
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _PoseGoal_SendGoal_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PoseGoal_SendGoal_Event_type_support_ids_t;

static const _PoseGoal_SendGoal_Event_type_support_ids_t _PoseGoal_SendGoal_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _PoseGoal_SendGoal_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PoseGoal_SendGoal_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PoseGoal_SendGoal_Event_type_support_symbol_names_t _PoseGoal_SendGoal_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, cora_msgs, action, PoseGoal_SendGoal_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, cora_msgs, action, PoseGoal_SendGoal_Event)),
  }
};

typedef struct _PoseGoal_SendGoal_Event_type_support_data_t
{
  void * data[2];
} _PoseGoal_SendGoal_Event_type_support_data_t;

static _PoseGoal_SendGoal_Event_type_support_data_t _PoseGoal_SendGoal_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PoseGoal_SendGoal_Event_message_typesupport_map = {
  2,
  "cora_msgs",
  &_PoseGoal_SendGoal_Event_message_typesupport_ids.typesupport_identifier[0],
  &_PoseGoal_SendGoal_Event_message_typesupport_symbol_names.symbol_name[0],
  &_PoseGoal_SendGoal_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PoseGoal_SendGoal_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PoseGoal_SendGoal_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &cora_msgs__action__PoseGoal_SendGoal_Event__get_type_hash,
  &cora_msgs__action__PoseGoal_SendGoal_Event__get_type_description,
  &cora_msgs__action__PoseGoal_SendGoal_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace cora_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<cora_msgs::action::PoseGoal_SendGoal_Event>()
{
  return &::cora_msgs::action::rosidl_typesupport_cpp::PoseGoal_SendGoal_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, cora_msgs, action, PoseGoal_SendGoal_Event)() {
  return get_message_type_support_handle<cora_msgs::action::PoseGoal_SendGoal_Event>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "cora_msgs/action/detail/pose_goal__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace cora_msgs
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _PoseGoal_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PoseGoal_SendGoal_type_support_ids_t;

static const _PoseGoal_SendGoal_type_support_ids_t _PoseGoal_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _PoseGoal_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PoseGoal_SendGoal_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PoseGoal_SendGoal_type_support_symbol_names_t _PoseGoal_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, cora_msgs, action, PoseGoal_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, cora_msgs, action, PoseGoal_SendGoal)),
  }
};

typedef struct _PoseGoal_SendGoal_type_support_data_t
{
  void * data[2];
} _PoseGoal_SendGoal_type_support_data_t;

static _PoseGoal_SendGoal_type_support_data_t _PoseGoal_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PoseGoal_SendGoal_service_typesupport_map = {
  2,
  "cora_msgs",
  &_PoseGoal_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_PoseGoal_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_PoseGoal_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t PoseGoal_SendGoal_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PoseGoal_SendGoal_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<cora_msgs::action::PoseGoal_SendGoal_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<cora_msgs::action::PoseGoal_SendGoal_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<cora_msgs::action::PoseGoal_SendGoal_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<cora_msgs::action::PoseGoal_SendGoal>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<cora_msgs::action::PoseGoal_SendGoal>,
  &cora_msgs__action__PoseGoal_SendGoal__get_type_hash,
  &cora_msgs__action__PoseGoal_SendGoal__get_type_description,
  &cora_msgs__action__PoseGoal_SendGoal__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace cora_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<cora_msgs::action::PoseGoal_SendGoal>()
{
  return &::cora_msgs::action::rosidl_typesupport_cpp::PoseGoal_SendGoal_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, cora_msgs, action, PoseGoal_SendGoal)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<cora_msgs::action::PoseGoal_SendGoal>();
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "cora_msgs/action/detail/pose_goal__functions.h"
// already included above
// #include "cora_msgs/action/detail/pose_goal__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace cora_msgs
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _PoseGoal_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PoseGoal_GetResult_Request_type_support_ids_t;

static const _PoseGoal_GetResult_Request_type_support_ids_t _PoseGoal_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _PoseGoal_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PoseGoal_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PoseGoal_GetResult_Request_type_support_symbol_names_t _PoseGoal_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, cora_msgs, action, PoseGoal_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, cora_msgs, action, PoseGoal_GetResult_Request)),
  }
};

typedef struct _PoseGoal_GetResult_Request_type_support_data_t
{
  void * data[2];
} _PoseGoal_GetResult_Request_type_support_data_t;

static _PoseGoal_GetResult_Request_type_support_data_t _PoseGoal_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PoseGoal_GetResult_Request_message_typesupport_map = {
  2,
  "cora_msgs",
  &_PoseGoal_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_PoseGoal_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_PoseGoal_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PoseGoal_GetResult_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PoseGoal_GetResult_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &cora_msgs__action__PoseGoal_GetResult_Request__get_type_hash,
  &cora_msgs__action__PoseGoal_GetResult_Request__get_type_description,
  &cora_msgs__action__PoseGoal_GetResult_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace cora_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<cora_msgs::action::PoseGoal_GetResult_Request>()
{
  return &::cora_msgs::action::rosidl_typesupport_cpp::PoseGoal_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, cora_msgs, action, PoseGoal_GetResult_Request)() {
  return get_message_type_support_handle<cora_msgs::action::PoseGoal_GetResult_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "cora_msgs/action/detail/pose_goal__functions.h"
// already included above
// #include "cora_msgs/action/detail/pose_goal__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace cora_msgs
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _PoseGoal_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PoseGoal_GetResult_Response_type_support_ids_t;

static const _PoseGoal_GetResult_Response_type_support_ids_t _PoseGoal_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _PoseGoal_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PoseGoal_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PoseGoal_GetResult_Response_type_support_symbol_names_t _PoseGoal_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, cora_msgs, action, PoseGoal_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, cora_msgs, action, PoseGoal_GetResult_Response)),
  }
};

typedef struct _PoseGoal_GetResult_Response_type_support_data_t
{
  void * data[2];
} _PoseGoal_GetResult_Response_type_support_data_t;

static _PoseGoal_GetResult_Response_type_support_data_t _PoseGoal_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PoseGoal_GetResult_Response_message_typesupport_map = {
  2,
  "cora_msgs",
  &_PoseGoal_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_PoseGoal_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_PoseGoal_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PoseGoal_GetResult_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PoseGoal_GetResult_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &cora_msgs__action__PoseGoal_GetResult_Response__get_type_hash,
  &cora_msgs__action__PoseGoal_GetResult_Response__get_type_description,
  &cora_msgs__action__PoseGoal_GetResult_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace cora_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<cora_msgs::action::PoseGoal_GetResult_Response>()
{
  return &::cora_msgs::action::rosidl_typesupport_cpp::PoseGoal_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, cora_msgs, action, PoseGoal_GetResult_Response)() {
  return get_message_type_support_handle<cora_msgs::action::PoseGoal_GetResult_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "cora_msgs/action/detail/pose_goal__functions.h"
// already included above
// #include "cora_msgs/action/detail/pose_goal__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace cora_msgs
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _PoseGoal_GetResult_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PoseGoal_GetResult_Event_type_support_ids_t;

static const _PoseGoal_GetResult_Event_type_support_ids_t _PoseGoal_GetResult_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _PoseGoal_GetResult_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PoseGoal_GetResult_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PoseGoal_GetResult_Event_type_support_symbol_names_t _PoseGoal_GetResult_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, cora_msgs, action, PoseGoal_GetResult_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, cora_msgs, action, PoseGoal_GetResult_Event)),
  }
};

typedef struct _PoseGoal_GetResult_Event_type_support_data_t
{
  void * data[2];
} _PoseGoal_GetResult_Event_type_support_data_t;

static _PoseGoal_GetResult_Event_type_support_data_t _PoseGoal_GetResult_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PoseGoal_GetResult_Event_message_typesupport_map = {
  2,
  "cora_msgs",
  &_PoseGoal_GetResult_Event_message_typesupport_ids.typesupport_identifier[0],
  &_PoseGoal_GetResult_Event_message_typesupport_symbol_names.symbol_name[0],
  &_PoseGoal_GetResult_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PoseGoal_GetResult_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PoseGoal_GetResult_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &cora_msgs__action__PoseGoal_GetResult_Event__get_type_hash,
  &cora_msgs__action__PoseGoal_GetResult_Event__get_type_description,
  &cora_msgs__action__PoseGoal_GetResult_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace cora_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<cora_msgs::action::PoseGoal_GetResult_Event>()
{
  return &::cora_msgs::action::rosidl_typesupport_cpp::PoseGoal_GetResult_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, cora_msgs, action, PoseGoal_GetResult_Event)() {
  return get_message_type_support_handle<cora_msgs::action::PoseGoal_GetResult_Event>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "cora_msgs/action/detail/pose_goal__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace cora_msgs
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _PoseGoal_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PoseGoal_GetResult_type_support_ids_t;

static const _PoseGoal_GetResult_type_support_ids_t _PoseGoal_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _PoseGoal_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PoseGoal_GetResult_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PoseGoal_GetResult_type_support_symbol_names_t _PoseGoal_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, cora_msgs, action, PoseGoal_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, cora_msgs, action, PoseGoal_GetResult)),
  }
};

typedef struct _PoseGoal_GetResult_type_support_data_t
{
  void * data[2];
} _PoseGoal_GetResult_type_support_data_t;

static _PoseGoal_GetResult_type_support_data_t _PoseGoal_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PoseGoal_GetResult_service_typesupport_map = {
  2,
  "cora_msgs",
  &_PoseGoal_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_PoseGoal_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_PoseGoal_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t PoseGoal_GetResult_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PoseGoal_GetResult_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<cora_msgs::action::PoseGoal_GetResult_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<cora_msgs::action::PoseGoal_GetResult_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<cora_msgs::action::PoseGoal_GetResult_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<cora_msgs::action::PoseGoal_GetResult>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<cora_msgs::action::PoseGoal_GetResult>,
  &cora_msgs__action__PoseGoal_GetResult__get_type_hash,
  &cora_msgs__action__PoseGoal_GetResult__get_type_description,
  &cora_msgs__action__PoseGoal_GetResult__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace cora_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<cora_msgs::action::PoseGoal_GetResult>()
{
  return &::cora_msgs::action::rosidl_typesupport_cpp::PoseGoal_GetResult_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, cora_msgs, action, PoseGoal_GetResult)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<cora_msgs::action::PoseGoal_GetResult>();
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "cora_msgs/action/detail/pose_goal__functions.h"
// already included above
// #include "cora_msgs/action/detail/pose_goal__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace cora_msgs
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _PoseGoal_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PoseGoal_FeedbackMessage_type_support_ids_t;

static const _PoseGoal_FeedbackMessage_type_support_ids_t _PoseGoal_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _PoseGoal_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PoseGoal_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PoseGoal_FeedbackMessage_type_support_symbol_names_t _PoseGoal_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, cora_msgs, action, PoseGoal_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, cora_msgs, action, PoseGoal_FeedbackMessage)),
  }
};

typedef struct _PoseGoal_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _PoseGoal_FeedbackMessage_type_support_data_t;

static _PoseGoal_FeedbackMessage_type_support_data_t _PoseGoal_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PoseGoal_FeedbackMessage_message_typesupport_map = {
  2,
  "cora_msgs",
  &_PoseGoal_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_PoseGoal_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_PoseGoal_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PoseGoal_FeedbackMessage_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PoseGoal_FeedbackMessage_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &cora_msgs__action__PoseGoal_FeedbackMessage__get_type_hash,
  &cora_msgs__action__PoseGoal_FeedbackMessage__get_type_description,
  &cora_msgs__action__PoseGoal_FeedbackMessage__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace cora_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<cora_msgs::action::PoseGoal_FeedbackMessage>()
{
  return &::cora_msgs::action::rosidl_typesupport_cpp::PoseGoal_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, cora_msgs, action, PoseGoal_FeedbackMessage)() {
  return get_message_type_support_handle<cora_msgs::action::PoseGoal_FeedbackMessage>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

#include "action_msgs/msg/goal_status_array.hpp"
#include "action_msgs/srv/cancel_goal.hpp"
// already included above
// #include "cora_msgs/action/detail/pose_goal__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_typesupport_cpp/action_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"

namespace cora_msgs
{

namespace action
{

namespace rosidl_typesupport_cpp
{

static rosidl_action_type_support_t PoseGoal_action_type_support_handle = {
  NULL, NULL, NULL, NULL, NULL,
  &cora_msgs__action__PoseGoal__get_type_hash,
  &cora_msgs__action__PoseGoal__get_type_description,
  &cora_msgs__action__PoseGoal__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace cora_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_action_type_support_t *
get_action_type_support_handle<cora_msgs::action::PoseGoal>()
{
  using ::cora_msgs::action::rosidl_typesupport_cpp::PoseGoal_action_type_support_handle;
  // Thread-safe by always writing the same values to the static struct
  PoseGoal_action_type_support_handle.goal_service_type_support = get_service_type_support_handle<::cora_msgs::action::PoseGoal::Impl::SendGoalService>();
  PoseGoal_action_type_support_handle.result_service_type_support = get_service_type_support_handle<::cora_msgs::action::PoseGoal::Impl::GetResultService>();
  PoseGoal_action_type_support_handle.cancel_service_type_support = get_service_type_support_handle<::cora_msgs::action::PoseGoal::Impl::CancelGoalService>();
  PoseGoal_action_type_support_handle.feedback_message_type_support = get_message_type_support_handle<::cora_msgs::action::PoseGoal::Impl::FeedbackMessage>();
  PoseGoal_action_type_support_handle.status_message_type_support = get_message_type_support_handle<::cora_msgs::action::PoseGoal::Impl::GoalStatusMessage>();
  return &PoseGoal_action_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_action_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__ACTION_SYMBOL_NAME(rosidl_typesupport_cpp, cora_msgs, action, PoseGoal)() {
  return ::rosidl_typesupport_cpp::get_action_type_support_handle<cora_msgs::action::PoseGoal>();
}

#ifdef __cplusplus
}
#endif
