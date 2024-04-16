#pragma once

#include <string>

#include "ros/node_handle.h"
#include "ros/publisher.h"

#include "robotinfo_msgs/RobotInfo10Fields.h"


class RobotInfo
{
public:
    RobotInfo() = delete;
    RobotInfo(ros::NodeHandle &nh);

    virtual void publish_data();    // Publish the robot's info

protected:
    virtual void fill_info_msg();   // Builds the info message

protected:
    robotinfo_msgs::RobotInfo10Fields info_msg; // The robot info message

    ros::Publisher info_pub;        // The robot's info publisher

private:
    std::string robot_description;  // The robot description, for instance the brand or make
    std::string serial_number;      // The robot's serial number
    std::string ip_address;         // The robot's IP address
    std::string firmware_version;   // The robot's Firmware version

};
