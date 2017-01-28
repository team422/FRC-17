#include "shooter.hpp"
#include <WPILib.h>

#include "../commands/shooter_command.hpp"
#include "../port_mapping.hpp"

Shooter::Shooter() :
	Subsystem("Shooter"),
	top_motor(new CANTalon(Ports::CANBusIDs::TOP_SHOOTER_MOTOR)),
	bot_motor(new CANTalon(Ports::CANBusIDs::BOTTOM_SHOOTER_MOTOR)),
	top_speed(0),
	bot_speed(0) {
	top_motor->Set(0);
	bot_motor->Set(0);
}

void Shooter::InitDefaultCommand() {
	SetDefaultCommand(new Shooter_Command());
}

void Shooter::continue_motor() {
	top_motor->Set(top_speed);
	bot_motor->Set(bot_speed);
}

float Shooter::get_bot_speed() {
	return bot_speed;
}

float Shooter::get_top_speed() {
	return top_speed;
}

void Shooter::set_bot_speed(float input) {
	bot_speed = input;
}

void Shooter::set_top_speed(float input) {
	top_speed = input;
}

float constrain(float input) {
	if (input > 1) {
		return 1;
	} else if (input < -1) {
		return -1;
	}

	return input;
}
