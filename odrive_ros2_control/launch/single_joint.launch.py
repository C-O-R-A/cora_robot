from launch import LaunchDescription
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from launch.substitutions import PathJoinSubstitution, Command


def generate_launch_description():
    # Adjust "odrive_setup" to whichever package these files actually live in
    pkg_share = FindPackageShare("odrive_ros2_control")

    urdf_path = PathJoinSubstitution([pkg_share, "config", "test_joint.urdf"])
    controllers_path = PathJoinSubstitution([pkg_share, "config", "test_controllers.yaml"])

    robot_description = {"robot_description": Command(["cat ", urdf_path])}

    # Robot State Publisher
    robot_state_publisher = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        name="robot_state_publisher",
        output="log",
        parameters=[robot_description],
    )

    controller_manager = Node(
        package="controller_manager",
        executable="ros2_control_node",
        parameters=[robot_description, controllers_path],
        output="screen",
    )

    joint_state_broadcaster_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["joint_state_broadcaster"],
    )

    test_position_controller_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["test_position_controller"],
    )

    return LaunchDescription([
        robot_state_publisher,
        controller_manager,
        joint_state_broadcaster_spawner,
        test_position_controller_spawner,
    ])