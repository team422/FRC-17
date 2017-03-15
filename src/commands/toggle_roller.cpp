#include "toggle_roller.hpp"

#include "../subsystems/subsystems.hpp"

Toggle_Roller::Toggle_Roller(bool is_on) :
is_on (is_on) {
	Requires(Subsystems::ball_intake);
}

void Toggle_Roller::Initialize() {
	if (is_on) {
		Subsystems::ball_intake->set_intake_motor(0.85);
	} else {
		Subsystems::ball_intake->set_intake_motor(0);
	}
}

bool Toggle_Roller::IsFinished() {
	return true;
}
