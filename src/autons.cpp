#include "main.h"
const int DRIVE_SPEED = 110;  
const int TURN_SPEED = 90;
const int SWING_SPEED = 90;

void default_constants() {
  chassis.pid_heading_constants_set(3, 0, 20);
  chassis.pid_drive_constants_set(10, 0, 100);
  chassis.pid_turn_constants_set(3, 0, 20);
  chassis.pid_swing_constants_set(5, 0, 30);

  chassis.pid_turn_exit_condition_set(300_ms, 3_deg, 500_ms, 7_deg, 750_ms, 750_ms);
  chassis.pid_swing_exit_condition_set(300_ms, 3_deg, 500_ms, 7_deg, 750_ms, 750_ms);
  chassis.pid_drive_exit_condition_set(300_ms, 1_in, 500_ms, 3_in, 750_ms, 750_ms);

  chassis.slew_drive_constants_set(7_in, 80);
}

void optimusAuto()
{
  


  //slaps 10 balls

  wingLeft.set(true);
  pros::delay(500);
  wingRight.set(false);
  pros::delay(1000);

  wingLeft.set(true);
  pros::delay(500);
  wingRight.set(false);
  pros::delay(1000);

  wingLeft.set(true);
  pros::delay(500);
  wingRight.set(false);
  pros::delay(1000);

  wingLeft.set(true);
  pros::delay(500);
  wingRight.set(false);
  pros::delay(1000);

  wingLeft.set(true);
  pros::delay(500);
  wingRight.set(false);
  pros::delay(1000);

  wingLeft.set(true);
  pros::delay(500);
  wingRight.set(false);
  pros::delay(1000);

  wingLeft.set(true);
  pros::delay(500);
  wingRight.set(false);
  pros::delay(1000);

  wingLeft.set(true);
  pros::delay(500);
  wingRight.set(false);
  pros::delay(1000);

  wingLeft.set(true);
  pros::delay(500);
  wingRight.set(false);
  pros::delay(1000);

  wingLeft.set(true);
  pros::delay(500);
  wingRight.set(false);
  pros::delay(1000);

  

  



  //drives and trys to score them
  chassis.pid_drive_set(-60_in, 110, true);
  chassis.pid_wait();

  //wingLeft.set(true);
  //pros::delay(500);


  chassis.pid_turn_set(-17_deg, 70, true);
  chassis.pid_wait();




  chassis.pid_drive_set(-220_in, 110, true);
  chassis.pid_wait();


  chassis.pid_swing_set(ez::LEFT_SWING, -145_deg, 110, 0, true);
  chassis.pid_wait();





//wings out

  wingLeft.set(true);
  


  chassis.pid_drive_set(-120_in, 50, true);
  chassis.pid_wait();

  chassis.pid_turn_set(-20, 70, true);
  chassis.pid_wait();


  chassis.pid_drive_set(-70, 110, true);
  chassis.pid_wait();

  chassis.pid_drive_set(40, 70, true);
  chassis.pid_wait();

  chassis.pid_drive_set(-45, 110, true);
  chassis.pid_wait();


  
/*



  keep arm out
  drive a bit
  turn a bit
  drive straight
  deploy left wing
  swing drive
  drive into goal
  keep moving back and forth for a bit into side of goal to make sure they are scored

  
  
  
  
  */

  //chassis.pid_turn_set(90_deg, 45, true);
  //chassis.pid_wait();


}