#!/usr/bin/env python
import rospy
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry
from std_msgs.msg import Header 
from sensor_msgs.msg import Joy

# This ROS Node converts Joystick inputs from the joy node
# into commands for turtlesim

# Receives joystick messages (subscribed to Joy topic)
# then converts the joysick inputs into Twist commands
# axis 1 aka left stick vertical controls linear speed
# axis 0 aka left stick horizonal controls angular speed
joystick_input = Odometry()

def callback(data, test):
   global joystick_input
   joystick_input.header = Header()
   joystick_input.header.frame_id = 'map'
   joystick_input.pose.pose.position.x  = data.axes[1]
   joystick_input.pose.pose.position.y = data.axes[0]
   #joystick_input.pose.pose.orientation.z = 0
   
   #Section for retrieving joy input and storing it in a twist message 
   test.linear.x =  1.5 * data.axes[1]
   print('Linear velocity: ')
   print(test.linear.x)
   test.angular.z =  -1.5 * data.axes[0]
   print('Angular velocity: ')
   print(test.angular.z)
   
def temp_callback(data):
   print(data)


def start():
   global pub
   pub = rospy.Publisher('/test', Twist, queue_size=1)
   odom_pub = rospy.Publisher('/test_input', Odometry, queue_size=1)
   #pub = rospy.Publisher('/carla/hero/twist_cmd', Twist, queue_size=1)
   # subscribed to joystick inputs on topic "joy"
   twist = Twist()
   rospy.Subscriber("joy", Joy, callback, (twist))
   #rospy.Subscriber("/carla/hero/odometry", Odometry, temp_callback)
   # starts the node
   rospy.init_node('Joy2Turtle')
   rate = rospy.Rate(pow(10,10))
   while not rospy.is_shutdown():
      pub.publish(twist)
      odom_pub.publish(joystick_input)
      rate.sleep()
   


   

if __name__ == '__main__':
   start()
