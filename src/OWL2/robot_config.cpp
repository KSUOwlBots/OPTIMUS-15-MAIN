#include "EZ-Template/piston.hpp"
#include "main.h"

// Change the port numbers to match the robot's configuration
pros::Motor intakeLeft(10, pros::E_MOTOR_GEAR_600, false,
                       pros::E_MOTOR_ENCODER_ROTATIONS);
pros::Motor intakeRight(2, pros::E_MOTOR_GEAR_600, true,
                        pros::E_MOTOR_ENCODER_ROTATIONS);
pros::Motor_Group intake({intakeLeft, intakeRight});
ez::Piston wingLeft{'A', false};
ez::Piston wingRight{'B', false};
ez::Piston hang{'C', false};
