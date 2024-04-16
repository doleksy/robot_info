#include "robot_info/agv_robot_info_class.h"


AGVRobotInfo::AGVRobotInfo(ros::NodeHandle &nh)
    : RobotInfo(nh)
    , maximum_payload{ "100 kg" }
{
    ROS_INFO("AGVRobotInfo Publisher created");
}

void AGVRobotInfo::publish_data()
{
    RobotInfo::fill_info_msg();
    fill_info_msg();
    info_pub.publish(info_msg);
}

void AGVRobotInfo::fill_info_msg()
{
    info_msg.data_field_05 = "maximum_payload: " + maximum_payload;

    hydraulicSysMon.fill_in_msg(info_msg);
}
