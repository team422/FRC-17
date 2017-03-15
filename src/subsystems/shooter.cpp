#include "shooter.hpp"

#include "../commands/shooter_command.hpp"
#include "../port_mapping.hpp"

Shooter::Shooter() :
Subsystem ("Shooter"),
top_motor (new CANTalon(Ports::CANBusIds::SHOOTER_TOP)),
bottom_motor (new CANTalon(Ports::CANBusIds::SHOOTER_BOTTOM)),
top_speed (0),
bottom_speed (0) {
	bottom_motor->SetInverted(true);
	set_top_speed(0);
	top_motor->ConfigEncoderCodesPerRev(12);
	set_bottom_speed(0);
	bottom_motor->ConfigEncoderCodesPerRev(12);
}

void Shooter::InitDefaultCommand() {
	SetDefaultCommand(new Shooter_Command());
}

void Shooter::set_top_speed(float speed) {
	top_speed = constrain(speed);
	top_motor->Set(top_speed);
}

float Shooter::get_top_speed() {
	return top_speed;
}

void Shooter::set_bottom_speed(float speed) {
	bottom_speed = constrain(speed);
	bottom_motor->Set(bottom_speed);
}

float Shooter::get_bottom_speed() {
	return bottom_speed;
}

float Shooter::get_top_encoder_speed() {
	return top_motor->GetSpeed();
}

float Shooter::get_bottom_encoder_speed() {
	return bottom_motor->GetSpeed();
}

float Shooter::constrain(float input) {
	if (input > 0.85) {
		return 0.85;
	} else if (input < -0.85) {
		return -0.85;
	}
	return input;
}
