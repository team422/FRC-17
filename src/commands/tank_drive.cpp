#include "tank_drive.hpp"
#include "../subsystems/subsystems.hpp"
#include "../user_interface.hpp"

#include <WPILib.h>

Tank_Drive::Tank_Drive() :
IS_DOUBLED(false) {
	Requires(Subsystems::drive_base);
}


void Tank_Drive::Execute() {
  float left_power_scaled = UI::left_joystick->get_y();;

	float right_power_scaled = UI::right_joystick->get_y();

	if(IS_DOUBLED) {
		left_power_scaled *= 2;
		right_power_scaled *= 2;
	}

	Subsystems::drive_base->set_motors_normalized(left_power_scaled, right_power_scaled);
}

bool Tank_Drive::IsFinished() {
	return false;
}

void Tank_Drive::End() {
	Subsystems::drive_base->set_motors_normalized(0, 0);
}
