#include "comp_drive.hpp"
#include "../subsystems/subsystems.hpp"
#include "../user_interface.hpp"

#include <WPILib.h>

Comp_Drive::Comp_Drive() {
  Requires(Subsystems::drive_base);
}

void Comp_Drive::Execute() {
  float accel_value = UI::Primary_Driver::right_stick->get_y();
  float turn_value = UI::Primary_Driver::left_stick->get_x();

  if(accel_value < turn_value) {
	float pwr = Comp_Drive::scale_turn(turn_value);
    Subsystems::drive_base->set_motors_normalized(pwr, -pwr);
  } else if(turn_value < accel_value) {
    Subsystems::drive_base->set_motors_normalized(accel_value, accel_value);
  }
}

bool Comp_Drive::IsFinished() {
  return false;
}

float Comp_Drive::scale_turn(float turn_value) {
  return (turn_value * 0.6);
}
