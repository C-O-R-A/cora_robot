"""
A launch file for running the motion planning python api tutorial
"""

import os
import yaml
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.conditions import IfCondition
from launch.actions import DeclareLaunchArgument, ExecuteProcess
from launch.substitutions import LaunchConfiguration
from moveit_configs_utils import MoveItConfigsBuilder


def load_yaml(package_name, file_path):
    package_path = get_package_share_directory(package_name)
    absolute_file_path = os.path.join(package_path, file_path)

    try:
        with open(absolute_file_path, "r") as file:
            return yaml.safe_load(file)
    except (
        EnvironmentError
    ):  # parent of IOError, OSError *and* WindowsError where available
        return None


def generate_launch_description():
    moveit_config = (
        MoveItConfigsBuilder(robot_name="cora", package_name="cora_moveit_config")
        .robot_description(file_path="config/cora.urdf.xacro")
        .trajectory_execution(file_path="config/moveit_controllers.yaml")
        .moveit_cpp(  # Here we select our planning pipelines config file
            file_path=get_package_share_directory("cora_moveit")
            + "/config/cora_moveit.yaml"
        )
        .to_moveit_configs()
    )

    # Get parameters for the Servo node
    servo_yaml = load_yaml("cora_moveit", "config/servo_parameters.yaml")
    servo_params = {"moveit_servo": servo_yaml}

    # Launch arguments
    use_servo = DeclareLaunchArgument(
        "use_servo",
        default_value='false',
        description="Whether to launch servo node"
    )

    use_moveitpy = DeclareLaunchArgument(
        "use_moveitpy",
        default_value='false',
        description="Whether to launch moveitpy node",
    )

    # hardware_arg = DeclareLaunchArgument(
    #     'hardware',
    #     default_value='Fake',
    #     description='Choose hardware type: Fake or Real'
    # )

    # Select a script to run
    moveitpy_file = DeclareLaunchArgument(
        "executable_name",
        default_value="moveitpy_node",
        description="Name of executable to run",
    )

    # Create a node for the selected script
    moveit_py_node = Node(
        name="moveitpy_node",
        package="cora_moveit",
        executable=LaunchConfiguration("executable_name"),
        output="both",
        parameters=[moveit_config.to_dict()],
        condition=IfCondition(LaunchConfiguration("use_moveitpy")),
    )

    servo_node = Node(
        package="moveit_servo",
        executable="servo_node",
        parameters=[
            servo_params,
            moveit_config.robot_description,
            moveit_config.robot_description_semantic,
            moveit_config.robot_description_kinematics,
        ],
        output="screen",
        condition=IfCondition(LaunchConfiguration("use_servo")),
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
            moveit_config.robot_description_kinematics,
        ],
    )

    move_group_node = Node(
        package="moveit_ros_move_group",
        executable="move_group",
        output="screen",
        parameters=[
            moveit_config.to_dict(),
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
            moveitpy_file,
            use_servo,
            use_moveitpy,
            move_group_node,
            moveit_py_node,
            servo_node,
            robot_state_publisher,
            ros2_control_node,
            rviz_node,
            static_tf,
        ]
        + load_controllers
    )


# ros2 launch cora_moveit move.launch.py use_servo:=true use_moveitpy:=true
