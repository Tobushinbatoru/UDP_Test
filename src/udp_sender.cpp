#include "ros/ros.h"
#include "std_msgs/String.h"
#include "simple_udp.h"
#include <unistd.h>
#include <sstream>

int main(int argc, char **argv) {
    ros::init(argc, argv, "udp_sender_node");
    ros::NodeHandle nh;

    SIMPLE_UDP udp0("192.168.49.129", 4001);

    int count = 0;

    while (ros::ok()) {
        // 文字列にカウントを組み込む
        std::ostringstream ss;
        ss << "hello! Count: " << count;
        std::string message = ss.str();

        udp0.udp_send(message);

        // カウントを増やす
        count++;

        // 1秒スリープ
        //sleep(1);

        ROS_INFO("Message sent: %s", message.c_str());
    }

    return 0;
}

