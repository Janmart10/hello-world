#!/usr/bin/env python
import rospy
from geometry_msgs.msg import Twist
from sensor_msgs.msg import Joy

# This ROS Node converts Joystick inputs from the joy node
# into commands for turtlesim

# Receives joystick messages (subscribed to Joy topic)
# then converts the joysick inputs into Twist commands
# axis 1 aka left stick vertical controls linear speed
# axis 0 aka left stick horizonal controls angular speed

def callback(data, test):
   test.linear.x =  1.5 * data.axes[1]
   print('Linear velocity: ')
   print(test.linear.x)
   test.angular.z =  -1.5 * data.axes[0]
   print('Angular velocity: ')
   print(test.angular.z)
   



def start():
   global pub
   pub = rospy.Publisher('/test', Twist, queue_size=1)
   #pub = rospy.Publisher('/carla/hero/twist_cmd', Twist, queue_size=1)
   # subscribed to joystick inputs on topic "joy"
   twist = Twist()
   rospy.Subscriber("joy", Joy, callback, (twist))
   # starts the node
   rospy.init_node('Joy2Turtle')
   rate = rospy.Rate(pow(10,10))
   while not rospy.is_shutdown():
      pub.publish(twist)
      rate.sleep()
   


   

if __name__ == '__main__':
   start()
