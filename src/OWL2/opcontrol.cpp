#include "main.h"

// Change the controls to match the robot's configuration

// simple intake control
void intakeControl() {
  while (true) {
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
      intake.move_voltage(11500);
    } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
      intake.move_voltage(-11500);
    } else {
      intake.move_voltage(0);
    }
    pros::delay(ez::util::DELAY_TIME);
  }
}
// toggle for right wing control
void rightWingControl() {
  while (true) {
    // 1 button toggle
    wingRight.button_toggle(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1));
    // 2 button toggle
    // wingRight.buttons(master.get_digital(pros::E_CONTROLLER_DIGITAL_X), master.get_digital(pros::E_CONTROLLER_DIGITAL_A));
    pros::delay(ez::util::DELAY_TIME);
  }
}
// toggle for left wing control
void leftWingControl() {
  while (true) {
    // 1 button toggle
    wingLeft.button_toggle(master.get_digital(pros::E_CONTROLLER_DIGITAL_L2));
    // 2 button toggle
    // wingRight.buttons(master.get_digital(pros::E_CONTROLLER_DIGITAL_Y),master.get_digital(pros::E_CONTROLLER_DIGITAL_B));
    pros::delay(ez::util::DELAY_TIME);
  }
}
// toggle for hang control.
void hangControl() {
  while (true) {
    // 1 button toggle
    wingLeft.button_toggle(master.get_digital(pros::E_CONTROLLER_DIGITAL_UP));
    // 2 button toggle
    // wingRight.buttons(master.get_digital(pros::E_CONTROLLER_DIGITAL_UP), master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN));
    pros::delay(ez::util::DELAY_TIME);
  }
}