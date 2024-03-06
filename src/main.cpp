#include "main.h"

/////
// For installation, upgrading, documentations and tutorials, check out our
// website! https://ez-robotics.github.io/EZ-Template/
/////

// Chassis constructor
ez::Drive chassis(
    // Left Chassis Ports (negative port will reverse it!)
    //   the first port is used as the sensor
    {-16, 17, -19, 20},

    // Right Chassis Ports (negative port will reverse it!)
    //   the first port is used as the sensor
    {-11, 13, -14, 15},

    // IMU Port
    6,

    // Wheel Diameter (Remember, 4" wheels without screw holes are
    // actually 4.125!)
    3.25,

    // Cartridge RPM
    600,

    // External Gear Ratio (MUST BE DECIMAL) This is WHEEL GEAR / MOTOR GEAR
    // eg. if your drive is 84:36 where the 36t is powered, your RATIO would be
    // 84/36 which is 2.333 eg. if your drive is 36:60 where the 60t is powered,
    // your RATIO would be 36/60 which is 0.6
    0.6666666667);

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
  // Print our branding over your terminal :D
  ez::ez_template_print();

  // Stop the user from doing anything while legacy ports configure
  pros::delay(500);

  // Configure your chassis controls

  // Sets the active brake kP. We recommend 0.1.
  chassis.opcontrol_drive_activebrake_set(0.1);

  // Defaults for curve. If using tank, only the first parameter is  used.
  // (Comment this line out if you have an SD card!)
  chassis.opcontrol_curve_default_set(0, 0);

  // Set the drive to your own constants from autons.cpp!
  default_constants();

  // Autonomous Selector using LLEMU
  ez::as::auton_selector.autons_add({
      Auton("example auton description", autonomous_1),
  });

  // Initialize chassis and auton selector
  chassis.initialize();
  ez::as::initialize();
  master.rumble(". . .");
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
  // . . .
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
  // . . .
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
  // Resets PID targets to 0
  chassis.pid_targets_reset();

  // Reset gyro position to 0
  chassis.drive_imu_reset();

  // Reset drive sensors to 0
  chassis.drive_sensor_reset();

  // Set motors to hold.  This helps autonomous consistency
  chassis.drive_brake_set(MOTOR_BRAKE_HOLD);

  // Calls selected auton from autonomous selector
  ez::as::auton_selector.selected_auton_call();
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
  // tasks for opcontrol functions. These are used for toggles and other
  // functions
  pros::Task intakeControlTask(intakeControl);
  pros::Task rightWingControlTask(rightWingControl);
  pros::Task leftWingControlTask(leftWingControl);
  pros::Task hangControlTask(hangControl);
  // This is preference to what you like to drive on
  chassis.drive_brake_set(MOTOR_BRAKE_COAST);

  while (true) {
    chassis.opcontrol_arcade_standard(ez::SPLIT);
    // This is used for timer calculations! Keep this ez::util::DELAY_TIME
    pros::delay(ez::util::DELAY_TIME);
  }
}