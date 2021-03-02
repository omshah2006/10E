/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
vex::motor FR = vex::motor(PORT10);
vex::motor FL = vex::motor(PORT1);
vex::motor BR = vex::motor(PORT19);
vex::motor BL = vex::motor(PORT12);
vex::motor rintake = vex::motor(PORT15);
vex::motor lintake = vex::motor(PORT16);
vex::controller Controller = vex::controller();
// ---- END VEXCODE CONFIGURED DEVICES ----

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/



void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................

  FR.spin(directionType::rev, 100, percentUnits::pct); //forward
  BR.spin(directionType::rev, 100, percentUnits::pct);
  FL.spin(directionType::fwd, 100, percentUnits::pct);
  BL.spin(directionType::fwd, 100, percentUnits::pct);

  vex::task::sleep(1900);

  FR.stop();
  BR.stop();
  FL.stop();
  BL.stop();
  vex::task::sleep(300);

  FR.spin(directionType::rev, 100, percentUnits::pct); //turn
  BR.spin(directionType::rev, 100, percentUnits::pct);
  FL.spin(directionType::rev, 100, percentUnits::pct);
  BL.spin(directionType::rev, 100, percentUnits::pct);

  vex::task::sleep(200);

  FR.stop();
  BR.stop();
  FL.stop();
  BL.stop();
  vex::task::sleep(300);

  FR.spin(directionType::rev, 100, percentUnits::pct); //forward
  BR.spin(directionType::rev, 100, percentUnits::pct);
  FL.spin(directionType::fwd, 100, percentUnits::pct);
  BL.spin(directionType::fwd, 100, percentUnits::pct);

  vex::task::sleep(500);
  FR.stop();
  BR.stop();
  FL.stop();
  BL.stop();
  vex::task::sleep(300);

  FR.spin(directionType::fwd, 100, percentUnits::pct); //right
  BR.spin(directionType::fwd, 100, percentUnits::pct);
  FL.spin(directionType::fwd, 100, percentUnits::pct);
  BL.spin(directionType::fwd, 100, percentUnits::pct);

  vex::task::sleep(700);
  FR.stop();
  BR.stop();
  FL.stop();
  BL.stop();
  vex::task::sleep(400);

  FR.spin(directionType::rev, 100, percentUnits::pct); //forward
  BR.spin(directionType::rev, 100, percentUnits::pct);
  FL.spin(directionType::fwd, 100, percentUnits::pct);
  BL.spin(directionType::fwd, 100, percentUnits::pct);

  vex::task::sleep(200);
  FR.stop();
  BR.stop();
  FL.stop();
  BL.stop();
  vex::task::sleep(300);

  FR.spin(directionType::rev, 100, percentUnits::pct); //left
  BR.spin(directionType::rev, 100, percentUnits::pct);
  FL.spin(directionType::rev, 100, percentUnits::pct);
  BL.spin(directionType::rev, 100, percentUnits::pct);

  vex::task::sleep(700);

  FR.stop();
  BR.stop();
  FL.stop();
  BL.stop();
  vex::task::sleep(400);

  FR.spin(directionType::rev, 100, percentUnits::pct); //forward
  BR.spin(directionType::rev, 100, percentUnits::pct);
  FL.spin(directionType::fwd, 100, percentUnits::pct);
  BL.spin(directionType::fwd, 100, percentUnits::pct);

  vex::task::sleep(200);
  FR.stop();
  BR.stop();
  FL.stop();
  BL.stop();
  vex::task::sleep(300);

  FR.spin(directionType::fwd, 100, percentUnits::pct); //left
  BR.spin(directionType::fwd, 100, percentUnits::pct);
  FL.spin(directionType::fwd, 100, percentUnits::pct);
  BL.spin(directionType::fwd, 100, percentUnits::pct);

  vex::task::sleep(700);
  FR.stop();
  BR.stop();
  FL.stop();
  BL.stop();
  vex::task::sleep(400);


}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    FR.spin(vex::directionType::fwd, (Controller.Axis1.value() - Controller.Axis3.value()), vex::velocityUnits::pct);
    FL.spin(vex::directionType::fwd, (Controller.Axis1.value() + Controller.Axis3.value()), vex::velocityUnits::pct);
    BR.spin(vex::directionType::fwd, (Controller.Axis1.value() - Controller.Axis3.value()), vex::velocityUnits::pct);
    BL.spin(vex::directionType::fwd, (Controller.Axis1.value() + Controller.Axis3.value()), vex::velocityUnits::pct);
    
    while(Controller.ButtonR1.pressing()) {
      rintake.spin(directionType::fwd, 20, velocityUnits::pct);
      lintake.spin(directionType::fwd, -20, velocityUnits::pct);
    }

    while(Controller.ButtonR2.pressing()) {
      rintake.spin(directionType::fwd, -20, velocityUnits::pct);
      lintake.spin(directionType::fwd, 20, velocityUnits::pct);
    }
  
    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
