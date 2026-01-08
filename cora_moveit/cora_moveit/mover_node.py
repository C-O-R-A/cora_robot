import collections
import threading
import time

# rclpy library
import rclpy
from rclpy.node import Node
from cora_msgs.action import PoseGoal
from geometry_msgs.msg import PoseStamped
from rclpy.action import ActionServer, CancelResponse, GoalResponse
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.executors import ExternalShutdownException, MultiThreadedExecutor

# moveit python library
from moveit.core.robot_state import RobotState
from moveit.planning import (
    MoveItPy,
    MultiPipelinePlanRequestParameters,
)
from moveit_msgs import moveit_msgs_s__rosidl_typesupport_c
from ament_index_python.packages import get_package_share_directory
from moveit_configs_utils import MoveItConfigsBuilder
from moveit.core.kinematic_constraints import construct_joint_constraint


class MoverNodeServer(Node):

    def __init__(self):
        super().__init__("mover_node")
        self.move = ActionServer(
            self,
            PoseGoal,
            "posegoal",
            callback_group=ReentrantCallbackGroup(),
            handle_accepted_callback=self.handle_accepted_callback,
            goal_callback=self.goal_callback,
            cancel_callback=self.cancel_callback,
            execute_callback=self.execute_callback,
        )
        self.goal_handle = None
        self._goal_queue = collections.deque()
        self._goal_queue_lock = threading.Lock()

        # Instantiate a MoveitPy instance
        self.cora = MoveItPy(node_name="mover_node_server")
        self.cora_arm = self.cora.get_planning_component("arm")
        self.get_logger().info("MoveitPy instance created!")

        # Instantiate a RobotState instance using the current robot model
        self.robot_model = self.cora.get_robot_model()
        self.robot_state = RobotState(self.robot_model)
        self.joint_interface_methods = {
            "position": self.robot_state.joint_positions,
            "velocity": self.robot_state.joint_velocities,
            "effort": self.robot_state.joint_efforts,
            "acceleration": self.robot_state.joint_accelerations,
        }

    def handle_accepted_callback(self, goal_handle):
        with self._goal_queue_lock:
            if self.goal_handle is not None:
                self.get_logger().info(
                    f'Adding goal <<<{goal_handle}>>> to queue'
                    )
                self._goal_queue.append(goal_handle)
            else:
                self.goal_handle = goal_handle
                self.goal_handle.execute()

    def goal_callback(self, goal_request):
        return GoalResponse.ACCEPT

    def cancel_callback(self, goal_handle):
        """Accept or reject a client request to cancel an action."""
        self.get_logger().info("Received cancel request")
        return CancelResponse.ACCEPT

    def execute_callback(self, goal_handle):
        
        try:
            self.get_logger().info(
                f'Execution callback started on goal <<<{goal_handle}>>>'
                )
            space = goal_handle.request.space.strip().upper()
            interface_type = goal_handle.request.interface_type.strip().lower()
            predefined_pose = None

            self.cora_arm.set_start_state_to_current_state()

            # Selecting a predefined pose takes precidence over any other goals
            if goal_handle.request.predefined_pose:
                self.get_logger().info(f"Using predefined pose: {goal_handle.request.predefined_pose.strip().lower()}")
                predefined_pose = goal_handle.request.predefined_pose.strip().lower()
                self.cora_arm.set_goal_state(
                    configuration_name=predefined_pose
                    )

            elif space == "TS":
                self.get_logger().info('Setting Task Space goal...')

                # Extract task space goal and target from action request
                # pose goal should be posestamped msg sent from the client
                try:
                    if interface_type == "position":
                        pose_goal = goal_handle.request.pose_goal.pose
                        target = goal_handle.request.pose_goal.target_frame

                        # Set goal state
                        self.cora_arm.set_goal_state(
                            pose_stamped_msg=pose_goal,
                            pose_link=target
                            )
                    elif interface_type in ('velocity',
                                            'acceleration',
                                            'effort'):
                        raise ValueError(
                            'Mover Node cannot accept preplanned ' \
                            'cartesian velocity or acceleration goals yet... \n'
                            )
                    else:
                        raise ValueError('Invalid interface type specified. ')

                except ValueError as e:
                    self.get_logger().error(e +
                                            'Cancelling motion plan request...'
                                            )
                    goal_handle.abort()
                    return PoseGoal.Result()

            elif space == "JS":
                self.get_logger().info('Setting Joint Space goal...')

                # Extract joint space goal array from action request
                joint_goal = goal_handle.request.joint_goal

                # Assign values from array to dict elements
                joint_values = {
                    f"J{idx}": i for (idx, i) in enumerate(joint_goal, 1)
                    }

                # Set joint values to the correct interface
                self.joint_interface_methods[interface_type] = joint_values

                # Construct joint constraint goal
                joint_constraint = construct_joint_constraint(
                    robot_state=self.robot_state,
                    joint_model_group=self.robot_model.get_joint_model_group("arm")
                )

                # Set goal state
                self.cora_arm.set_goal_state(
                    motion_plan_constraints=[joint_constraint]
                    )

            else:
                self.get_logger().info(
                    f'Unrecognized goal space string: {space}'
                    )
                goal_handle.abort()
                return PoseGoal.Result()

            self.get_logger().info('Planning Trajectory')
            plan_result = self.cora_arm.plan()

            # execute the plan
            if plan_result:
                self.get_logger().info("Executing plan")
                robot_trajectory = plan_result.trajectory
                self.cora.execute(robot_trajectory, controllers=[])
            else:
                self.get_logger().error("Planning failed")
                return PoseGoal.Result()

            goal_handle.succeed()
            # Create a PoseStamped message
            pose_stamped_result = PoseStamped()
            pose_stamped_result.header.stamp = self.get_clock().now().to_msg()  # current ROS time
            pose_stamped_result.header.frame_id = "Gripper"                       # or the frame you used
            pose_stamped_result.pose = self.robot_state.get_pose("Gripper")       # the Pose object

            result = PoseGoal.Result()
            result.pose_result = pose_stamped_result
            result.status_result = 'Complete'
            result.success = True

            return result

        finally:
            with self._goal_queue_lock:
                try:
                    self.get_logger().info('Retrieving goal from queue')
                    self.goal_handle = self._goal_queue.popleft()
                    self.goal_handle.execute()
                except IndexError:
                    self.get_logger().info('No goals left in queue')
                    self.goal_handle = None

    def destroy(self):
        self.move.destroy()
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)

    action_server = MoverNodeServer()

    executor = MultiThreadedExecutor()
    try:
        executor.add_node(action_server)
        executor.spin()
    except (KeyboardInterrupt, ExternalShutdownException):
        pass
    finally:
        action_server.destroy_node()
        rclpy.shutdown()

