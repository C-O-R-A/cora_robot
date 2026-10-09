#include "hardware_interface/system_interface.hpp"
#include "hardware_interface/types/hardware_interface_type_values.hpp"
#include "pluginlib/class_list_macros.hpp"
#include "rclcpp/rclcpp.hpp"

#include "std_msgs/msg/u_int32_multi_array.hpp"
#include "odrive_msgs/msg/robot_power.hpp"
#include "odrive_msgs/msg/robot_status.hpp"
// General helpers and class definitions
#include "can_helpers.hpp"
#include "socket_can.hpp"

// Odrive specific
#include "odrive_enums.h"
#include "can_simple_messages.hpp"

namespace odrive_ros2_control {

class Axis;

class ODriveHardwareInterface final : public hardware_interface::SystemInterface {
public:
    using return_type = hardware_interface::return_type;
    using State = rclcpp_lifecycle::State;

    CallbackReturn on_init(const hardware_interface::HardwareInfo& info) override;
    CallbackReturn on_configure(const State& previous_state) override;
    CallbackReturn on_cleanup(const State& previous_state) override;
    CallbackReturn on_activate(const State& previous_state) override;
    CallbackReturn on_deactivate(const State& previous_state) override;

    std::vector<hardware_interface::StateInterface> export_state_interfaces() override;
    std::vector<hardware_interface::CommandInterface> export_command_interfaces() override;

    return_type perform_command_mode_switch(
        const std::vector<std::string>& start_interfaces,
        const std::vector<std::string>& stop_interfaces
    ) override;

    return_type read(const rclcpp::Time&, const rclcpp::Duration&) override;
    return_type write(const rclcpp::Time&, const rclcpp::Duration&) override;
    
    rclcpp::Node::SharedPtr node_;
    rclcpp::Publisher<std_msgs::msg::UInt32MultiArray>::SharedPtr heartbeat_pub_;
    rclcpp::Publisher<odrive_msgs::msg::RobotStatus>::SharedPtr status_pub_;
    rclcpp::Publisher<odrive_msgs::msg::RobotPower>::SharedPtr power_pub_;

private:
    void on_can_msg(const can_frame& frame);
    void set_axis_command_mode(const Axis& axis);

    bool active_;
    EpollEventLoop event_loop_;
    std::vector<Axis> axes_;
    std::string can_intf_name_;
    SocketCanIntf can_intf_;
    rclcpp::Time timestamp_;
};

struct Axis {
    Axis(SocketCanIntf* can_intf, uint32_t node_id, double transmission, std::array<double, 3> gains)
    : can_intf_(can_intf),
      node_id_(node_id),
      transmission_(transmission),
      pos_gain(gains[0]),
      vel_gain(gains[1]),
      vel_integrator_gain(gains[2]) {}

    void on_can_msg(const rclcpp::Time& timestamp, const can_frame& frame);

    void on_can_msg();

    SocketCanIntf* can_intf_;
    uint32_t node_id_;
    double transmission_;
    double pos_gain;
    double vel_gain;
    double vel_integrator_gain;

    // Commands (ros2_control => ODrives)
    double pos_setpoint_ = 0.0f; // [rad]
    double vel_setpoint_ = 0.0f; // [rad/s]
    double torque_setpoint_ = 0.0f; // [Nm]

    // State (ODrives => ros2_control)
    // rclcpp::Time encoder_estimates_timestamp_;
    uint32_t axis_error_ = 0;
    uint8_t axis_state_ = 0;
    uint8_t motor_error_flag_ = 0;
    uint8_t encoder_error_flag_ = 0;
    uint8_t controller_error_flag_ = 0;
    uint8_t trajectory_done_flag_ = 0;
    uint8_t procedure_result_ = 0;

    uint32_t motor_error_ = 0;
    uint32_t encoder_error_ = 0;
    uint32_t controller_error_ = 0;
    uint32_t sensorless_error_ = 0;
    uint32_t active_errors_ = 0;
    uint32_t disarm_reason_ = 0;

    double pos_estimate_ = NAN; // [rad]
    double vel_estimate_ = NAN; // [rad/s]
    double iq_setpoint_ = NAN; // [A]
    double iq_measured_ = NAN; // [A]
    double torque_target_ = NAN; // [Nm]
    double torque_estimate_ = NAN; // [Nm]
    double bus_voltage_ = NAN; // [V]
    double bus_current_ = NAN; // [A]

    // Indicates which controller inputs are enabled. This is configured by the
    // controller that sits on top of this hardware interface. Multiple inputs
    // can be enabled at the same time, in this case the non-primary inputs are
    // used as feedforward terms.
    // This implicitly defines the ODrive's control mode.
    bool pos_input_enabled_ = false;
    bool vel_input_enabled_ = false;
    bool torque_input_enabled_ = false;

    template <typename T>
    void send(const T& msg) const {
        struct can_frame frame;
        frame.can_id = node_id_ << 5 | msg.cmd_id;
        frame.can_dlc = msg.msg_length;
        msg.encode_buf(frame.data);

        can_intf_->send_can_frame(frame);
    }

    void request_encoder_estimates() const {
        struct can_frame frame;
        frame.can_id = node_id_ << 5 | Get_Encoder_Estimates_msg_t::cmd_id;
        frame.can_id |= CAN_RTR_FLAG;
        frame.can_dlc = Get_Encoder_Estimates_msg_t::msg_length;
        can_intf_->send_can_frame(frame);
    }

    void request_bus_voltage_current() const {
        struct can_frame frame;
        frame.can_id = node_id_ << 5 | Get_Bus_Voltage_Current_msg_t::cmd_id;
        frame.can_id |= CAN_RTR_FLAG;
        frame.can_dlc = Get_Bus_Voltage_Current_msg_t::msg_length;
        can_intf_->send_can_frame(frame);
    }

    void request_iq() const {
        struct can_frame frame;
        frame.can_id = node_id_ << 5 | Get_Iq_msg_t::cmd_id;
        frame.can_id |= CAN_RTR_FLAG;
        frame.can_dlc = Get_Iq_msg_t::msg_length;
        can_intf_->send_can_frame(frame);
    }

    void request_errors() const {
        struct can_frame frame;
        frame.can_id = node_id_ << 5 | Get_Motor_Error_msg_t::cmd_id;
        frame.can_id |= CAN_RTR_FLAG;
        frame.can_dlc = Get_Motor_Error_msg_t::msg_length;
        can_intf_->send_can_frame(frame);

        frame.can_id = node_id_ << 5 | Get_Encoder_Error_msg_t::cmd_id;
        frame.can_id |= CAN_RTR_FLAG;
        frame.can_dlc = Get_Encoder_Error_msg_t::msg_length;
        can_intf_->send_can_frame(frame);

        frame.can_id = node_id_ << 5 | Get_Controller_Error_msg_t::cmd_id;
        frame.can_id |= CAN_RTR_FLAG;
        frame.can_dlc = Get_Controller_Error_msg_t::msg_length;
        can_intf_->send_can_frame(frame);
    }

    void set_gains() const {
        Set_Pos_Gain_msg_t pos_msg;
        pos_msg.Pos_Gain = pos_gain;
        send(pos_msg);

        Set_Vel_Gains_msg_t vel_msg;
        vel_msg.Vel_Gain = vel_gain;
        vel_msg.Vel_Integrator_Gain = vel_integrator_gain;
        send(vel_msg);    
    }

}; // namespace odrive_ros2_control
}
using namespace odrive_ros2_control;

using hardware_interface::CallbackReturn;
using hardware_interface::return_type;

CallbackReturn ODriveHardwareInterface::on_init(const hardware_interface::HardwareInfo& info) {
    if (hardware_interface::SystemInterface::on_init(info) != CallbackReturn::SUCCESS) {
        return CallbackReturn::ERROR;
    }
    // Parse CAN interface name
    can_intf_name_ = info_.hardware_parameters["can"];

    // Create axes with their node IDs and add them to the axes_ vector
    for (auto& joint : info_.joints) {
        double transmission_ = std::stod(joint.parameters.at("transmission"));
        int node_id = std::stoi(joint.parameters.at("node_id"));
        std::array<double, 3> gains = {
            std::stod(joint.parameters.at("pos_gain")),
            std::stod(joint.parameters.at("vel_gain")),
            std::stod(joint.parameters.at("vel_integrator_gain"))
        };

        axes_.emplace_back(
            &can_intf_, 
            node_id, 
            transmission_,
            gains
        );
    }

    return CallbackReturn::SUCCESS;
}

CallbackReturn ODriveHardwareInterface::on_configure(const State&) {
    // Initialize CAN interface with can_intf_.init(name, event_loop, callback)
    // Error if initialization fails
    if (!can_intf_.init(can_intf_name_, &event_loop_, std::bind(&ODriveHardwareInterface::on_can_msg, this, _1))) {
        RCLCPP_ERROR(
            rclcpp::get_logger("ODriveHardwareInterface"),
            "Failed to initialize SocketCAN on %s",
            can_intf_name_.c_str()
        );
        return CallbackReturn::ERROR;
    }
    RCLCPP_INFO(rclcpp::get_logger("ODriveHardwareInterface"), "Initialized SocketCAN on %s", can_intf_name_.c_str());

    node_ = rclcpp::Node::make_shared("odrive_ros2_control_status");
    status_pub_ = node_->create_publisher<odrive_msgs::msg::RobotStatus>("odrive/status", 10);
    power_pub_ = node_->create_publisher<odrive_msgs::msg::RobotPower>("odrive/power", 10);

    return CallbackReturn::SUCCESS;
}

CallbackReturn ODriveHardwareInterface::on_cleanup(const State&) {
    // Deinitialize CAN interface
    can_intf_.deinit();
    return CallbackReturn::SUCCESS;
}

CallbackReturn ODriveHardwareInterface::on_activate(const State&) {
    RCLCPP_INFO(rclcpp::get_logger("ODriveHardwareInterface"), "activating ODrives...");

    // This can be called several seconds before the controller finishes starting.
    // Therefore we enable the ODrives only in perform_command_mode_switch().

    active_ = true;
    for (auto& axis : axes_) {
        set_axis_command_mode(axis);
        axis.set_gains();
    }

    return CallbackReturn::SUCCESS;
}

CallbackReturn ODriveHardwareInterface::on_deactivate(const State&) {
    RCLCPP_INFO(rclcpp::get_logger("ODriveHardwareInterface"), "deactivating ODrives...");
    // Disable all ODrives using the active_ flag
    active_ = false;
    for (auto& axis : axes_) {
        set_axis_command_mode(axis);
    }

    return CallbackReturn::SUCCESS;
}

std::vector<hardware_interface::StateInterface> ODriveHardwareInterface::export_state_interfaces() {
    std::vector<hardware_interface::StateInterface> state_interfaces;
    // Export state interfaces for each joint, 
    // take the values stored in corresponding Axis object
    for (size_t i = 0; i < info_.joints.size(); i++) {
        state_interfaces.emplace_back(hardware_interface::StateInterface(
            info_.joints[i].name,
            hardware_interface::HW_IF_EFFORT,
            &axes_[i].torque_target_
        ));
        state_interfaces.emplace_back(hardware_interface::StateInterface(
            info_.joints[i].name,
            hardware_interface::HW_IF_VELOCITY,
            &axes_[i].vel_estimate_
        ));
        state_interfaces.emplace_back(hardware_interface::StateInterface(
            info_.joints[i].name,
            hardware_interface::HW_IF_POSITION,
            &axes_[i].pos_estimate_
        ));
    }

    return state_interfaces;
}

std::vector<hardware_interface::CommandInterface> ODriveHardwareInterface::export_command_interfaces() {
    std::vector<hardware_interface::CommandInterface> command_interfaces;
    // Tell ros2_control what variables to update (with a command) for each joint command interface
    for (size_t i = 0; i < info_.joints.size(); i++) {
        command_interfaces.emplace_back(hardware_interface::CommandInterface(
            info_.joints[i].name,
            hardware_interface::HW_IF_EFFORT,
            &axes_[i].torque_setpoint_
        ));
        command_interfaces.emplace_back(hardware_interface::CommandInterface(
            info_.joints[i].name,
            hardware_interface::HW_IF_VELOCITY,
            &axes_[i].vel_setpoint_
        ));
        command_interfaces.emplace_back(hardware_interface::CommandInterface(
            info_.joints[i].name,
            hardware_interface::HW_IF_POSITION,
            &axes_[i].pos_setpoint_
        ));
    }

    return command_interfaces;
}

return_type ODriveHardwareInterface::perform_command_mode_switch(
    const std::vector<std::string>& start_interfaces,
    const std::vector<std::string>& stop_interfaces
) {
    for (size_t i = 0; i < axes_.size(); ++i) {
        // Get reference to the axis
        Axis& axis = axes_[i];

        // Map of interface names to pointers to the corresponding enabled flags in kv pairs
        std::array<std::pair<std::string, bool*>, 3> interfaces = {
            {{info_.joints[i].name + "/" + hardware_interface::HW_IF_POSITION, &axis.pos_input_enabled_},
             {info_.joints[i].name + "/" + hardware_interface::HW_IF_VELOCITY, &axis.vel_input_enabled_},
             {info_.joints[i].name + "/" + hardware_interface::HW_IF_EFFORT, &axis.torque_input_enabled_}}};

        bool mode_switch = false;
        
        // Disable interfaces in stop_interfaces
        for (const std::string& key : stop_interfaces) {
            for (auto& kv : interfaces) {
                // if interface matches, disable it 
                if (kv.first == key) {
                    *kv.second = false;
                    mode_switch = true;
                }
            }
        }

        // Enable interfaces in start_interfaces
        for (const std::string& key : start_interfaces) {
            for (auto& kv : interfaces) {
                // if interface matches, enable it
                if (kv.first == key) {
                    *kv.second = true;
                    mode_switch = true;
                }
            }
        }
        
        // If any interface was started or stopped, 
        // update the ODrive's control mode in accordance with the enabled inputs
        if (mode_switch) {
            set_axis_command_mode(axis);
        }
    }

    return return_type::OK;
}

return_type ODriveHardwareInterface::read(const rclcpp::Time& timestamp, const rclcpp::Duration&) {
    timestamp_ = timestamp;
    // Read all available CAN messages,
    // this updates the can message in can_intf_ 
    // and can_intf_ calls on_can_msg() for each received message
    while (can_intf_.read_nonblocking()) {
    }

    odrive_msgs::msg::RobotStatus status;
    status.joint_status.resize(axes_.size());

    odrive_msgs::msg::RobotPower power;
    power.joint_power.resize(axes_.size());

    for (size_t i = 0; i < axes_.size(); ++i) {
        auto &a = axes_[i];

        odrive_msgs::msg::JointStatus joint_status;
        joint_status.axis_state.axis_state = a.axis_state_;
        joint_status.axis_error.error = a.axis_error_;
        joint_status.controller_error.error = a.controller_error_;
        joint_status.encoder_error.error = a.encoder_error_;
        joint_status.motor_error.error = a.motor_error_;
        status.joint_status[i] = joint_status;

        odrive_msgs::msg::JointPower joint_power;
        joint_power.joint_name = info_.joints[i].name;
        joint_power.bus_voltage = a.bus_voltage_;
        joint_power.bus_current = a.bus_current_;
        joint_power.iq_measured = a.iq_measured_;
        joint_power.iq_setpoint = a.iq_setpoint_;
        power.joint_power[i] = joint_power;
    }

    status_pub_->publish(status);
    power_pub_->publish(power);

    return return_type::OK;
}

return_type ODriveHardwareInterface::write(const rclcpp::Time&, const rclcpp::Duration&) {
    for (auto& axis : axes_) {
        // Request periodic feedback from the ODrive so its state can be monitored.
        axis.request_encoder_estimates();
        // axis.request_bus_voltage_current();
        // axis.request_iq();
        // axis.request_errors();

        // Send the CAN message that fits the set of enabled input types
        if (axis.pos_input_enabled_) {
            Set_Input_Pos_msg_t msg;
            msg.Input_Pos = (axis.pos_setpoint_ / (2 * M_PI)) * axis.transmission_;
            msg.Vel_FF = axis.vel_input_enabled_ ? (axis.vel_setpoint_ / (2 * M_PI)) * axis.transmission_ : 0.0f;
            msg.Torque_FF = axis.torque_input_enabled_ ? (axis.torque_setpoint_ / axis.transmission_) : 0.0f;
            axis.send(msg);
        } else if (axis.vel_input_enabled_) {
            Set_Input_Vel_msg_t msg;
            msg.Input_Vel = (axis.vel_setpoint_ / (2 * M_PI)) * axis.transmission_;
            msg.Input_Torque_FF = axis.torque_input_enabled_ ? (axis.torque_setpoint_ / axis.transmission_) : 0.0f;
            axis.send(msg);
        } else if (axis.torque_input_enabled_) {
            Set_Input_Torque_msg_t msg;
            msg.Input_Torque = axis.torque_setpoint_ / axis.transmission_;
            axis.send(msg);
        } else {
            // no control enabled - don't send any setpoint
        }
    }

    return return_type::OK;
}

void ODriveHardwareInterface::on_can_msg(const can_frame& frame) {
    // Check what axis the message is for
    for (auto& axis : axes_) {
        // if axis node id matches the can id, 
        // pass it to the axis for processing
        if ((frame.can_id >> 5) == axis.node_id_) {
            axis.on_can_msg(timestamp_, frame);
        }
    }
}

void ODriveHardwareInterface::set_axis_command_mode(const Axis& axis) {
    if (!active_) {
        RCLCPP_INFO(rclcpp::get_logger("ODriveHardwareInterface"), "Interface inactive. Setting axis to idle.");
        Set_Axis_State_msg_t idle_msg;
        idle_msg.Axis_Requested_State = AXIS_STATE_IDLE;
        axis.send(idle_msg);
        return;
    }

    Set_Controller_Mode_msg_t control_msg;
    Clear_Errors_msg_t clear_error_msg;
    Set_Axis_State_msg_t state_msg;

    control_msg.Input_Mode = INPUT_MODE_PASSTHROUGH;
    state_msg.Axis_Requested_State = AXIS_STATE_CLOSED_LOOP_CONTROL;

    if (axis.pos_input_enabled_) {
        RCLCPP_INFO(rclcpp::get_logger("ODriveHardwareInterface"), "Setting to position control.");
        control_msg.Control_Mode = CONTROL_MODE_POSITION_CONTROL;
    } else if (axis.vel_input_enabled_) {
        RCLCPP_INFO(rclcpp::get_logger("ODriveHardwareInterface"), "Setting to velocity control.");
        control_msg.Control_Mode = CONTROL_MODE_VELOCITY_CONTROL;
    } else if (axis.torque_input_enabled_) {
        RCLCPP_INFO(rclcpp::get_logger("ODriveHardwareInterface"), "Setting to torque control.");
        control_msg.Control_Mode = CONTROL_MODE_TORQUE_CONTROL;
    } else {
        RCLCPP_INFO(rclcpp::get_logger("ODriveHardwareInterface"), "No control mode specified. Setting to idle.");
        state_msg.Axis_Requested_State = AXIS_STATE_IDLE;
        axis.send(state_msg);
        return;
    }

    axis.send(control_msg);
    axis.send(clear_error_msg);
    axis.send(state_msg);
}

void Axis::on_can_msg(const rclcpp::Time&, const can_frame& frame) {
    uint8_t cmd = frame.can_id & 0x1f;

    auto try_decode = [&]<typename TMsg>(TMsg& msg) {
        if (frame.can_dlc < Get_Encoder_Estimates_msg_t::msg_length) {
            RCLCPP_WARN(rclcpp::get_logger("ODriveHardwareInterface"), "message %d too short", cmd);
            return false;
        }
        msg.decode_buf(frame.data);
        return true;
    };

    switch (cmd) {
        case Heartbeat_msg_t::cmd_id: {
            if (Heartbeat_msg_t msg; try_decode(msg)) {
                axis_error_ = msg.Axis_Error;
                axis_state_ = msg.Axis_State;
                motor_error_flag_ = msg.Motor_Error_Flag;
                encoder_error_flag_ = msg.Encoder_Error_Flag;
                controller_error_flag_ = msg.Controller_Error_Flag;
                trajectory_done_flag_ = msg.Trajectory_Done_Flag;
            }
        } break;
        case Get_Encoder_Estimates_msg_t::cmd_id: {
            if (Get_Encoder_Estimates_msg_t msg; try_decode(msg)) {
                pos_estimate_ = (msg.Pos_Estimate / transmission_) * (2 * M_PI);
                vel_estimate_ = (msg.Vel_Estimate / transmission_) * (2 * M_PI);
            }
        } break;
        case Get_Motor_Error_msg_t::cmd_id: {
            if (Get_Motor_Error_msg_t msg; try_decode(msg)) {
                motor_error_ = static_cast<uint32_t>(msg.Motor_Error);
            }
        } break;
        case Get_Encoder_Error_msg_t::cmd_id: {
            if (Get_Encoder_Error_msg_t msg; try_decode(msg)) {
                encoder_error_ = static_cast<uint32_t>(msg.Encoder_Error);
            }
        } break;
        case Get_Controller_Error_msg_t::cmd_id: {
            if (Get_Controller_Error_msg_t msg; try_decode(msg)) {
                controller_error_ = static_cast<uint32_t>(msg.Controller_Error);
            }
        } break;
        case Get_Iq_msg_t::cmd_id: {
            if (Get_Iq_msg_t msg; try_decode(msg)) {
                iq_setpoint_ = msg.Iq_Setpoint;
                iq_measured_ = msg.Iq_Measured;
                torque_target_ = msg.Iq_Setpoint;
                torque_estimate_ = msg.Iq_Measured;
            }
        } break;
        case Get_Bus_Voltage_Current_msg_t::cmd_id: {
            if (Get_Bus_Voltage_Current_msg_t msg; try_decode(msg)) {
                bus_voltage_ = msg.Bus_Voltage;
                bus_current_ = msg.Bus_Current;
            }
        } break;
            // silently ignore unimplemented command IDs
    }
}

PLUGINLIB_EXPORT_CLASS(odrive_ros2_control::ODriveHardwareInterface, hardware_interface::SystemInterface)
