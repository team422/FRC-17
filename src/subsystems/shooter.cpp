#include "shooter.hpp"

#include "../commands/shooter_command.hpp"
#include "../port_mapping.hpp"

Shooter::Shooter() :
Subsystem ("Shooter"),
back_motor (new CANTalon(Ports::CANBusIds::SHOOTER_TOP)),
front_motor (new CANTalon(Ports::CANBusIds::SHOOTER_BOTTOM)),
back_speed (0),
front_motor (0) {
	front_motor->SetInverted(true);
	set_back_speed(0);
	back_motor->ConfigEncoderCodesPerRev(12);
	set_front_speed(0);
	front_motor->ConfigEncoderCodesPerRev(12);
}

void Shooter::InitDefaultCommand() {
	SetDefaultCommand(new Shooter_Command());
}

void Shooter::set_back_speed(float speed) {
	back_speed = constrain(speed);
	back_motor->Set(back_speed);
}

float Shooter::get_back_speed() {
	return back_speed;
}

void Shooter::set_front_speed(float speed) {
	front_motor = constrain(speed);
	front_motor->Set(front_motor);
}

float Shooter::get_front_speed() {
	return front_motor;
}

float Shooter::get_back_encoder_speed() {
	return back_motor->GetSpeed();
}

float Shooter::get_front_encoder_speed() {
	return front_motor->GetSpeed();
}

float Shooter::constrain(float input) {
	if (input > 0.85) {
		return 0.85;
	} else if (input < -0.85) {
		return -0.85;
	}
	return input;
}
