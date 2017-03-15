#include "shooter_command.hpp"
#include "../subsystems/subsystems.hpp"

Shooter_Command::Shooter_Command() {
	Requires(Subsystems::shooter);
}

void Shooter_Command::Initialize() {}

void Shooter_Command::Execute() {
	printf("Top Speed: %f\n", Subsystems::shooter->get_top_speed());
	printf("Bottom Speed: %f\n", Subsystems::shooter->get_bottom_speed());
}

bool Shooter_Command::IsFinished() {
	return false;
}

void Shooter_Command::End() {
	Subsystems::shooter->set_bottom_speed(0);
	Subsystems::shooter->set_top_speed(0);
}
