#include "robot_info/robot_info_class.h"
#include "robotinfo_msgs/RobotInfo10Fields.h"


RobotInfo::RobotInfo(ros::NodeHandle &nh)
    : robot_description{ "Mir100" }
    , serial_number{ "567A359" }
    , ip_address{ "169.254.5.180" }
    , firmware_version{ "3.5.8" }
    , info_pub{ nh.advertise<robotinfo_msgs::RobotInfo10Fields>("/robot_info", 1000) }
{
    ROS_INFO("RobotInfo Publisher created");
}

void RobotInfo::publish_data()
{
    fill_info_msg();
    info_pub.publish(info_msg);
}

void RobotInfo::fill_info_msg()
{
    info_msg.data_field_01 = "robot_description: " + robot_description;
    info_msg.data_field_02 = "serial_number: " + serial_number;
    info_msg.data_field_03 = "ip_address: " + ip_address;
    info_msg.data_field_04 = "firmware_version: " + firmware_version;
}
