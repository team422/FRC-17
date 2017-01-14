#include <subsystems/drive_base.hpp>

#include "../commands/tank_drive.hpp"
#include "../port_mapping.hpp"

Drive_Base::Drive_Base() :
	Subsystem("Drive_Base"),
	left_motor( new Talon(0)),
	right_motor( new Talon(0)) {
}

void Drive_Base::InitDefaultCommand() {
	SetDefaultCommand( new Tank_Drive() );
}

void Drive_Base::set_motors_normalized(float left_speed, float right_speed) {
	left_motor->Set(constrain(left_speed));
	right_motor->Set(constrain(right_speed));
}

float Drive_Base::constrain(float input) {
	if(input > 0.85) {
		input = 0.85;
	}
	else if(input < -0.85) {
		input = -0.85;
	}

	return input;
}
