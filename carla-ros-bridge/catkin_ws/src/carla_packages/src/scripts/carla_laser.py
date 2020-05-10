#!/usr/bin/env python
import rospy

from sensor_msgs.msg import LaserScan

#list = []
minRange = pow(10,10)

def callback(msg, args):
    #minRange = pow(10,10)
    global minRange
    #print(len(msg.ranges))
    #print((msg.ranges[359])) #located around the back at msg.ranges[0]
    #print(msg.ranges[180]) #90 is on the right side, 180 is front
    print(msg.ranges[90]) #270 is on the left side of wheelchair
    # print('angle min')
    # print(msg.angle_min)
    # print('angle max')
    # print(msg.angle_max)
    # print('angle increment')
    # print(msg.angle_increment)
    for x in range(len(msg.ranges)):
        if (msg.ranges[x] > 0 and msg.ranges[x] < pow(10,10)):
            if (minRange > msg.ranges[x] and msg.ranges[x] != 0):
                minRange = msg.ranges[x]
                # print('new minRange is')
                # print(minRange)
            #print(msg.ranges[x])
    #print(msg.ranges)

def loop():
    rospy.init_node('ranges')
    #minRange = pow(10, 10)
    maxRange = 0
    #sub = rospy.Subscriber('/scan', LaserScan, callback, (minRange, maxRange))
    sub = rospy.Subscriber('/scan', LaserScan, callback, (maxRange))
    rospy.spin()



if __name__ == '__main__':
    loop()
