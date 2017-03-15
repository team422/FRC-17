#include "lift.hpp"
#include "../port_mapping.hpp"

Lift::Lift() :
Subsystem("Lift"),
lift_motor (new CANTalon(Ports::CANBusIds::LIFT_MOTOR)) {
	lift_motor->Set(0);
}

void Lift::InitDefaultCommand() {
	SetDefaultCommand(nullptr);
}

void Lift::set_motor(float speed) {
	lift_motor->Set(constrain(speed));
}

float Lift::constrain(float input) {
	if (input > 0.85) {
		return 0.85;
	} else if (input < -0.85) {
		return -0.85;
	}
	return input;
}
