# Unscented Kalman Filter Project

[![Udacity - Self-Driving Car NanoDegree](https://s3.amazonaws.com/udacity-sdc/github/shield-carnd.svg)](http://www.udacity.com/drive)

Self-Driving Car Engineer Nanodegree Program

Overview

---

[//]: # (Image References)

[video]: ./images/result.gif "Video showing tracking performance"
[nis_laser]: ./images/nis_Laser.png "NIS Laser plot"
[nis_radar]: ./images/nis_Radar.png "NIS Radar plot"

PROJECT DESCRIPTION
The project is an implementation of an Unscented Kalman Filter(UKF) using the CTRV motion model to esitmate the state of a moving object of interest. For the purpose of the project we use Radar and Lidar data detecting a bicyclist nearby. UKF is based on a similar structure to the extended Kalman filter(EKF).

The main file calls a function called ProcessMeasurement, part of the class ukf. This function processes the new Laser or Radar measurements. Once the measurements are processed they are compared against the ground truth value. Testing is achieved using Udacity's simulator which communicates over WebSockets in a JSON format.

![alt text][video]

**Project Goals**

The goals / steps of this project are the following:
* Build an Unscented Kalman Filter (UKF) for tracking using Lidar and radar measurments
* Test algorithm against Dataset-1 in the simulator
* Output coordinates px, py, vx, and vy RMSE should be less than or equal to the values  [.09, .10, .40, .30]

**Project Files**

The repository consists of the following files: 
* ./Images/ - Supporting images
* ./src/Eigen - Eigen Library
* ./src/CMakeLists.txt - Code compilation
* ./src/main.cpp - communicates with the Term 2 Simulator receiving data measurements, calls a function to run the Kalman filter, calls a function to calculate RMSE
* ./src/UKF.cpp -  Initializes the filter, calls the predict function, calls the update function
* ./src/tools.cpp - function to calculate RMSE
* ./src/json.cpp - Structuring to communicate with simulator
* ./src/measurement_package.h - Header file for measurement_package.cpp
* ./src/tools.h - Header file for tolls.cpp

**Project Simulator**

This project involves Tracking Simulator which can be downloaded [here](https://github.com/udacity/self-driving-car-sim/releases)

Lidar measurements are red circles, radar measurements are blue circles with an arrow pointing in the direction of the observed angle, and estimation markers are green triangles.

This project involves the Term 2 Simulator which can be downloaded [here](https://github.com/udacity/self-driving-car-sim/releases)

This repository includes two files that can be used to set up and intall [uWebSocketIO](https://github.com/uWebSockets/uWebSockets) for either Linux or Mac systems. For windows you can use either Docker, VMware, or even [Windows 10 Bash on Ubuntu](https://www.howtogeek.com/249966/how-to-install-and-use-the-linux-bash-shell-on-windows-10/) to install uWebSocketIO. Please see [this concept in the classroom](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/16cf4a78-4fc7-49e1-8621-3450ca938b77) for the required version and installation scripts.

**Project Dependencies**

* cmake: 3.5
* make: 4.1 (Linux and Mac), 3.81 (Windows)
* gcc/g++: 5.4
* uWebSocketIO: Use install-ubuntu.sh

**Project Build Instructions**

Once the install for uWebSocketIO is complete, the main program can be built and ran by doing the following from the project top directory.

1. mkdir build
2. cd build
3. cmake ..
4. make
5. ./UnscentedKF

**Other Important Dependencies**
* cmake >= 3.5
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

---

**Dataset**

The dataset consists of simulated lidar and radar measurements detecting a bicycle that travels around the vehicle.

Each row represents a sensor measurement where the first column tells you if the measurement comes from radar (R) or lidar (L).

For a row containing radar data, the columns are: 

```sensor_type, rho_measured, phi_measured, rhodot_measured, timestamp, x_groundtruth, y_groundtruth, vx_groundtruth, vy_groundtruth, yaw_groundtruth, yawrate_groundtruth.```


```For a row containing lidar data, the columns are: sensor_type, x_measured, y_measured, timestamp, x_groundtruth, y_groundtruth, vx_groundtruth, vy_groundtruth, yaw_groundtruth, yawrate_groundtruth.```

**Results**

The project goal of keeping RMSE values less than or equal to the values [.09, .10, .40, .30] was acheived. The final RMSE values for tracking using lidar and radar measurements were:

| Px     | Py     | Vx     | Vy     |
|--------|--------|--------|--------|
| 0.0841 | 0.0926 | 0.3847 | 0.2542 |

NIS - Laser Plot

![alt text][nis_laser]

NIS - Radar Plot

![alt text][nis_radar]
