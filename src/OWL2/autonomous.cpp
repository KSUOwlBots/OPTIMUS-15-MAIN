#include "main.h"

// auton help functions

// time is the time the wing will be open. Default is 1 second
// assuming that false is closed, and that the wing will be normally closed
// if not, swap false and true for either the left or right wing
void wingLeftAuton(int time = 1000) {
  wingLeft.set(true);
  pros::delay(time);
  wingRight.set(false);
  pros::delay(time);
}
void wingRightAuton(int time = 1000) {
  wingLeft.set(true);
  pros::delay(time);
  wingRight.set(false);
  pros::delay(time);
}
// speed is the speed of the intake. Default is 110. The max is 127. The speed is scaled to voltage
// to outtake, set speed to a negative value
// time is the time the intake will run. Default is 1 second
void intakeControlAuton(int speed = 110, int time = 1000) {
  intake.move_voltage((speed * 12000) / 127);
  pros::delay(time);
  intake.move_voltage(0);
}
