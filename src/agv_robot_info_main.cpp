#include "robot_info/agv_robot_info_class.h"

#include "ros/init.h"
#include "ros/rate.h"
#include "ros/ros.h"
#include "ros/node_handle.h"


int main(int argc, char *argv[])
{
    ros::init(argc, argv, "agv_robot_info_node");
    ros::NodeHandle nh;

    AGVRobotInfo robot_info(nh);

    ros::Rate pubRate(1);
    while (ros::ok())
    {
        robot_info.publish_data();
        ros::spinOnce();
        pubRate.sleep();
    }
}
