#include "toggle_climber.hpp"

#include "../subsystems/subsystems.hpp"

Toggle_Climber::Toggle_Climber(bool on, bool half) : on (on), half (half) {
	Requires(Subsystems::climber);
}

void Toggle_Climber::Initialize() {
	if (on) {
		if (half) {
			Subsystems::climber->set_motor(0.4);
		} else {
			Subsystems::climber->set_motor(0.9);
		}
	} else {
		Subsystems::climber->set_motor(0);
	}
}

bool Toggle_Climber::IsFinished() {
	return true;
}
