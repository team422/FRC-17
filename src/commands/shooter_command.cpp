#include "shooter_command.hpp"
#include "../subsystems/subsystems.hpp"

Shooter_Command::Shooter_Command() {
	Requires(Subsystems::shooter);
}

void Shooter_Command::Execute() {
	Subsystems::shooter->continue_motors();
}

bool Shooter_Command::IsFinished() {
	return false;
}

void Shooter_Command::End() {
	Subsystems::shooter->set_left_speed(0);
	Subsystems::shooter->set_right_speed(0);
}

void Shooter_Command::Interrupted() {
	Subsystems::shooter->set_left_speed(0);
	Subsystems::shooter->set_right_speed(0);
}
