#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <stdlib.h>
#include <turtlesim/Pose.h>


using namespace std;


float xa = 2; // x coordinate  for waypoint
float ya = 2; // y coordinate  for waypoint
float xb = 8; // x coordinate  for end
float yb = 8; // y coordinate  for end
float xr; // x coordinate of the robot
float yr; // y coordinate of the robot
float xba = 0; // AB x vector
float yba = 0; // AB y vector
float ir = 0;  // angular

int lookahead = 2; //

float lx = 0; // lookahead
float ly = 0; // lookahead

float Pose(const turtlesim::Pose::ConstPtr& msg)
{
  float a = msg->x;
  float b = msg->y;
  xr = a;
  yr = b;

}

  int main(int argc, char**argv){
  ros::init(argc, argv, "publish_velocity");

  ros::NodeHandle nh;
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe<turtlesim::Pose>("turtle1/pose", 10, Pose);
  ros::Publisher  pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 10);
  ros::Rate rate(10);
  while(ros::ok()){

  geometry_msgs::Twist msg;
    for(int i =0;i<4;i++){
    msg.linear.x = 0.1;
    msg.angular.z = 0.1;
    pub.publish(msg);
		
	
    cout << "robot x:"<< xr <<"robot y:" << yr << endl;
	
	
}


  ROS_INFO_STREAM("Sending velocity command:"<<" linear="<<msg.linear.x<<" angular="<<msg.angular.z);

  rate.sleep();
  }
return 0;
}
