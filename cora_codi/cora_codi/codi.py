import rclpy
from rclpy.node import Node
from tf2_ros import TransformListener, Buffer
from geometry_msgs.msg import TransformStamped
from codi import CoraClient

class CodiNode(Node):
    def __init__(self):
        super().__init__("codi_node")
        self.codi_server = CoraClient()
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)
        self.timer = self.create_timer(0.1, self.transforms_callback) # Check every 0.1s
        

    def transforms_callback(self):
        try:
            gripper_transform_stamped = self.tf_buffer.lookup_transform('gripper', 'base', rclpy.time.Time())
            camera_transform_stamped = self.tf_buffer.lookup_transform('camera','base', rclpy.time.Time())

            gripper_transforms = [gripper_transform_stamped.transform.translation, gripper_transform_stamped.transform.rotation]
            camera_transforms = [camera_transform_stamped.transform.translation, camera_transform_stamped.transform.rotation]

        except Exception as e:
            self.get_logger().error(f"Could not get transform: {e}") 

    def commands_callback(self):
        try:
            space, interface_type, commands = self.codi_server.decode_commands(self.codi_server.receive_commands())
        
        except Exception as e:
            self.get_logger().error(f"Could not get commands: {e}") 
                 

def main(args=None):
    rclpy.init(args=args)
    node = CodiNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()


self.cmd_vel_pub = self.create_publisher(
    Twist, 
    '/mirte_base_controller/cmd_vel', 
    1)