#!/usr/bin/env python
import rospy
import ros_numpy
import numpy
import numpy as np


from sensor_msgs.msg import PointCloud2
import std_msgs.msg
import sensor_msgs.point_cloud2 as pcl2
from sensor_msgs import point_cloud2
from sensor_msgs.msg import PointField
from std_msgs.msg import Header



minRange = pow(10,10)
pcl = PointCloud2()
pclHeader = None
pclFields = None 

original_pcl = PointCloud2()

shortestPcl = 0
#need to have installed ros_numpy 
def shortestPoint(array, origin):
    shortestDist = pow(10,10)
    closestPoint = array[0]
    for x in array: 
        #print(x)
        dist = numpy.sqrt(numpy.sum((origin-x)**2))
        if (dist < shortestDist):
            shortestDist = dist
            closestPoint = x
    return closestPoint

def callback(msg):
    global test
    global shortestPcl	
    global pclFields
    global pclHeader
    global pcl
    arr = ros_numpy.point_cloud2.pointcloud2_to_xyz_array(msg)
    print(arr)
    origin = numpy.array((0 ,0, 0))
   
    #find shortest dist in each array, and print it per callback 
    dist = numpy.sqrt(numpy.sum((origin-arr[0])**2))
    #print(dist)

    pcl = msg
    shortestPcl = shortestPoint(arr, origin)
    pclFields = msg.fields 
    pclHeader = msg.header

    #print(shortestPoint(arr, origin)) 

    print('\n')



    

def loop():
    rospy.init_node('ranges')
    pub = rospy.Publisher('/PointCloudTest', PointCloud2, queue_size=1)
    pub_two = rospy.Publisher('/CarlaPointCloud', PointCloud2, queue_size=1)

    #minRange = pow(10, 10)
    maxRange = 0
    #sub = rospy.Subscriber('/carla/hero/lidar/front/point_cloud', PointCloud2, callback, (maxRange))
    sub = rospy.Subscriber('/carla/hero/lidar/front/point_cloud', PointCloud2, callback)
    #rospy.spin()
    #rate = rospy.Rate(pow(10,10)) #original
    rate = rospy.Rate(10)
    
    header = std_msgs.msg.Header()
    header.stamp = rospy.Time.now()
    header.frame_id = 'map'
    scaled_polygon_pcl = None
    new_pcl = None 
    
    while not rospy.is_shutdown():
        # cloud_points = [[shortestPcl]]
        # cloud_points = [[1.0, 1.0, 0.0]]
        if (isinstance(shortestPcl, numpy.ndarray)):
            cloud_points = [ [shortestPcl[0], shortestPcl[1], shortestPcl[2]] ]
            #scaled_polygon_pcl = pcl2.create_cloud_xyz32(header, cloud_points)
            new_pcl = point_cloud2.create_cloud(pclHeader,pclFields, cloud_points)
            print(new_pcl)
            pub.publish(new_pcl) 


            #pub_two.publish(pcl)
            #print(cloud_points)
            #pub.publish(scaled_polygon_pcl)
            #print(scaled_polygon_pcl)
            
       
        rate.sleep()



if __name__ == '__main__':
    loop()




# def shortestPoint(array, origin):
#     shortestDist = pow(10,10)
#     for x in np.nditer(array):
#         # dist = numpy.sqrt(numpy.sum((origin-x)**2))
#         # if (dist < shortestDist):
#         #     shortestDist = dist
#         print(x)
#         print('\n')
#     return shortestDist