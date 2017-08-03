#include <ros/ros.h>
#include <std_msgs/Int32.h>
#include <iostream>

void number_callback(const std_msgs::Int32ConstPtr& msg){
  ROS_INFO("Received [%d]" , msg->data);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "topic_subcriber");
  ros::NodeHandle nh;
  ros::Subscriber number_subscriber = nh.subscribe("/number", 10 , number_callback);
  ros::Rate loop_rate(10);

  ros::spin();
  loop_rate.sleep();
  return 0;
}
