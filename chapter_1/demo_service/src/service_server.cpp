#include <ros/ros.h>
#include <iostream>
#include <sstream>

#include "demo_srv/demo_srv.h"

using namespace std;

bool demo_service_callback(demo_srv::demo_srv::Request& req, demo_srv::demo_srv::Response& res){
  std::stringstream ss;
  ss << "Received Here";
  res.out = ss.str();

  ROS_INFO("From Client [%s] , Server says [%s]" , req.in.c_str() , res.out.c_str());

  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "service_server");
  ros::NodeHandle nh;

  ros::ServiceServer service = nh.advertiseService("demo_service", demo_service_callback);

  ROS_INFO("Ready to receive from client.");
  ros::spin();
  return 0;
}
