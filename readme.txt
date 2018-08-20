# Unscented Kalman Filter Project

[![Udacity - Self-Driving Car NanoDegree](https://s3.amazonaws.com/udacity-sdc/github/shield-carnd.svg)](http://www.udacity.com/drive)

Self-Driving Car Engineer Nanodegree Program

Overview

---

[//]: # (Image References)

PROJECT DESCRIPTION
The project is an implementation of an Unscented Kalman Filter(UKF) using the CTRV motion model to esitmate the state of a moving object of interest. For the purpose of the project we use Radar and Lidar data detecting a bicyclist nearby. UKF is based on a similar structure to the extended Kalman filter(EKF).

The main file calls a function called ProcessMeasurement, part of the class ukf. This function processes the new Laser or Radar measurements. Once the measurements are processed they are compared against the ground truth value. Testing is achieved using Udacity's simulator which communicates over WebSockets in a JSON format.

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

C++ QUIZZES
The quizzes including the solutions of them are included in the file ukf.cpp. They are individual functions, which don't need any special environment. The solution of the quizzes are given here and also the expected results.
The quizzes can easily evaluated: if every value of the student solution (vectors and matrices) differs less than 0.001 from the original solution, the quizz is passed, otherwise failed.



PROJECT PASSING CRITERIA
There are several criteria that must be fulfilled to pass the project.

- The overall processing chain (prediction, laser update or radar update depending on measurement type) must be correct.
- The student is not allowed to use values from the future to reason about the current state.
- It must be possible to run the project in three different modes: considering laser only, with considering radar only, or with using both sensors.
- For every mode, the overall RMSE (2d position only) may not be more than 10% increased to what the original solution is able to reach (this number depends on the individual measurement sequence)
- The RMSE of laser AND radar must be lower than radar only or laser only
- The NIS of radar measurements must be between 0.35 and 7.81 in at least 80% of all radar update steps.


PROJECT GRADING
- I recommend a hall of fame for the lowest overall RMSE using laser AND radar.
- I recommend to ask students to improve the initialization procedure and evaluate the RMSE during the first 20 steps.








