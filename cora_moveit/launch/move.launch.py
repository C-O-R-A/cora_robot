"""
A launch file for running the motion planning python api tutorial
"""

import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument, ExecuteProcess
from launch.substitutions import LaunchConfiguration
from moveit_configs_utils import MoveItConfigsBuilder


def generate_launch_description():
    moveit_config = (
        MoveItConfigsBuilder(
            robot_name="cora", package_name="cora_moveit_config"
        )
        .robot_description(file_path="config/cora.urdf.xacro")
        .trajectory_execution(file_path="config/moveit_controllers.yaml")
        .moveit_cpp( # Here we select our planning pipelines config file
            file_path=get_package_share_directory("cora_moveit")
            + "/config/cora_moveit.yaml"
        )
        .to_moveit_configs()
    )

    # Select a script to run
    example_file = DeclareLaunchArgument(
        "executable_name",
        default_value="cora_moveit_test",
        description="Name of executable to run",
    )

    # Create a node for the selected script
    moveit_py_node = Node(
        name="cora_moveit_test",
        package="cora_moveit",
        executable=LaunchConfiguration("executable_name"),
        output="both",
        parameters=[moveit_config.to_dict()],
    )

    # Rviz config
    rviz_config_file = os.path.join(
        get_package_share_directory("cora_moveit_config"),
        "config",
        "moveit.rviz",
    )

    # Rviz node
    rviz_node = Node(
        package="rviz2",
        executable="rviz2",
        output="log",
        arguments=["-d", rviz_config_file],
        parameters=[
            moveit_config.robot_description,
            moveit_config.robot_description_semantic,
        ],
    )

    # Static Transforms
    static_tf = Node(
        package="tf2_ros",
        executable="static_transform_publisher",
        name="static_transform_publisher",
        output="log",
        arguments=["--frame-id", "world", "--child-frame-id", "base_link"],
    )

    # Robot State Publisher
    robot_state_publisher = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        name="robot_state_publisher",
        output="log",
        parameters=[moveit_config.robot_description],
    )

    # Ros 2 controllers config
    ros2_controllers_path = os.path.join(
        get_package_share_directory("cora_moveit_config"),
        "config",
        "ros2_controllers.yaml",
    )

    # Ros 2 controllers node
    ros2_control_node = Node(
        package="controller_manager",
        executable="ros2_control_node",
        parameters=[ros2_controllers_path],
        remappings=[
            ("/controller_manager/robot_description", "/robot_description"),
        ],
        output="log",
    )

    load_controllers = []
    for controller in [
        "arm_controller",
        "gripper_fingers_controller",
        "joint_state_broadcaster",
    ]:
        load_controllers += [
            ExecuteProcess(
                cmd=["ros2 run controller_manager spawner {}".format(controller)],
                shell=True,
                output="log",
            )
        ]

    return LaunchDescription(
        [
            example_file,
            moveit_py_node,
            robot_state_publisher,
            ros2_control_node,
            rviz_node,
            static_tf,
        ]
        + load_controllers
    )