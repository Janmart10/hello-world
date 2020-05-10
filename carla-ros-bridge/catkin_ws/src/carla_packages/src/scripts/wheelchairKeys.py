#!/usr/bin/env python
import getch
import rospy
from std_msgs.msg import String #String message
from std_msgs.msg import Int8
from geometry_msgs.msg import Twist




def keys():
    #pub = rospy.Publisher('keys',Int8,queue_size=10) # "key" is the publisher name
    vel_msg = Twist()
    velocity_publisher = rospy.Publisher('/carla/hero/twist_cmd', Twist, queue_size=10)
    rospy.init_node('keypress',anonymous=True)
    rate = rospy.Rate(10)#try removing this line ans see what happens
    while not rospy.is_shutdown():
        print('Running Keys script')
        k=ord(getch.getch())# this is used to convert the keypress event in the keyboard or joypad , joystick to a ord value
        if (k==65):
            vel_msg.linear.x = 6
            rospy.loginfo(str(k))
            rospy.loginfo('UP')
        elif (k==66):
            vel_msg.linear.x = -6
            rospy.loginfo(str(k))
            rospy.loginfo('DOWN')
        elif ((k==68)):
            vel_msg.angular.z = -3
            rospy.loginfo(str(k))
            rospy.loginfo('LEFT')
        elif (k==67):
            vel_msg.angular.z = 3
            rospy.loginfo(str(k))
            rospy.loginfo('RIGHT')
        else:
            vel_msg.linear.x = 0
            vel_msg.angular.z = 0
        #pub.publish(k)
        #rospy.loginfo(str(k))
        velocity_publisher.publish(vel_msg)

        #rate.sleep()

#s=115,e=101,g=103,b=98



if __name__=='__main__':
    try:
        keys()
        #move()
    except rospy.ROSInterruptException:
        pass
