#include "toggle_shooter.hpp"
#include "../subsystems/subsystems.hpp"

Toggle_Shooter::Toggle_Shooter(bool is_on) :
is_on (is_on) {
	Requires(Subsystems::shooter);
}

void Toggle_Shooter::Initialize() {
	if (is_on) {
		Subsystems::shooter->set_back_speed(.5);
		Subsystems::shooter->set_front_speed(0.2);
	} else {
		Subsystems::shooter->set_back_speed(0);
		Subsystems::shooter->set_front_speed(0);
	}
}

bool Toggle_Shooter::IsFinished() {
	return true;
}
