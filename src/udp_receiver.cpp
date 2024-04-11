#include "ros/ros.h"
#include "std_msgs/String.h"
#include "simple_udp.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "udp_receiver_node");
    ros::NodeHandle nh;

    SIMPLE_UDP udp0("0.0.0.0", 4001);
    udp0.udp_bind();

    while (ros::ok()) {
        std::string rdata = udp0.udp_recv();
        ROS_INFO("Received: %s", rdata.c_str());
    }

    return 0;
}

