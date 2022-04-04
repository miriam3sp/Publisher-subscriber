#include <ros/ros.h>
#include <message_pkg/Num.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "publisher_node");
    ros::NodeHandle nh;
    ros::Publisher chatterPublisher =
        nh.advertise<message_pkg::Num>("top", 10);
    ros::Rate loopRate(10);
    //std_msgs::Int16 count;

    while (ros::ok())
    {
        message_pkg::Num message;
        message.x.data = 0.1f;
        message.y.data = 0.2f;
        message.z.data = 0.3f;

        chatterPublisher.publish(message);
        ros::spinOnce();
        loopRate.sleep();
    }
    return 0;
}