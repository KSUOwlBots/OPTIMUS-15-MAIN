#include "main.h"
ez::Drive chassis({1, 2, 3}, {-4, -5, -6}, 7, 3.25, 600, 1.6667);
void initialize() {
  ez::ez_template_print();
  pros::delay(500);
  chassis.opcontrol_curve_buttons_toggle(false);
  chassis.opcontrol_drive_activebrake_set(0.1);
  chassis.opcontrol_curve_default_set(5, 5);
  ez::as::auton_selector.autons_add({
      Auton("Example Drive\n\nDrive forward and come back.", drive_example),
      Auton("Example Turn\n\nTurn 3 times.", turn_example),
      Auton("Drive and Turn\n\nDrive forward, turn, come back. ",
            drive_and_turn),
      Auton("Drive and Turn\n\nSlow down during drive.",
            wait_until_change_speed),
      Auton("Swing Example\n\nSwing in an 'S' curve", swing_example),
      Auton("Combine all 3 movements", combining_movements),
      Auton("Interference\n\nAfter driving forward, robot performs differently "
            "if interfered or not.",
            interfered_example),
  });
  chassis.initialize();
  ez::as::initialize();
  master.rumble(".");
}
void disabled() {}
void competition_initialize() {}
void autonomous() {
  chassis.pid_targets_reset();
  chassis.drive_imu_reset();
  chassis.drive_sensor_reset();
  chassis.drive_brake_set(MOTOR_BRAKE_HOLD);
  ez::as::auton_selector.selected_auton_call();
}
void opcontrol() {
  chassis.drive_brake_set(MOTOR_BRAKE_COAST);

  while (true) {

    if (!pros::competition::is_connected()) {
      if (master.get_digital_new_press(DIGITAL_X))
        chassis.pid_tuner_toggle();
      if (master.get_digital_new_press(DIGITAL_B))
        autonomous();
      chassis.pid_tuner_iterate();
    }

    chassis.opcontrol_arcade_standard(ez::SPLIT);
    pros::delay(ez::util::DELAY_TIME);
  }
}
