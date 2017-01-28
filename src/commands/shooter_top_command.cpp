#include "shooter_top_command.hpp"
#include "../subsystems/subsystems.hpp"

Shooter_Top_Command::Shooter_Top_Command() {
	Requires(Subsystems::shooter_top);
}

void Shooter_Top_Command::Execute() {
	Subsystems::shooter_top->continue_motor();
}

bool Shooter_Top_Command::IsFinished() {
	return false;
}

void Shooter_Top_Command::Interrupted() {
}

void Shooter_Top_Command::End() {
	Subsystems::shooter_top->set_top_speed(0);
}
