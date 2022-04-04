#include "ros/ros.h"
#include <message_pkg/Num.h>

void chatterCallback(const message_pkg::Num::ConstPtr &msg)
{
    std::string string_var;
    ros::param::get("/joint", string_var);
    ROS_INFO("I heard: [%s %f %f %f]", string_var.c_str(), msg->x.data, msg->y.data, msg->z.data);
}
int main(int argc, char **argv)
{
    ros::init(argc, argv, "listener");
    ros::NodeHandle nodeHandle;
    ros::Subscriber subscriber =
        nodeHandle.subscribe("top", 10, chatterCallback);
    ros::spin();
    return 0;
}