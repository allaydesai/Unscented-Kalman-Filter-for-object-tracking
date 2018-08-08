#include "ukf.h"
#include "Eigen/Dense"
#include <iostream>

using namespace std;
using Eigen::MatrixXd;
using Eigen::VectorXd;
using std::vector;

/**
 * Initializes Unscented Kalman filter
 * This is scaffolding, do not modify
 */
UKF::UKF() {
  // if this is false, laser measurements will be ignored (except during init)
  use_laser_ = true;

  // if this is false, radar measurements will be ignored (except during init)
  use_radar_ = true;

  // initial state vector
  x_ = VectorXd(5);

  // initial covariance matrix
  P_ = MatrixXd(5, 5);

  // Process noise standard deviation longitudinal acceleration in m/s^2
  std_a_ = 30;

  // Process noise standard deviation yaw acceleration in rad/s^2
  std_yawdd_ = 30;
  
  //DO NOT MODIFY measurement noise values below these are provided by the sensor manufacturer.
  // Laser measurement noise standard deviation position1 in m
  std_laspx_ = 0.15;

  // Laser measurement noise standard deviation position2 in m
  std_laspy_ = 0.15;

  // Radar measurement noise standard deviation radius in m
  std_radr_ = 0.3;

  // Radar measurement noise standard deviation angle in rad
  std_radphi_ = 0.03;

  // Radar measurement noise standard deviation radius change in m/s
  std_radrd_ = 0.3;
  //DO NOT MODIFY measurement noise values above these are provided by the sensor manufacturer.
  
  /**
  TODO:

  Complete the initialization. See ukf.h for other member properties.

  Hint: one or more values initialized above might be wildly off...
  */
  time_us_ = 0;
  is_initialized_ = false;
   ///* State dimension
  n_x_ = 5;

  ///* Augmented state dimension
  n_aug_ = 7;

  ///* predicted sigma points matrix
  Xsig_pred_ = MatrixXd(n_x_, 2 * n_aug_ + 1);
  ///* Weights of sigma points
  weights_ = VectorXd(2*n_aug_+1);
 
  ///* Sigma point spreading parameter
  lambda_ = 3 - n_aug_;
}

/**
* Destructor.
*/
UKF::~UKF() {}

/**
 * @param {MeasurementPackage} meas_package The latest measurement data of
 * either radar or laser.
 */
void UKF::ProcessMeasurement(MeasurementPackage meas_package) {
  /**
  TODO:

  Complete this function! Make sure you switch between lidar and radar
  measurements.
  */
  if (!is_initialized_)
  {
    //first measurement
    x_ << 0, 0, 0, 0, 0;

    // covariance matrix
    P_ << 1, 0, 0, 0, 0,
          0, 1, 0, 0, 0,
          0, 0, 10,0, 0,
          0, 0, 0,10, 0,
          0, 0, 0, 0,10;

    //Initialize state with first measurements
    if (meas_package.sensor_type_ == MeasurementPackage::RADAR)
    {
      // Retreive raw values
      float rho = meas_package.raw_measurements_(0);
      float theta = meas_package.raw_measurements_(1);
      float ro_dot = meas_package.raw_measurements_(2);
      // conversion from polar to cartesian coordinate system
      x_[0] = rho * cos(theta);
      x_[1] = rho * sin(theta);
      x_[2] = ro_dot;
    }
    else if (meas_package.sensor_type_ == MeasurementPackage::LASER)
    {
      // map raw values directly, already cartesian
      x_[0] = meas_package.raw_measurements_(0); //px
      x_[1] = meas_package.raw_measurements_(1); //py
    }

    //compute the time elapsed between current and previous measurements
    float delta_t = (meas_package.timestamp_ - time_us_)/ 1000000.0;
    time_us_ = meas_package.timestamp_;

    is_initialized_ = true;
    return;

  }
  
  //compute the time elapsed between current and previous measurements
  float delta_t = (meas_package.timestamp_ - time_us_)/ 1000000.0;
  
  //Predict
  Prediction(delta_t);
  //check sensor type for update
  if (meas_package.sensor_type_ == MeasurementPackage::RADAR and use_radar_)
  {
    UpdateRadar(meas_package);
  }
  if (meas_package.sensor_type_ == MeasurementPackage::LASER and use_laser_)
  {
    UpdateLidar(meas_package);
  }
  // update last timestep with current time
  time_us_ = meas_package.timestamp_;
  
}

/**
 * Predicts sigma points, the state, and the state covariance matrix.
 * @param {double} delta_t the change in time (in seconds) between the last
 * measurement and this one.
 */
void UKF::Prediction(double delta_t) {
  /**
  TODO:

  Complete this function! Estimate the object's location. Modify the state
  vector, x_. Predict sigma points, the state, and the state covariance matrix.
  */


}

/**
 * Updates the state and the state covariance matrix using a laser measurement.
 * @param {MeasurementPackage} meas_package
 */
void UKF::UpdateLidar(MeasurementPackage meas_package) {
  /**
  TODO:

  Complete this function! Use lidar data to update the belief about the object's
  position. Modify the state vector, x_, and covariance, P_.

  You'll also need to calculate the lidar NIS.
  */
}

/**
 * Updates the state and the state covariance matrix using a radar measurement.
 * @param {MeasurementPackage} meas_package
 */
void UKF::UpdateRadar(MeasurementPackage meas_package) {
  /**
  TODO:

  Complete this function! Use radar data to update the belief about the object's
  position. Modify the state vector, x_, and covariance, P_.

  You'll also need to calculate the radar NIS.
  */
}