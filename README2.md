# Carla Wheelchair instricutions
## Downloading carla wheelchair standalone package:
* Using this link, download the package and extract it (compressed folder size = 4.98 gb, once extracted it will be around 12 gb)
https://www.dropbox.com/s/jeabnwhhppdhks7/CARLA_StandalonePackage_9.7.zip?dl=0

## Testing if carla (stand alone package) works:
- Before running any python scripts related to carla, install pygame and numpy:
```pip install --user pygame numpy```
- Navigate to the extracted folder:  /CARLA_Shipping_0.9.7-dirty/LinuxNoEditor/  using the terminal
- Run the command: ```./CarlaUE4.sh```
    - This should open a window displaying the world used by carla
- Open a separate terminal, and go into (cd : CARLA_Shipping_0.9.7-dirty/LinuxNoEditor/PythonAPI/examples
- Inside that directory (PythonAPI/examples) run the command: ```./manual_control.py``` 
  - This should spawn a random vehicle, which can be controlled by using the WASD keys 
- Close that window and run: ```./manual_wc.py``` (inside PythonAPI/examples)
  - This should spawn a wheelchair that can be controlled by using the WASD keys




## Installing carla ROS bridge

- Install carla_ros_bridge using the instructions on this link: https://github.com/carla-simulator/ros-bridge/tree/0.9.6 
  - Note: carla has recently released a new version, alongside carla_ros bridge (v 0.9.9) however the wheelchair carla simulation has been built and tested using CARLA v 0.9.7. Therefore use the older version (make sure branch is “0.9.6 carla ros bridge”) as there may be compatibility issues. 
- Navigate to carla-ros-bridge and enter:   source /opt/ros/<your-ros-version>/setup.bash e.g. if using melodic:     source /opt/ros/melodic/setup.bash
- install required ros-dependencies:
  - ```rosdep update```
  - ```rosdep install --from-paths src --ignore-src -r```
  - ```sudo apt-get install ros-melodic-ros-numpy``` (needed for PointCloud2 functions in python)
- Install joy package using these instructions: http://wiki.ros.org/joy/Tutorials/ConfiguringALinuxJoystick (needed for joystick input)
- Navigate into ~/carla-ros-bridge and run ```catkin_make```

## Downloading carla_package
- Download carla_package and add it to the catkin workspace of your choice
- Go into your workspace and enter: catkin_make       and check if succesful
- If you are unable to run the scripts, you may need to navigate to /carla_package/src/scripts using the terminal and enter: 
```chmod +x script.py``` 
  - E.g. ```chmod +x wc_joy.py```       to make them executable

## Testing if carla ROS bridge works
- (Step 1)Open a terminal and navigate to /CARLA_Shipping_0.9.7-dirty/LinuxNoEditor/   
- (Step 2)Then enter: ```DISPLAY= ./CarlaUE4.sh -opengl -carla-server -quality-level=low``` 
  - This runs carla without creating a separate window. If you want to run carla with a window, simply run: ```./CarlaUE4.sh```  (this may affect the performance of the simulation, when opening another window e.g. ```./manual_control.py```)
- (Step 3)Open another terminal, navigate to /CARLA_Shipping_0.9.7-dirty/LinuxNoEditor/ and enter: 

```export PYTHONPATH=$PYTHONPATH:(path to your egg file)```

- Example: the location of my egg file (inside the carla standalone package there are 2 egg files, use 2.7) is:
 /home/janmart/ExternalDrive/carla/Dist/CARLA_Shipping_0.9.7-dirty/LinuxNoEditor/PythonAPI/carla/dist/carla-0.9.7-py2.7-linux-x86_64.egg
- Therefore the following command would look like:
```export PYTHONPATH=$PYTHONPATH:/home/janmart/ExternalDrive/carla/Dist/CARLA_Shipping_0.9.7-dirty/LinuxNoEditor/PythonAPI/carla/dist/carla-0.9.7-py2.7-linux-x86_64.egg```

- (Step 4)Open another terminal, navigate to /CARLA_Shipping_0.9.7-dirty/LinuxNoEditor/PythonAPI/examples and enter: 
```./wc_ros.py``` 
  - This should open a window containing a wheelchair located inside the carla world





## Moving the wheelchair using ROS and displaying data through rviz
- Repeat Steps 1 - 4 from “Testing if carla ROS bridge works”
- Open another terminal,  navigate to /CARLA_Shipping_0.9.7-dirty/LinuxNoEditor/ and enter: ```rosrun joy joy_node```
- Open another terminal, navigate to /CARLA_Shipping_0.9.7-dirty/LinuxNoEditor/  and enter: ```rosrun carla_package wc_joy.py```
  - This will allow the wheelchair to be moved using joystick input 
- Open another terminal, open rviz and add a topic e.g. /carla/hero/lidar/front/point_cloud/PointCloud2 will display data received by the lidar attached onto the wheelchair (located near it’s center and slightly above it)
   - Change the Fixed Frame to: hero/lidar/front 
