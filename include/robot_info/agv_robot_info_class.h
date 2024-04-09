#pragma once

#include <string>

#include "robot_info/robot_info_class.h"

#include "ros/node_handle.h"
#include "ros/publisher.h"

#include "robot_info_msg/robot_info_10.h"


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

};
