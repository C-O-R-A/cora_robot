import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import (
    IncludeLaunchDescription,
    RegisterEventHandler,
    DeclareLaunchArgument,
    TimerAction,
)
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch.conditions import IfCondition
from launch.event_handlers import (
    OnExecutionComplete,
)
import os


def generate_launch_description():

    # CoDi server config file path
    config_file = os.path.join(
        get_package_share_directory("cora_codi"), "config", "server_params.yaml"
    )

    # Whether to use CoDi
    use_codi_arg = DeclareLaunchArgument(
        "use_codi", default_value="true", description="Whether to use CoDi for control"
    )

    hardware_arg = DeclareLaunchArgument(
        "hardware",
        default_value="Fake",
        description="Choose hardware type: Fake or Real",
    )

    # Include CoDi node
    codi_node = Node(
        package="cora_codi",
        executable="codi_node",
        name="codi_node",
        output="both",
        parameters=[{"config_file": config_file}],
        condition=IfCondition(LaunchConfiguration("use_codi")),
    )

    # Include MoveIt and Mover node launch files,
    # these will also launch RViz, tf2, controllers, etc
    moveit_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(
                get_package_share_directory("cora_moveit"), "launch", "move.launch.py"
            )
        ),
        launch_arguments={
            "use_servo": "true",
            "use_moveitpy": "true",
        }.items(),
    )

    # Only start CoDi after MoveIt launch finishes initialization
    codi_after_moveit = TimerAction(period=30.0, actions=[codi_node])

    return LaunchDescription(
        [
            use_codi_arg,
            hardware_arg,
            moveit_launch,
            codi_after_moveit,
        ]
    )
