from rclpy.lifecycle import LifecycleNode
from rclpy.lifecycle import State
from rclpy.lifecycle import TransitionCallbackReturn


class VisionNode(LifecycleNode):
    def __init__(self):
        super().__init__("vision_node")

    def on_configure(self, state: State):
        self.get_logger().info("Vision configuring...")
        # allocate resources
        return TransitionCallbackReturn.SUCCESS

    def on_activate(self, state: State):
        self.get_logger().info("Vision activated")
        # start publishers / threads
        return TransitionCallbackReturn.SUCCESS

    def on_deactivate(self, state: State):
        self.get_logger().info("Vision deactivated")
        # stop work
        return TransitionCallbackReturn.SUCCESS

    def on_cleanup(self, state: State):
        self.get_logger().info("Vision cleaned up")
        return TransitionCallbackReturn.SUCCESS
