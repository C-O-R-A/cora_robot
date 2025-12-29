import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from lifecycle_msgs.srv import ChangeState
from lifecycle_msgs.msg import Transition

from tf2_ros import TransformListener, Buffer
from geometry_msgs.msg import TransformStamped
from cora_msgs.action import GripperPoseGoal, PoseGoal
from codi import CoraServer
import threading

class CodiNode(Node):
    def __init__(self):
        super().__init__("codi_node")

        # Status dict
        self.status_dict = {
            'home': 'home'
        }


        # Start CoDI server
        self.codi_server = CoraServer(filepath="../config/server_params.yaml")
        self.codi_server._activate()
        threading.Thread(target=self.codi_server.receive_config, daemon=True).start()
        threading.Thread(target=self.codi_server.receive_command, daemon=True).start()

        # Transform listener
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)
        self.timer = self.create_timer(0.1, self.transforms_callback) # Check every 0.1s

        # # Use gripper param
        # self.declare_parameter('use_gripper', True)
        # self.use_gripper = self.get_parameter('use_gripper').value

        # Pose goal actions
        self.pose_timer = self.create_timer(0.01, self.pose_timer_callback)
        self.gripper_timer = self.create_timer(0.01, self.gripper_timer_callback)
        self.pose_action_client = ActionClient(self, PoseGoal, 'posegoal')
        self.gripper_action_client = ActionClient(self, GripperPoseGoal, 'gripperposegoal')

        # Lifecycle Nodes
        self.vision_client = self.create_client(ChangeState, '/vision_node/change_state')
        self.camera_client = self.create_client(ChangeState, '/camera_node/change_state')
        self.controller_client = self.create_client(ChangeState, '/controller_node/change_state')

    def activate_node(self, client):
        req = ChangeState.Request()
        req.transition.id = Transition.TRANSITION_ACTIVATE
        client.call_async(req)
    
    def deactivate_node(self, client):
        req = ChangeState.Request()
        req.transition.id = Transition.TRANSITION_DEACTIVATE

    def apply_config(self, config):
        if config.use_vision:
            self.activate_node(self.vision_client)
        else:
            self.deactivate_node(self.vision_client)

        if config.use_camera:
            self.activate_node(self.camera_client)
        else:
            self.deactivate_node(self.camera_client)
        
        if config.use_controller:
            self.activate_node(self.controller_client)
        else:
            self.deactivate_node(self.controller_client)

    def transforms_callback(self):
        try:
            gripper_transform_stamped = self.tf_buffer.lookup_transform('gripper', 'base', rclpy.time.Time())
            camera_transform_stamped = self.tf_buffer.lookup_transform('camera','base', rclpy.time.Time())

            self.gripper_transforms = [gripper_transform_stamped.transform.translation, gripper_transform_stamped.transform.rotation]
            self.camera_transforms = [camera_transform_stamped.transform.translation, camera_transform_stamped.transform.rotation]

            # Send to Client
            self.codi_server.send_state(self.status,'TS',self.gripper_transforms)

        except Exception as e:
            self.get_logger().error(f"Could not get transform: {e}") 

    def commands_callback(self):
        try:
            rt, space, interface_type, pose_command , gripper_command = self.codi_server.receive_command()

        except Exception as e:
            self.get_logger().error(f"Could not get commands: {e}") 
        
        goal = PoseGoal.Goal()
        gripper_goal = GripperPoseGoal.Goal()

        

        self._action_client.wait_for_server()

        return self._action_client.send_goal_async(goal_msg)
    
    def config_callback(self):
        config = self.codi_server.receive_config()
        self.apply_config(config)
                 

def main(args=None):
    rclpy.init(args=args)
    node = CodiNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

# ├── moveitpy_node          (Action Client Node)
# ├── vision_node            (LifecycleNode)
# ├── camera_node            (LifecycleNode)
# ├── teleop_node            (LifecycleNode)
# └── lifecycle_manager_node (or logic inside cora_comms)