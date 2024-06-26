#pragma once

#include <string>

#include "robot_info/robot_info_class.h"
#include "robot_info/hydraulic_system_monitor.h"

#include "ros/node_handle.h"
#include "ros/publisher.h"

#include "robotinfo_msgs/RobotInfo10Fields.h"


class AGVRobotInfo : public RobotInfo
{
public:
    AGVRobotInfo() = delete;
    AGVRobotInfo(ros::NodeHandle &nh);

    void publish_data() override;   // Publish the robot's info

protected:
    void fill_info_msg() override;  // Builds the info message

private:
    std::string maximum_payload;    // The maximum weight the robot can transport

    HydraulicSystemMonitor hydraulicSysMon; // Monitors the hydraulics of the robot

};
