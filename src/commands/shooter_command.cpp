#include "shooter_command.hpp"
#include "../subsystems/subsystems.hpp"

Shooter_Command::Shooter_Command() {
	Requires(Subsystems::shooter_bottom);
}

void Shooter_Command::Execute() {
	Subsystems::shooter_bottom->continue_motor();
}

bool Shooter_Command::IsFinished() {
	return false;
}

void Shooter_Command::Interrupted() {
}

void Shooter_Command::End() {
	Subsystems::shooter_bottom->set_bottom_speed(0);
}
