#include "vex.h"

vex::controller Controller = vex::controller();
vex::motor FR = vex::motor(PORT1);
vex::motor FL = vex::motor(PORT2);
vex::motor BR = vex::motor(PORT3);
vex::motor BL = vex::motor(PORT4);

//FR = front-right, FL = front-left, BR = back-right, BL = back-left

void mtr_ctl (void) {
  FR.spin(vex::directionType::fwd, Controller.Axis2.value() - Controller.Axis4.value() - Controller.Axis1.value(), vex::velocityUnits::pct);
  FL.spin(vex::directionType::fwd, Controller.Axis2.value() + Controller.Axis4.value() + Controller.Axis1.value(), vex::velocityUnits::pct);
  BR.spin(vex::directionType::fwd, Controller.Axis2.value() - Controller.Axis4.value() + Controller.Axis1.value(), vex::velocityUnits::pct);
  BL.spin(vex::directionType::fwd, Controller.Axis2.value() + Controller.Axis4.value() - Controller.Axis1.value(), vex::velocityUnits::pct);
}