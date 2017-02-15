#include "comp_drive.hpp"
#include "../subsystems/subsystems.hpp"
#include "../user_interface.hpp"

#include <WPILib.h>

Comp_Drive::Comp_Drive() {
  Requires(Subsystem::drive_base);
}

void Comp_Drive::Execute() {
  float accel_value = UI::Primary_Driver::right_stick->GetY();
  float turn_value = UI::Primary_Driver::left_stick->GetX();

  if(accel_value < turn_value) {
    Subsystems::drive_base->set_motors_normalized(scale_turn(turn_value), -scale_turn(turn_value))
  } else if(turn_value < accel_value) {
    Subsystems::drive_base->set_motors_normalized(accel_value, accel_value);
  }
}

bool Comp_Drive::IsFinished() {
  return false;
}

float scale_turn(float turn_value) {
  return (turn_value * 0.6);
}
