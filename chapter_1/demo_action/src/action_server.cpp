#include <ros/ros.h>
#include <iostream>
#include <sstream>
#include <actionlib/server/simple_action_server.h>

#include "demo_action/demo_actionAction.h"

using namespace std;

class demo_actionAction{
protected:
  ros::NodeHandle nh;

  actionlib::SimpleActionServer<demo_action::demo_actionAction> action_server;

  demo_action::demo_actionFeedback action_feedback;

  demo_action::demo_actionResult action_result;

  std::string action_name;
  int goal;
  int progress;

public:
  demo_actionAction(std::string name):
    action_server(nh , name , boost::bind(&demo_actionAction::executeCB , this , _1) , false),
    action_name(name){
      action_server.registerPreemptCallback(boost::bind(&demo_actionAction::preemptCB, this));
      action_server.start();
  }
  ~demo_actionAction(void){
  }

  void preemptCB(){
    ROS_WARN("%s got preempted!", action_name.c_str());
    action_result.final_count = progress;
    action_server.setPreempted(action_result, "I got Preempted");
  }

  void executeCB(const demo_action::demo_actionGoalConstPtr& goal){
    if(!action_server.isActive() || action_server.isPreemptRequested()){
      return;
    }
    ros::Rate rate(5);

    ROS_INFO("%s is processing the goal %d" , action_name.c_str() , goal->count);
    for(progress = 1; progress <= goal->count ; progress++){
      if(!ros::ok()){
        action_result.final_count = progress;
        action_server.setAborted(action_result, "I failed !");
        ROS_INFO("%s Shutting down", action_name.c_str());
        break;
      }

      if(!action_server.isActive() || action_server.isPreemptRequested()){
        return;
      }

      if(goal->count <= progress){
        ROS_INFO("%s Succeded at getting to goal %d" , action_name.c_str() , goal->count);
        action_result.final_count = progress;
        action_server.setSucceeded(action_result);
      }
      else {
        ROS_INFO("Setting to goal %d / %d", action_feedback.current_number , goal->count);
        action_feedback.current_number = progress;
        action_server.publishFeedback(action_feedback);
      }
      rate.sleep();
   }
  }
};

int main(int argc, char **argv)
{
  ros::init(argc, argv, "action_server");
  ROS_INFO("Start Action Server");
  demo_actionAction demo_actionAction("demo_action");

  ros::spin();
  return 0;
}
