# rclpy library
import rclpy
from rclpy.node import Node
from cora_msgs.action import PoseGoal
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


class GripperNodeServer(Node):
    '''
    GripperNodeServer
    description: Gripper actuation service. moves fingers of the gripper with moveit
    '''
    def __init__(self):
        super().__init__("gripper_node")
