#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include <sstream>
#include "turtlesim/Pose.h"


using namespace std;

ros::Publisher pub;
ros::Subscriber pose_subscriber;
turtlesim::Pose turtlesim_pose;
const double PI =3.14159265359;
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



void poseCallback(const turtlesim::Pose::ConstPtr & msg);

  int main(int argc, char**argv){

  ros::init(argc, argv, "helmsman");
  ros::NodeHandle n;

  pose_subscriber = n.subscribe("/turtle1/pose",10 , poseCallback);
  pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);
  ros::Rate rate(10);
  while(ros::ok()){

  geometry_msgs::Twist msg;
    for(int i =0;i<4;i++){
    msg.linear.x = 0.1;
    msg.angular.z = 0.1;
    pub.publish(msg);

cout<<"Send command:"<<" linear="<<msg.linear.x<<" angular="<<msg.angular.z<<
"/nrobot x: "<<xr<<"robot y: " << yr<<"looking i direction: "<<ir*180/PI <<endl;
ros::spinOnce();
}




  rate.sleep();
  }
return 0;
};


void poseCallback(const turtlesim::Pose::ConstPtr & msg)
{
      xr = msg->x;
      yr = msg->y;
      ir = msg->theta;

};
