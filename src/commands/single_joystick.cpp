#include "./single_joystick.hpp"
#include "../subsystems/subsystems.hpp"
#include "../user_interface.hpp"

#include <WPILib.h>

Single_Joystick::Single_Joystick() {
  Requires(Subsystems::drive_base);
}

void Single_Joystick::Execute() {
  float right_x = UI::Primary_Driver::right_stick->GetX();
	float right_y = UI::Primary_Driver::right_stick->GetY();

	float left_power = 0;
	float right_power = 0;

	float left_power_scaled = 0;
	float right_power_scaled = 0;

  //Deadzone for special case
  if ((right_y < .2 && right_y >= 0) || (right_y > -.2 && right_y <= 0)) {
    right_y /= 2;
    right_x /= 2;
    if (right_x < 0) {
      left_power_scaled = right_y - right_x;
      right_power_scaled = right_y + right_x;
    } else if (right_x >= 0) {
      left_power_scaled = right_y + right_x;
      right_power_scaled = right_y - right_x;
    }
  }

  //Normal joy_drive
  else {
<<<<<<< HEAD
    if (right_x < 0) {
      left_power = right_y - right_x;
      right_power = right_y;

      left_power_scaled = left_power;
      right_power_scaled = right_power;

//      left_power_scaled = 1/(1+(1/(exp(8.5*left_power-4.5))));
//      right_power_scaled = 1/(1+(1/(exp(8.5*right_power-4.5))));
=======
    if (right_y < 0) {
      left_power = right_y - right_x;
      right_power = right_y;

      left_power_scaled = 1/(1+(1/(exp(8.5*left_power-4.5))));
      right_power_scaled = 1/(1+(1/(exp(8.5*right_power-4.5))));
>>>>>>> origin/feat/change_drive

    } else if (right_x >= 0) {
      left_power = right_y;
      right_power = right_y - right_x;

<<<<<<< HEAD
      left_power_scaled = left_power;
      right_power_scaled = right_power;

//      left_power_scaled = 1/(1+(1/(exp(8.5*left_power-4.5))));
//      right_power_scaled = 1/(1+(1/(exp(8.5*right_power-4.5))));
=======
      left_power_scaled = 1/(1+(1/(exp(8.5*left_power-4.5))));
      right_power_scaled = 1/(1+(1/(exp(8.5*right_power-4.5))));
>>>>>>> origin/feat/change_drive
    }
  }

  Subsystems::drive_base->set_motors_normalized(left_power_scaled, right_power_scaled);
}

bool Single_Joystick::IsFinished() {
  return false;
}
