// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cora_msgs:action/PoseGoal.idl
// generated code does not contain a copyright notice
#include "cora_msgs/action/detail/pose_goal__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `pose_goal`
#include "cora_msgs/msg/detail/targeted_pose_stamped__functions.h"
// Member `joint_goal`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `predefined_pose`
// Member `space`
// Member `interface_type`
#include "rosidl_runtime_c/string_functions.h"

bool
cora_msgs__action__PoseGoal_Goal__init(cora_msgs__action__PoseGoal_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // pose_goal
  if (!cora_msgs__msg__TargetedPoseStamped__init(&msg->pose_goal)) {
    cora_msgs__action__PoseGoal_Goal__fini(msg);
    return false;
  }
  // joint_goal
  if (!rosidl_runtime_c__double__Sequence__init(&msg->joint_goal, 0)) {
    cora_msgs__action__PoseGoal_Goal__fini(msg);
    return false;
  }
  // predefined_pose
  if (!rosidl_runtime_c__String__init(&msg->predefined_pose)) {
    cora_msgs__action__PoseGoal_Goal__fini(msg);
    return false;
  }
  // space
  if (!rosidl_runtime_c__String__init(&msg->space)) {
    cora_msgs__action__PoseGoal_Goal__fini(msg);
    return false;
  }
  // interface_type
  if (!rosidl_runtime_c__String__init(&msg->interface_type)) {
    cora_msgs__action__PoseGoal_Goal__fini(msg);
    return false;
  }
  return true;
}

void
cora_msgs__action__PoseGoal_Goal__fini(cora_msgs__action__PoseGoal_Goal * msg)
{
  if (!msg) {
    return;
  }
  // pose_goal
  cora_msgs__msg__TargetedPoseStamped__fini(&msg->pose_goal);
  // joint_goal
  rosidl_runtime_c__double__Sequence__fini(&msg->joint_goal);
  // predefined_pose
  rosidl_runtime_c__String__fini(&msg->predefined_pose);
  // space
  rosidl_runtime_c__String__fini(&msg->space);
  // interface_type
  rosidl_runtime_c__String__fini(&msg->interface_type);
}

bool
cora_msgs__action__PoseGoal_Goal__are_equal(const cora_msgs__action__PoseGoal_Goal * lhs, const cora_msgs__action__PoseGoal_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // pose_goal
  if (!cora_msgs__msg__TargetedPoseStamped__are_equal(
      &(lhs->pose_goal), &(rhs->pose_goal)))
  {
    return false;
  }
  // joint_goal
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->joint_goal), &(rhs->joint_goal)))
  {
    return false;
  }
  // predefined_pose
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->predefined_pose), &(rhs->predefined_pose)))
  {
    return false;
  }
  // space
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->space), &(rhs->space)))
  {
    return false;
  }
  // interface_type
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->interface_type), &(rhs->interface_type)))
  {
    return false;
  }
  return true;
}

bool
cora_msgs__action__PoseGoal_Goal__copy(
  const cora_msgs__action__PoseGoal_Goal * input,
  cora_msgs__action__PoseGoal_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // pose_goal
  if (!cora_msgs__msg__TargetedPoseStamped__copy(
      &(input->pose_goal), &(output->pose_goal)))
  {
    return false;
  }
  // joint_goal
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->joint_goal), &(output->joint_goal)))
  {
    return false;
  }
  // predefined_pose
  if (!rosidl_runtime_c__String__copy(
      &(input->predefined_pose), &(output->predefined_pose)))
  {
    return false;
  }
  // space
  if (!rosidl_runtime_c__String__copy(
      &(input->space), &(output->space)))
  {
    return false;
  }
  // interface_type
  if (!rosidl_runtime_c__String__copy(
      &(input->interface_type), &(output->interface_type)))
  {
    return false;
  }
  return true;
}

cora_msgs__action__PoseGoal_Goal *
cora_msgs__action__PoseGoal_Goal__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cora_msgs__action__PoseGoal_Goal * msg = (cora_msgs__action__PoseGoal_Goal *)allocator.allocate(sizeof(cora_msgs__action__PoseGoal_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cora_msgs__action__PoseGoal_Goal));
  bool success = cora_msgs__action__PoseGoal_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cora_msgs__action__PoseGoal_Goal__destroy(cora_msgs__action__PoseGoal_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cora_msgs__action__PoseGoal_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cora_msgs__action__PoseGoal_Goal__Sequence__init(cora_msgs__action__PoseGoal_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cora_msgs__action__PoseGoal_Goal * data = NULL;

  if (size) {
    data = (cora_msgs__action__PoseGoal_Goal *)allocator.zero_allocate(size, sizeof(cora_msgs__action__PoseGoal_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cora_msgs__action__PoseGoal_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cora_msgs__action__PoseGoal_Goal__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
cora_msgs__action__PoseGoal_Goal__Sequence__fini(cora_msgs__action__PoseGoal_Goal__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      cora_msgs__action__PoseGoal_Goal__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

cora_msgs__action__PoseGoal_Goal__Sequence *
cora_msgs__action__PoseGoal_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cora_msgs__action__PoseGoal_Goal__Sequence * array = (cora_msgs__action__PoseGoal_Goal__Sequence *)allocator.allocate(sizeof(cora_msgs__action__PoseGoal_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cora_msgs__action__PoseGoal_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cora_msgs__action__PoseGoal_Goal__Sequence__destroy(cora_msgs__action__PoseGoal_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cora_msgs__action__PoseGoal_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cora_msgs__action__PoseGoal_Goal__Sequence__are_equal(const cora_msgs__action__PoseGoal_Goal__Sequence * lhs, const cora_msgs__action__PoseGoal_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cora_msgs__action__PoseGoal_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cora_msgs__action__PoseGoal_Goal__Sequence__copy(
  const cora_msgs__action__PoseGoal_Goal__Sequence * input,
  cora_msgs__action__PoseGoal_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cora_msgs__action__PoseGoal_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cora_msgs__action__PoseGoal_Goal * data =
      (cora_msgs__action__PoseGoal_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cora_msgs__action__PoseGoal_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cora_msgs__action__PoseGoal_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cora_msgs__action__PoseGoal_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `pose_result`
#include "geometry_msgs/msg/detail/pose_stamped__functions.h"
// Member `joint_result`
// already included above
// #include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `status_result`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
cora_msgs__action__PoseGoal_Result__init(cora_msgs__action__PoseGoal_Result * msg)
{
  if (!msg) {
    return false;
  }
  // pose_result
  if (!geometry_msgs__msg__PoseStamped__init(&msg->pose_result)) {
    cora_msgs__action__PoseGoal_Result__fini(msg);
    return false;
  }
  // joint_result
  if (!rosidl_runtime_c__double__Sequence__init(&msg->joint_result, 0)) {
    cora_msgs__action__PoseGoal_Result__fini(msg);
    return false;
  }
  // status_result
  if (!rosidl_runtime_c__String__init(&msg->status_result)) {
    cora_msgs__action__PoseGoal_Result__fini(msg);
    return false;
  }
  // success
  return true;
}

void
cora_msgs__action__PoseGoal_Result__fini(cora_msgs__action__PoseGoal_Result * msg)
{
  if (!msg) {
    return;
  }
  // pose_result
  geometry_msgs__msg__PoseStamped__fini(&msg->pose_result);
  // joint_result
  rosidl_runtime_c__double__Sequence__fini(&msg->joint_result);
  // status_result
  rosidl_runtime_c__String__fini(&msg->status_result);
  // success
}

bool
cora_msgs__action__PoseGoal_Result__are_equal(const cora_msgs__action__PoseGoal_Result * lhs, const cora_msgs__action__PoseGoal_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // pose_result
  if (!geometry_msgs__msg__PoseStamped__are_equal(
      &(lhs->pose_result), &(rhs->pose_result)))
  {
    return false;
  }
  // joint_result
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->joint_result), &(rhs->joint_result)))
  {
    return false;
  }
  // status_result
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->status_result), &(rhs->status_result)))
  {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  return true;
}

bool
cora_msgs__action__PoseGoal_Result__copy(
  const cora_msgs__action__PoseGoal_Result * input,
  cora_msgs__action__PoseGoal_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // pose_result
  if (!geometry_msgs__msg__PoseStamped__copy(
      &(input->pose_result), &(output->pose_result)))
  {
    return false;
  }
  // joint_result
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->joint_result), &(output->joint_result)))
  {
    return false;
  }
  // status_result
  if (!rosidl_runtime_c__String__copy(
      &(input->status_result), &(output->status_result)))
  {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

cora_msgs__action__PoseGoal_Result *
cora_msgs__action__PoseGoal_Result__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cora_msgs__action__PoseGoal_Result * msg = (cora_msgs__action__PoseGoal_Result *)allocator.allocate(sizeof(cora_msgs__action__PoseGoal_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cora_msgs__action__PoseGoal_Result));
  bool success = cora_msgs__action__PoseGoal_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cora_msgs__action__PoseGoal_Result__destroy(cora_msgs__action__PoseGoal_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cora_msgs__action__PoseGoal_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cora_msgs__action__PoseGoal_Result__Sequence__init(cora_msgs__action__PoseGoal_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cora_msgs__action__PoseGoal_Result * data = NULL;

  if (size) {
    data = (cora_msgs__action__PoseGoal_Result *)allocator.zero_allocate(size, sizeof(cora_msgs__action__PoseGoal_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cora_msgs__action__PoseGoal_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cora_msgs__action__PoseGoal_Result__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
cora_msgs__action__PoseGoal_Result__Sequence__fini(cora_msgs__action__PoseGoal_Result__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      cora_msgs__action__PoseGoal_Result__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

cora_msgs__action__PoseGoal_Result__Sequence *
cora_msgs__action__PoseGoal_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cora_msgs__action__PoseGoal_Result__Sequence * array = (cora_msgs__action__PoseGoal_Result__Sequence *)allocator.allocate(sizeof(cora_msgs__action__PoseGoal_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cora_msgs__action__PoseGoal_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cora_msgs__action__PoseGoal_Result__Sequence__destroy(cora_msgs__action__PoseGoal_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cora_msgs__action__PoseGoal_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cora_msgs__action__PoseGoal_Result__Sequence__are_equal(const cora_msgs__action__PoseGoal_Result__Sequence * lhs, const cora_msgs__action__PoseGoal_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cora_msgs__action__PoseGoal_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cora_msgs__action__PoseGoal_Result__Sequence__copy(
  const cora_msgs__action__PoseGoal_Result__Sequence * input,
  cora_msgs__action__PoseGoal_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cora_msgs__action__PoseGoal_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cora_msgs__action__PoseGoal_Result * data =
      (cora_msgs__action__PoseGoal_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cora_msgs__action__PoseGoal_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cora_msgs__action__PoseGoal_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cora_msgs__action__PoseGoal_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `pose_feedback`
// already included above
// #include "geometry_msgs/msg/detail/pose_stamped__functions.h"
// Member `status`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
cora_msgs__action__PoseGoal_Feedback__init(cora_msgs__action__PoseGoal_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // pose_feedback
  if (!geometry_msgs__msg__PoseStamped__init(&msg->pose_feedback)) {
    cora_msgs__action__PoseGoal_Feedback__fini(msg);
    return false;
  }
  // status
  if (!rosidl_runtime_c__String__init(&msg->status)) {
    cora_msgs__action__PoseGoal_Feedback__fini(msg);
    return false;
  }
  return true;
}

void
cora_msgs__action__PoseGoal_Feedback__fini(cora_msgs__action__PoseGoal_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // pose_feedback
  geometry_msgs__msg__PoseStamped__fini(&msg->pose_feedback);
  // status
  rosidl_runtime_c__String__fini(&msg->status);
}

bool
cora_msgs__action__PoseGoal_Feedback__are_equal(const cora_msgs__action__PoseGoal_Feedback * lhs, const cora_msgs__action__PoseGoal_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // pose_feedback
  if (!geometry_msgs__msg__PoseStamped__are_equal(
      &(lhs->pose_feedback), &(rhs->pose_feedback)))
  {
    return false;
  }
  // status
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->status), &(rhs->status)))
  {
    return false;
  }
  return true;
}

bool
cora_msgs__action__PoseGoal_Feedback__copy(
  const cora_msgs__action__PoseGoal_Feedback * input,
  cora_msgs__action__PoseGoal_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // pose_feedback
  if (!geometry_msgs__msg__PoseStamped__copy(
      &(input->pose_feedback), &(output->pose_feedback)))
  {
    return false;
  }
  // status
  if (!rosidl_runtime_c__String__copy(
      &(input->status), &(output->status)))
  {
    return false;
  }
  return true;
}

cora_msgs__action__PoseGoal_Feedback *
cora_msgs__action__PoseGoal_Feedback__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cora_msgs__action__PoseGoal_Feedback * msg = (cora_msgs__action__PoseGoal_Feedback *)allocator.allocate(sizeof(cora_msgs__action__PoseGoal_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cora_msgs__action__PoseGoal_Feedback));
  bool success = cora_msgs__action__PoseGoal_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cora_msgs__action__PoseGoal_Feedback__destroy(cora_msgs__action__PoseGoal_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cora_msgs__action__PoseGoal_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cora_msgs__action__PoseGoal_Feedback__Sequence__init(cora_msgs__action__PoseGoal_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cora_msgs__action__PoseGoal_Feedback * data = NULL;

  if (size) {
    data = (cora_msgs__action__PoseGoal_Feedback *)allocator.zero_allocate(size, sizeof(cora_msgs__action__PoseGoal_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cora_msgs__action__PoseGoal_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cora_msgs__action__PoseGoal_Feedback__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
cora_msgs__action__PoseGoal_Feedback__Sequence__fini(cora_msgs__action__PoseGoal_Feedback__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      cora_msgs__action__PoseGoal_Feedback__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

cora_msgs__action__PoseGoal_Feedback__Sequence *
cora_msgs__action__PoseGoal_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cora_msgs__action__PoseGoal_Feedback__Sequence * array = (cora_msgs__action__PoseGoal_Feedback__Sequence *)allocator.allocate(sizeof(cora_msgs__action__PoseGoal_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cora_msgs__action__PoseGoal_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cora_msgs__action__PoseGoal_Feedback__Sequence__destroy(cora_msgs__action__PoseGoal_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cora_msgs__action__PoseGoal_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cora_msgs__action__PoseGoal_Feedback__Sequence__are_equal(const cora_msgs__action__PoseGoal_Feedback__Sequence * lhs, const cora_msgs__action__PoseGoal_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cora_msgs__action__PoseGoal_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cora_msgs__action__PoseGoal_Feedback__Sequence__copy(
  const cora_msgs__action__PoseGoal_Feedback__Sequence * input,
  cora_msgs__action__PoseGoal_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cora_msgs__action__PoseGoal_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cora_msgs__action__PoseGoal_Feedback * data =
      (cora_msgs__action__PoseGoal_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cora_msgs__action__PoseGoal_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cora_msgs__action__PoseGoal_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cora_msgs__action__PoseGoal_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "cora_msgs/action/detail/pose_goal__functions.h"

bool
cora_msgs__action__PoseGoal_SendGoal_Request__init(cora_msgs__action__PoseGoal_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    cora_msgs__action__PoseGoal_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!cora_msgs__action__PoseGoal_Goal__init(&msg->goal)) {
    cora_msgs__action__PoseGoal_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
cora_msgs__action__PoseGoal_SendGoal_Request__fini(cora_msgs__action__PoseGoal_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  cora_msgs__action__PoseGoal_Goal__fini(&msg->goal);
}

bool
cora_msgs__action__PoseGoal_SendGoal_Request__are_equal(const cora_msgs__action__PoseGoal_SendGoal_Request * lhs, const cora_msgs__action__PoseGoal_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!cora_msgs__action__PoseGoal_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
cora_msgs__action__PoseGoal_SendGoal_Request__copy(
  const cora_msgs__action__PoseGoal_SendGoal_Request * input,
  cora_msgs__action__PoseGoal_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!cora_msgs__action__PoseGoal_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

cora_msgs__action__PoseGoal_SendGoal_Request *
cora_msgs__action__PoseGoal_SendGoal_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cora_msgs__action__PoseGoal_SendGoal_Request * msg = (cora_msgs__action__PoseGoal_SendGoal_Request *)allocator.allocate(sizeof(cora_msgs__action__PoseGoal_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cora_msgs__action__PoseGoal_SendGoal_Request));
  bool success = cora_msgs__action__PoseGoal_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cora_msgs__action__PoseGoal_SendGoal_Request__destroy(cora_msgs__action__PoseGoal_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cora_msgs__action__PoseGoal_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cora_msgs__action__PoseGoal_SendGoal_Request__Sequence__init(cora_msgs__action__PoseGoal_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cora_msgs__action__PoseGoal_SendGoal_Request * data = NULL;

  if (size) {
    data = (cora_msgs__action__PoseGoal_SendGoal_Request *)allocator.zero_allocate(size, sizeof(cora_msgs__action__PoseGoal_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cora_msgs__action__PoseGoal_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cora_msgs__action__PoseGoal_SendGoal_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
cora_msgs__action__PoseGoal_SendGoal_Request__Sequence__fini(cora_msgs__action__PoseGoal_SendGoal_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      cora_msgs__action__PoseGoal_SendGoal_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

cora_msgs__action__PoseGoal_SendGoal_Request__Sequence *
cora_msgs__action__PoseGoal_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cora_msgs__action__PoseGoal_SendGoal_Request__Sequence * array = (cora_msgs__action__PoseGoal_SendGoal_Request__Sequence *)allocator.allocate(sizeof(cora_msgs__action__PoseGoal_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cora_msgs__action__PoseGoal_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cora_msgs__action__PoseGoal_SendGoal_Request__Sequence__destroy(cora_msgs__action__PoseGoal_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cora_msgs__action__PoseGoal_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cora_msgs__action__PoseGoal_SendGoal_Request__Sequence__are_equal(const cora_msgs__action__PoseGoal_SendGoal_Request__Sequence * lhs, const cora_msgs__action__PoseGoal_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cora_msgs__action__PoseGoal_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cora_msgs__action__PoseGoal_SendGoal_Request__Sequence__copy(
  const cora_msgs__action__PoseGoal_SendGoal_Request__Sequence * input,
  cora_msgs__action__PoseGoal_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cora_msgs__action__PoseGoal_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cora_msgs__action__PoseGoal_SendGoal_Request * data =
      (cora_msgs__action__PoseGoal_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cora_msgs__action__PoseGoal_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cora_msgs__action__PoseGoal_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cora_msgs__action__PoseGoal_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
cora_msgs__action__PoseGoal_SendGoal_Response__init(cora_msgs__action__PoseGoal_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    cora_msgs__action__PoseGoal_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
cora_msgs__action__PoseGoal_SendGoal_Response__fini(cora_msgs__action__PoseGoal_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
cora_msgs__action__PoseGoal_SendGoal_Response__are_equal(const cora_msgs__action__PoseGoal_SendGoal_Response * lhs, const cora_msgs__action__PoseGoal_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
cora_msgs__action__PoseGoal_SendGoal_Response__copy(
  const cora_msgs__action__PoseGoal_SendGoal_Response * input,
  cora_msgs__action__PoseGoal_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

cora_msgs__action__PoseGoal_SendGoal_Response *
cora_msgs__action__PoseGoal_SendGoal_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cora_msgs__action__PoseGoal_SendGoal_Response * msg = (cora_msgs__action__PoseGoal_SendGoal_Response *)allocator.allocate(sizeof(cora_msgs__action__PoseGoal_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cora_msgs__action__PoseGoal_SendGoal_Response));
  bool success = cora_msgs__action__PoseGoal_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cora_msgs__action__PoseGoal_SendGoal_Response__destroy(cora_msgs__action__PoseGoal_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cora_msgs__action__PoseGoal_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cora_msgs__action__PoseGoal_SendGoal_Response__Sequence__init(cora_msgs__action__PoseGoal_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cora_msgs__action__PoseGoal_SendGoal_Response * data = NULL;

  if (size) {
    data = (cora_msgs__action__PoseGoal_SendGoal_Response *)allocator.zero_allocate(size, sizeof(cora_msgs__action__PoseGoal_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cora_msgs__action__PoseGoal_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cora_msgs__action__PoseGoal_SendGoal_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
cora_msgs__action__PoseGoal_SendGoal_Response__Sequence__fini(cora_msgs__action__PoseGoal_SendGoal_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      cora_msgs__action__PoseGoal_SendGoal_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

cora_msgs__action__PoseGoal_SendGoal_Response__Sequence *
cora_msgs__action__PoseGoal_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cora_msgs__action__PoseGoal_SendGoal_Response__Sequence * array = (cora_msgs__action__PoseGoal_SendGoal_Response__Sequence *)allocator.allocate(sizeof(cora_msgs__action__PoseGoal_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cora_msgs__action__PoseGoal_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cora_msgs__action__PoseGoal_SendGoal_Response__Sequence__destroy(cora_msgs__action__PoseGoal_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cora_msgs__action__PoseGoal_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cora_msgs__action__PoseGoal_SendGoal_Response__Sequence__are_equal(const cora_msgs__action__PoseGoal_SendGoal_Response__Sequence * lhs, const cora_msgs__action__PoseGoal_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cora_msgs__action__PoseGoal_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cora_msgs__action__PoseGoal_SendGoal_Response__Sequence__copy(
  const cora_msgs__action__PoseGoal_SendGoal_Response__Sequence * input,
  cora_msgs__action__PoseGoal_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cora_msgs__action__PoseGoal_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cora_msgs__action__PoseGoal_SendGoal_Response * data =
      (cora_msgs__action__PoseGoal_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cora_msgs__action__PoseGoal_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cora_msgs__action__PoseGoal_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cora_msgs__action__PoseGoal_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "cora_msgs/action/detail/pose_goal__functions.h"

bool
cora_msgs__action__PoseGoal_SendGoal_Event__init(cora_msgs__action__PoseGoal_SendGoal_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    cora_msgs__action__PoseGoal_SendGoal_Event__fini(msg);
    return false;
  }
  // request
  if (!cora_msgs__action__PoseGoal_SendGoal_Request__Sequence__init(&msg->request, 0)) {
    cora_msgs__action__PoseGoal_SendGoal_Event__fini(msg);
    return false;
  }
  // response
  if (!cora_msgs__action__PoseGoal_SendGoal_Response__Sequence__init(&msg->response, 0)) {
    cora_msgs__action__PoseGoal_SendGoal_Event__fini(msg);
    return false;
  }
  return true;
}

void
cora_msgs__action__PoseGoal_SendGoal_Event__fini(cora_msgs__action__PoseGoal_SendGoal_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  cora_msgs__action__PoseGoal_SendGoal_Request__Sequence__fini(&msg->request);
  // response
  cora_msgs__action__PoseGoal_SendGoal_Response__Sequence__fini(&msg->response);
}

bool
cora_msgs__action__PoseGoal_SendGoal_Event__are_equal(const cora_msgs__action__PoseGoal_SendGoal_Event * lhs, const cora_msgs__action__PoseGoal_SendGoal_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!cora_msgs__action__PoseGoal_SendGoal_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!cora_msgs__action__PoseGoal_SendGoal_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
cora_msgs__action__PoseGoal_SendGoal_Event__copy(
  const cora_msgs__action__PoseGoal_SendGoal_Event * input,
  cora_msgs__action__PoseGoal_SendGoal_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!cora_msgs__action__PoseGoal_SendGoal_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!cora_msgs__action__PoseGoal_SendGoal_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

cora_msgs__action__PoseGoal_SendGoal_Event *
cora_msgs__action__PoseGoal_SendGoal_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cora_msgs__action__PoseGoal_SendGoal_Event * msg = (cora_msgs__action__PoseGoal_SendGoal_Event *)allocator.allocate(sizeof(cora_msgs__action__PoseGoal_SendGoal_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cora_msgs__action__PoseGoal_SendGoal_Event));
  bool success = cora_msgs__action__PoseGoal_SendGoal_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cora_msgs__action__PoseGoal_SendGoal_Event__destroy(cora_msgs__action__PoseGoal_SendGoal_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cora_msgs__action__PoseGoal_SendGoal_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cora_msgs__action__PoseGoal_SendGoal_Event__Sequence__init(cora_msgs__action__PoseGoal_SendGoal_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cora_msgs__action__PoseGoal_SendGoal_Event * data = NULL;

  if (size) {
    data = (cora_msgs__action__PoseGoal_SendGoal_Event *)allocator.zero_allocate(size, sizeof(cora_msgs__action__PoseGoal_SendGoal_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cora_msgs__action__PoseGoal_SendGoal_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cora_msgs__action__PoseGoal_SendGoal_Event__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
cora_msgs__action__PoseGoal_SendGoal_Event__Sequence__fini(cora_msgs__action__PoseGoal_SendGoal_Event__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      cora_msgs__action__PoseGoal_SendGoal_Event__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

cora_msgs__action__PoseGoal_SendGoal_Event__Sequence *
cora_msgs__action__PoseGoal_SendGoal_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cora_msgs__action__PoseGoal_SendGoal_Event__Sequence * array = (cora_msgs__action__PoseGoal_SendGoal_Event__Sequence *)allocator.allocate(sizeof(cora_msgs__action__PoseGoal_SendGoal_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cora_msgs__action__PoseGoal_SendGoal_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cora_msgs__action__PoseGoal_SendGoal_Event__Sequence__destroy(cora_msgs__action__PoseGoal_SendGoal_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cora_msgs__action__PoseGoal_SendGoal_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cora_msgs__action__PoseGoal_SendGoal_Event__Sequence__are_equal(const cora_msgs__action__PoseGoal_SendGoal_Event__Sequence * lhs, const cora_msgs__action__PoseGoal_SendGoal_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cora_msgs__action__PoseGoal_SendGoal_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cora_msgs__action__PoseGoal_SendGoal_Event__Sequence__copy(
  const cora_msgs__action__PoseGoal_SendGoal_Event__Sequence * input,
  cora_msgs__action__PoseGoal_SendGoal_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cora_msgs__action__PoseGoal_SendGoal_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cora_msgs__action__PoseGoal_SendGoal_Event * data =
      (cora_msgs__action__PoseGoal_SendGoal_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cora_msgs__action__PoseGoal_SendGoal_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cora_msgs__action__PoseGoal_SendGoal_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cora_msgs__action__PoseGoal_SendGoal_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
cora_msgs__action__PoseGoal_GetResult_Request__init(cora_msgs__action__PoseGoal_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    cora_msgs__action__PoseGoal_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
cora_msgs__action__PoseGoal_GetResult_Request__fini(cora_msgs__action__PoseGoal_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
cora_msgs__action__PoseGoal_GetResult_Request__are_equal(const cora_msgs__action__PoseGoal_GetResult_Request * lhs, const cora_msgs__action__PoseGoal_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
cora_msgs__action__PoseGoal_GetResult_Request__copy(
  const cora_msgs__action__PoseGoal_GetResult_Request * input,
  cora_msgs__action__PoseGoal_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

cora_msgs__action__PoseGoal_GetResult_Request *
cora_msgs__action__PoseGoal_GetResult_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cora_msgs__action__PoseGoal_GetResult_Request * msg = (cora_msgs__action__PoseGoal_GetResult_Request *)allocator.allocate(sizeof(cora_msgs__action__PoseGoal_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cora_msgs__action__PoseGoal_GetResult_Request));
  bool success = cora_msgs__action__PoseGoal_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cora_msgs__action__PoseGoal_GetResult_Request__destroy(cora_msgs__action__PoseGoal_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cora_msgs__action__PoseGoal_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cora_msgs__action__PoseGoal_GetResult_Request__Sequence__init(cora_msgs__action__PoseGoal_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cora_msgs__action__PoseGoal_GetResult_Request * data = NULL;

  if (size) {
    data = (cora_msgs__action__PoseGoal_GetResult_Request *)allocator.zero_allocate(size, sizeof(cora_msgs__action__PoseGoal_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cora_msgs__action__PoseGoal_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cora_msgs__action__PoseGoal_GetResult_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
cora_msgs__action__PoseGoal_GetResult_Request__Sequence__fini(cora_msgs__action__PoseGoal_GetResult_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      cora_msgs__action__PoseGoal_GetResult_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

cora_msgs__action__PoseGoal_GetResult_Request__Sequence *
cora_msgs__action__PoseGoal_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cora_msgs__action__PoseGoal_GetResult_Request__Sequence * array = (cora_msgs__action__PoseGoal_GetResult_Request__Sequence *)allocator.allocate(sizeof(cora_msgs__action__PoseGoal_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cora_msgs__action__PoseGoal_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cora_msgs__action__PoseGoal_GetResult_Request__Sequence__destroy(cora_msgs__action__PoseGoal_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cora_msgs__action__PoseGoal_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cora_msgs__action__PoseGoal_GetResult_Request__Sequence__are_equal(const cora_msgs__action__PoseGoal_GetResult_Request__Sequence * lhs, const cora_msgs__action__PoseGoal_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cora_msgs__action__PoseGoal_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cora_msgs__action__PoseGoal_GetResult_Request__Sequence__copy(
  const cora_msgs__action__PoseGoal_GetResult_Request__Sequence * input,
  cora_msgs__action__PoseGoal_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cora_msgs__action__PoseGoal_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cora_msgs__action__PoseGoal_GetResult_Request * data =
      (cora_msgs__action__PoseGoal_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cora_msgs__action__PoseGoal_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cora_msgs__action__PoseGoal_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cora_msgs__action__PoseGoal_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "cora_msgs/action/detail/pose_goal__functions.h"

bool
cora_msgs__action__PoseGoal_GetResult_Response__init(cora_msgs__action__PoseGoal_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!cora_msgs__action__PoseGoal_Result__init(&msg->result)) {
    cora_msgs__action__PoseGoal_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
cora_msgs__action__PoseGoal_GetResult_Response__fini(cora_msgs__action__PoseGoal_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  cora_msgs__action__PoseGoal_Result__fini(&msg->result);
}

bool
cora_msgs__action__PoseGoal_GetResult_Response__are_equal(const cora_msgs__action__PoseGoal_GetResult_Response * lhs, const cora_msgs__action__PoseGoal_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!cora_msgs__action__PoseGoal_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
cora_msgs__action__PoseGoal_GetResult_Response__copy(
  const cora_msgs__action__PoseGoal_GetResult_Response * input,
  cora_msgs__action__PoseGoal_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!cora_msgs__action__PoseGoal_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

cora_msgs__action__PoseGoal_GetResult_Response *
cora_msgs__action__PoseGoal_GetResult_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cora_msgs__action__PoseGoal_GetResult_Response * msg = (cora_msgs__action__PoseGoal_GetResult_Response *)allocator.allocate(sizeof(cora_msgs__action__PoseGoal_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cora_msgs__action__PoseGoal_GetResult_Response));
  bool success = cora_msgs__action__PoseGoal_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cora_msgs__action__PoseGoal_GetResult_Response__destroy(cora_msgs__action__PoseGoal_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cora_msgs__action__PoseGoal_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cora_msgs__action__PoseGoal_GetResult_Response__Sequence__init(cora_msgs__action__PoseGoal_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cora_msgs__action__PoseGoal_GetResult_Response * data = NULL;

  if (size) {
    data = (cora_msgs__action__PoseGoal_GetResult_Response *)allocator.zero_allocate(size, sizeof(cora_msgs__action__PoseGoal_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cora_msgs__action__PoseGoal_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cora_msgs__action__PoseGoal_GetResult_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
cora_msgs__action__PoseGoal_GetResult_Response__Sequence__fini(cora_msgs__action__PoseGoal_GetResult_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      cora_msgs__action__PoseGoal_GetResult_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

cora_msgs__action__PoseGoal_GetResult_Response__Sequence *
cora_msgs__action__PoseGoal_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cora_msgs__action__PoseGoal_GetResult_Response__Sequence * array = (cora_msgs__action__PoseGoal_GetResult_Response__Sequence *)allocator.allocate(sizeof(cora_msgs__action__PoseGoal_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cora_msgs__action__PoseGoal_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cora_msgs__action__PoseGoal_GetResult_Response__Sequence__destroy(cora_msgs__action__PoseGoal_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cora_msgs__action__PoseGoal_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cora_msgs__action__PoseGoal_GetResult_Response__Sequence__are_equal(const cora_msgs__action__PoseGoal_GetResult_Response__Sequence * lhs, const cora_msgs__action__PoseGoal_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cora_msgs__action__PoseGoal_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cora_msgs__action__PoseGoal_GetResult_Response__Sequence__copy(
  const cora_msgs__action__PoseGoal_GetResult_Response__Sequence * input,
  cora_msgs__action__PoseGoal_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cora_msgs__action__PoseGoal_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cora_msgs__action__PoseGoal_GetResult_Response * data =
      (cora_msgs__action__PoseGoal_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cora_msgs__action__PoseGoal_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cora_msgs__action__PoseGoal_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cora_msgs__action__PoseGoal_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
// already included above
// #include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "cora_msgs/action/detail/pose_goal__functions.h"

bool
cora_msgs__action__PoseGoal_GetResult_Event__init(cora_msgs__action__PoseGoal_GetResult_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    cora_msgs__action__PoseGoal_GetResult_Event__fini(msg);
    return false;
  }
  // request
  if (!cora_msgs__action__PoseGoal_GetResult_Request__Sequence__init(&msg->request, 0)) {
    cora_msgs__action__PoseGoal_GetResult_Event__fini(msg);
    return false;
  }
  // response
  if (!cora_msgs__action__PoseGoal_GetResult_Response__Sequence__init(&msg->response, 0)) {
    cora_msgs__action__PoseGoal_GetResult_Event__fini(msg);
    return false;
  }
  return true;
}

void
cora_msgs__action__PoseGoal_GetResult_Event__fini(cora_msgs__action__PoseGoal_GetResult_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  cora_msgs__action__PoseGoal_GetResult_Request__Sequence__fini(&msg->request);
  // response
  cora_msgs__action__PoseGoal_GetResult_Response__Sequence__fini(&msg->response);
}

bool
cora_msgs__action__PoseGoal_GetResult_Event__are_equal(const cora_msgs__action__PoseGoal_GetResult_Event * lhs, const cora_msgs__action__PoseGoal_GetResult_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!cora_msgs__action__PoseGoal_GetResult_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!cora_msgs__action__PoseGoal_GetResult_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
cora_msgs__action__PoseGoal_GetResult_Event__copy(
  const cora_msgs__action__PoseGoal_GetResult_Event * input,
  cora_msgs__action__PoseGoal_GetResult_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!cora_msgs__action__PoseGoal_GetResult_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!cora_msgs__action__PoseGoal_GetResult_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

cora_msgs__action__PoseGoal_GetResult_Event *
cora_msgs__action__PoseGoal_GetResult_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cora_msgs__action__PoseGoal_GetResult_Event * msg = (cora_msgs__action__PoseGoal_GetResult_Event *)allocator.allocate(sizeof(cora_msgs__action__PoseGoal_GetResult_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cora_msgs__action__PoseGoal_GetResult_Event));
  bool success = cora_msgs__action__PoseGoal_GetResult_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cora_msgs__action__PoseGoal_GetResult_Event__destroy(cora_msgs__action__PoseGoal_GetResult_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cora_msgs__action__PoseGoal_GetResult_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cora_msgs__action__PoseGoal_GetResult_Event__Sequence__init(cora_msgs__action__PoseGoal_GetResult_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cora_msgs__action__PoseGoal_GetResult_Event * data = NULL;

  if (size) {
    data = (cora_msgs__action__PoseGoal_GetResult_Event *)allocator.zero_allocate(size, sizeof(cora_msgs__action__PoseGoal_GetResult_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cora_msgs__action__PoseGoal_GetResult_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cora_msgs__action__PoseGoal_GetResult_Event__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
cora_msgs__action__PoseGoal_GetResult_Event__Sequence__fini(cora_msgs__action__PoseGoal_GetResult_Event__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      cora_msgs__action__PoseGoal_GetResult_Event__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

cora_msgs__action__PoseGoal_GetResult_Event__Sequence *
cora_msgs__action__PoseGoal_GetResult_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cora_msgs__action__PoseGoal_GetResult_Event__Sequence * array = (cora_msgs__action__PoseGoal_GetResult_Event__Sequence *)allocator.allocate(sizeof(cora_msgs__action__PoseGoal_GetResult_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cora_msgs__action__PoseGoal_GetResult_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cora_msgs__action__PoseGoal_GetResult_Event__Sequence__destroy(cora_msgs__action__PoseGoal_GetResult_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cora_msgs__action__PoseGoal_GetResult_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cora_msgs__action__PoseGoal_GetResult_Event__Sequence__are_equal(const cora_msgs__action__PoseGoal_GetResult_Event__Sequence * lhs, const cora_msgs__action__PoseGoal_GetResult_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cora_msgs__action__PoseGoal_GetResult_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cora_msgs__action__PoseGoal_GetResult_Event__Sequence__copy(
  const cora_msgs__action__PoseGoal_GetResult_Event__Sequence * input,
  cora_msgs__action__PoseGoal_GetResult_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cora_msgs__action__PoseGoal_GetResult_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cora_msgs__action__PoseGoal_GetResult_Event * data =
      (cora_msgs__action__PoseGoal_GetResult_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cora_msgs__action__PoseGoal_GetResult_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cora_msgs__action__PoseGoal_GetResult_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cora_msgs__action__PoseGoal_GetResult_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "cora_msgs/action/detail/pose_goal__functions.h"

bool
cora_msgs__action__PoseGoal_FeedbackMessage__init(cora_msgs__action__PoseGoal_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    cora_msgs__action__PoseGoal_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!cora_msgs__action__PoseGoal_Feedback__init(&msg->feedback)) {
    cora_msgs__action__PoseGoal_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
cora_msgs__action__PoseGoal_FeedbackMessage__fini(cora_msgs__action__PoseGoal_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  cora_msgs__action__PoseGoal_Feedback__fini(&msg->feedback);
}

bool
cora_msgs__action__PoseGoal_FeedbackMessage__are_equal(const cora_msgs__action__PoseGoal_FeedbackMessage * lhs, const cora_msgs__action__PoseGoal_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!cora_msgs__action__PoseGoal_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
cora_msgs__action__PoseGoal_FeedbackMessage__copy(
  const cora_msgs__action__PoseGoal_FeedbackMessage * input,
  cora_msgs__action__PoseGoal_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!cora_msgs__action__PoseGoal_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

cora_msgs__action__PoseGoal_FeedbackMessage *
cora_msgs__action__PoseGoal_FeedbackMessage__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cora_msgs__action__PoseGoal_FeedbackMessage * msg = (cora_msgs__action__PoseGoal_FeedbackMessage *)allocator.allocate(sizeof(cora_msgs__action__PoseGoal_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cora_msgs__action__PoseGoal_FeedbackMessage));
  bool success = cora_msgs__action__PoseGoal_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cora_msgs__action__PoseGoal_FeedbackMessage__destroy(cora_msgs__action__PoseGoal_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cora_msgs__action__PoseGoal_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cora_msgs__action__PoseGoal_FeedbackMessage__Sequence__init(cora_msgs__action__PoseGoal_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cora_msgs__action__PoseGoal_FeedbackMessage * data = NULL;

  if (size) {
    data = (cora_msgs__action__PoseGoal_FeedbackMessage *)allocator.zero_allocate(size, sizeof(cora_msgs__action__PoseGoal_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cora_msgs__action__PoseGoal_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cora_msgs__action__PoseGoal_FeedbackMessage__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
cora_msgs__action__PoseGoal_FeedbackMessage__Sequence__fini(cora_msgs__action__PoseGoal_FeedbackMessage__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      cora_msgs__action__PoseGoal_FeedbackMessage__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

cora_msgs__action__PoseGoal_FeedbackMessage__Sequence *
cora_msgs__action__PoseGoal_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cora_msgs__action__PoseGoal_FeedbackMessage__Sequence * array = (cora_msgs__action__PoseGoal_FeedbackMessage__Sequence *)allocator.allocate(sizeof(cora_msgs__action__PoseGoal_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cora_msgs__action__PoseGoal_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cora_msgs__action__PoseGoal_FeedbackMessage__Sequence__destroy(cora_msgs__action__PoseGoal_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cora_msgs__action__PoseGoal_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cora_msgs__action__PoseGoal_FeedbackMessage__Sequence__are_equal(const cora_msgs__action__PoseGoal_FeedbackMessage__Sequence * lhs, const cora_msgs__action__PoseGoal_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cora_msgs__action__PoseGoal_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cora_msgs__action__PoseGoal_FeedbackMessage__Sequence__copy(
  const cora_msgs__action__PoseGoal_FeedbackMessage__Sequence * input,
  cora_msgs__action__PoseGoal_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cora_msgs__action__PoseGoal_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cora_msgs__action__PoseGoal_FeedbackMessage * data =
      (cora_msgs__action__PoseGoal_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cora_msgs__action__PoseGoal_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cora_msgs__action__PoseGoal_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cora_msgs__action__PoseGoal_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
