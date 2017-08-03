#include <ros/ros.h>
#include "std_msgs/Int32.h"
#include <iostream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "topic_publisher");
  ros::NodeHandle nh;
  ros::Publisher number_publisher = nh.advertise<std_msgs::Int32>("/number", 10);

  ros::Rate loop_rate(10);

  int number_count = 0;
  while (ros::ok()) {
    std_msgs::Int32 int32_msg;

    int32_msg.data = number_count;

    ROS_INFO("%d", int32_msg.data);//print data of int32_msg to screen

    number_publisher.publish(int32_msg);//publish int32_msg to topic (/number)

    ros::spinOnce();
    loop_rate.sleep();

    ++number_count;
  }

  return 0;
}
