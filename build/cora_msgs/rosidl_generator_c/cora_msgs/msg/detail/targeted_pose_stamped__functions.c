// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cora_msgs:msg/TargetedPoseStamped.idl
// generated code does not contain a copyright notice
#include "cora_msgs/msg/detail/targeted_pose_stamped__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `target_frame`
#include "rosidl_runtime_c/string_functions.h"
// Member `pose`
#include "geometry_msgs/msg/detail/pose_stamped__functions.h"

bool
cora_msgs__msg__TargetedPoseStamped__init(cora_msgs__msg__TargetedPoseStamped * msg)
{
  if (!msg) {
    return false;
  }
  // target_frame
  if (!rosidl_runtime_c__String__init(&msg->target_frame)) {
    cora_msgs__msg__TargetedPoseStamped__fini(msg);
    return false;
  }
  // pose
  if (!geometry_msgs__msg__PoseStamped__init(&msg->pose)) {
    cora_msgs__msg__TargetedPoseStamped__fini(msg);
    return false;
  }
  return true;
}

void
cora_msgs__msg__TargetedPoseStamped__fini(cora_msgs__msg__TargetedPoseStamped * msg)
{
  if (!msg) {
    return;
  }
  // target_frame
  rosidl_runtime_c__String__fini(&msg->target_frame);
  // pose
  geometry_msgs__msg__PoseStamped__fini(&msg->pose);
}

bool
cora_msgs__msg__TargetedPoseStamped__are_equal(const cora_msgs__msg__TargetedPoseStamped * lhs, const cora_msgs__msg__TargetedPoseStamped * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // target_frame
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->target_frame), &(rhs->target_frame)))
  {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__PoseStamped__are_equal(
      &(lhs->pose), &(rhs->pose)))
  {
    return false;
  }
  return true;
}

bool
cora_msgs__msg__TargetedPoseStamped__copy(
  const cora_msgs__msg__TargetedPoseStamped * input,
  cora_msgs__msg__TargetedPoseStamped * output)
{
  if (!input || !output) {
    return false;
  }
  // target_frame
  if (!rosidl_runtime_c__String__copy(
      &(input->target_frame), &(output->target_frame)))
  {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__PoseStamped__copy(
      &(input->pose), &(output->pose)))
  {
    return false;
  }
  return true;
}

cora_msgs__msg__TargetedPoseStamped *
cora_msgs__msg__TargetedPoseStamped__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cora_msgs__msg__TargetedPoseStamped * msg = (cora_msgs__msg__TargetedPoseStamped *)allocator.allocate(sizeof(cora_msgs__msg__TargetedPoseStamped), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cora_msgs__msg__TargetedPoseStamped));
  bool success = cora_msgs__msg__TargetedPoseStamped__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cora_msgs__msg__TargetedPoseStamped__destroy(cora_msgs__msg__TargetedPoseStamped * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cora_msgs__msg__TargetedPoseStamped__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cora_msgs__msg__TargetedPoseStamped__Sequence__init(cora_msgs__msg__TargetedPoseStamped__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cora_msgs__msg__TargetedPoseStamped * data = NULL;

  if (size) {
    data = (cora_msgs__msg__TargetedPoseStamped *)allocator.zero_allocate(size, sizeof(cora_msgs__msg__TargetedPoseStamped), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cora_msgs__msg__TargetedPoseStamped__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cora_msgs__msg__TargetedPoseStamped__fini(&data[i - 1]);
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
cora_msgs__msg__TargetedPoseStamped__Sequence__fini(cora_msgs__msg__TargetedPoseStamped__Sequence * array)
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
      cora_msgs__msg__TargetedPoseStamped__fini(&array->data[i]);
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

cora_msgs__msg__TargetedPoseStamped__Sequence *
cora_msgs__msg__TargetedPoseStamped__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cora_msgs__msg__TargetedPoseStamped__Sequence * array = (cora_msgs__msg__TargetedPoseStamped__Sequence *)allocator.allocate(sizeof(cora_msgs__msg__TargetedPoseStamped__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cora_msgs__msg__TargetedPoseStamped__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cora_msgs__msg__TargetedPoseStamped__Sequence__destroy(cora_msgs__msg__TargetedPoseStamped__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cora_msgs__msg__TargetedPoseStamped__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cora_msgs__msg__TargetedPoseStamped__Sequence__are_equal(const cora_msgs__msg__TargetedPoseStamped__Sequence * lhs, const cora_msgs__msg__TargetedPoseStamped__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cora_msgs__msg__TargetedPoseStamped__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cora_msgs__msg__TargetedPoseStamped__Sequence__copy(
  const cora_msgs__msg__TargetedPoseStamped__Sequence * input,
  cora_msgs__msg__TargetedPoseStamped__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cora_msgs__msg__TargetedPoseStamped);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cora_msgs__msg__TargetedPoseStamped * data =
      (cora_msgs__msg__TargetedPoseStamped *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cora_msgs__msg__TargetedPoseStamped__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cora_msgs__msg__TargetedPoseStamped__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cora_msgs__msg__TargetedPoseStamped__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
