#include <ros/ros.h>
#include <std_msgs/Int32.h>
#include <iostream>
#include <sstream>

#include "demo_msg/demo_msg.h"

using namespace std;

void number_callback(const demo_msg::demo_msgConstPtr& msg){
    ROS_INFO("Received greeting: [%s]" , msg->greeting.c_str());
    ROS_INFO("Received   number: [%d]" , msg->number);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "msg_subscriber");
  ros::NodeHandle nh;

  ros::Subscriber number_subscriber = nh.subscribe("/msg_topic" , 10 , number_callback);

  ros::spin();
  return 0;
}
