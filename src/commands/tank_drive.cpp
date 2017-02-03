#include "tank_drive.hpp"
#include "../subsystems/subsystems.hpp"
#include "../user_interface.hpp"

#include <WPILib.h>
//#include <math.h> - can use fabs if math.h is usable

Tank_Drive::Tank_Drive() {
	Requires(Subsystems::drive_base);
	is_doubled = false;
}

void Tank_Drive::Execute() {
	float right_x = UI::Primary_Driver::right_stick->GetX();

	float left_y = UI::Primary_Driver::left_stick->GetY();
	float right_y = UI::Primary_Driver::right_stick->GetY();

	float left_power = 0;
	float right_power = 0;

	float left_power_scaled = 0;
	float right_power_scaled = 0;

	//Single Joystick Drive as requested
	if(Subsystems::is_joydrive) {
		//Deadzone for special case
		if ((right_y < .1) || (right_y > -.1)) {
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
			if (right_y < 0) {
				left_power = right_y - right_x;
				right_power = right_y;

				left_power_scaled = 1/(1+(1/(exp(8.5*left_power-4.5))));
				right_power_scaled = 1/(1+(1/(exp(8.5*right_power-4.5))));

			} else if (right_x >= 0) {
				left_power = right_y;
				right_power = right_y - right_x;

				left_power_scaled = 1/(1+(1/(exp(8.5*left_power-4.5))));
				right_power_scaled = 1/(1+(1/(exp(8.5*right_power-4.5))));
			}


		}
	} else if (Subsystems::is_compdrive) {

	}

	else {
		left_power_scaled = left_y;
		right_power_scaled = right_y;
		if(is_doubled) {
			left_power_scaled *= 2;
			right_power_scaled *= 2;
		}
	}


	Subsystems::drive_base->set_motors_normalized(left_power_scaled, right_power_scaled);
}

bool Tank_Drive::IsFinished() {
	return false;
}
