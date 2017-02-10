#include "tank_drive.hpp"
#include "../subsystems/subsystems.hpp"
#include "../user_interface.hpp"

#include <WPILib.h>
//#include <math.h> - can use fabs if math.h is usable

Tank_Drive::Tank_Drive() :
IS_DOUBLED(false) {
	Requires(Subsystems::drive_base);
}

void Tank_Drive::Execute() {
  float left_power_scaled = UI::Primary_Driver::left_stick->GetY();
	float right_power_scaled = UI::Primary_Driver::right_stick->GetY();

	if(IS_DOUBLED) {
		left_power_scaled *= 2;
		right_power_scaled *= 2;
	}

	Subsystems::drive_base->set_motors_normalized(left_power_scaled, right_power_scaled);
}

bool Tank_Drive::IsFinished() {
	return false;
}
