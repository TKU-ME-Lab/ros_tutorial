#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>
#include <iostream>

#include "demo_action/demo_actionAction.h"


int main(int argc, char **argv)
{
  ros::init(argc, argv, "action_client");
  ros::NodeHandle nh;

  if(argc != 3){
    ROS_INFO("%d", argc);
    ROS_WARN("Usage: action_client <goal> <time_to_preempt_in_sec>");
    return 1;
  }

  actionlib::SimpleActionClient<demo_action::demo_actionAction> action_client("demo_action", true);

  ROS_INFO("Waiting for action server to start.");

  action_client.waitForServer();

  ROS_INFO("Action server started, sending goal.");

  demo_action::demo_actionGoal action_goal;
  action_goal.count = atoi(argv[1]);

  ROS_INFO("Sending Foal [%d] and Preempt time of [%d]", action_goal.count , atoi(argv[2]));
  action_client.sendGoal(action_goal);

  bool finished_before_timeout = action_client.waitForResult(ros::Duration(atoi(argv[2])));

  action_client.cancelGoal();

  if(finished_before_timeout){
    actionlib::SimpleClientGoalState client_state = action_client.getState();
    ROS_INFO("Action finished: %s", client_state.toString().c_str());
    action_client.cancelGoal();
  }
  else {
    ROS_INFO("Acion didn't finish before the time out.");
  }
  return 0;
}
