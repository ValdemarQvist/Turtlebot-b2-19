#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <stdlib.h>
#include <cpp.h>
#include <turtlesim/Pose.h>
#include <>

using namepace std


float xa = 0; // x coordinate  for waypoint 
float ya = 0; // y coordinate  for waypoint 
float xb = 0; // x coordinate  for end 
float yb = 0; // y coordinate  for end
float xr = 0; // x coordinate of the robot
float yr = 0; // y coordinate of the robot
float xba = 0; // AB x vector
float yba = 0; // AB y vector
float ir = 0; // 

int lookahead = 2; //

float lx // lookahead
float ly // lookahead

void Pose(const turtlesim::Pose::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->x());
}

  int main(int argc, char**argv){
  ros::init(argc, argv, "publish_velocity");
  ros::NodeHandle nh;
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("turtlesim/Pose", 1000, Pose);
  ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000);
  ros::Rate rate(2);
  while(ros::ok()){
  geometry_msgs::Twist msg;

    while(xr != xb && yr != yb)
    msg.linear.x = 1;

    pub.publish(msg);

  ROS_INFO_STREAM("Sending random velocity command:"<<" linear="<<msg.linear.x<<" angular="<<msg.angular.z);

  rate.sleep();
  }
}
return 0;
