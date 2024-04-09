#include "robot_info/robot_info_class.h"

#include "ros/init.h"
#include "ros/rate.h"
#include "ros/ros.h"
#include "ros/node_handle.h"


int main(int argc, char *argv[])
{
    ros::init(argc, argv, "robot_info_node");
    ros::NodeHandle nh;

    RobotInfo robot_info(nh);

    ros::Rate pubRate(1);
    while (ros::ok())
    {
        robot_info.publish_data();
        ros::spinOnce();
        pubRate.sleep();
    }
}
