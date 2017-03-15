#include "climber.hpp"

#include "../port_mapping.hpp"

Climber::Climber() :
Subsystem("Climber"),
climber (new CANTalon(Ports::CANBusIds::CLIMBER_MOTOR)){
	climber->Set(0);
}

void Climber::set_motor(float speed) {
	climber->Set(constrain(speed));
}

float Climber::constrain(float input) {
	if (input > 0.85) {
		return 0.85;
	} else if (input < -0.85) {
		return -0.85;
	}
	return input;
}
