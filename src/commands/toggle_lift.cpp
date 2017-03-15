#include "toggle_lift.hpp"

#include "../subsystems/subsystems.hpp"

Toggle_Lift::Toggle_Lift(bool is_on) :
is_on (is_on) {
	Requires(Subsystems::lift);
}

void Toggle_Lift::Initialize() {
	if (is_on) {
		Subsystems::lift->set_motor(0.6);
	} else {
		Subsystems::lift->set_motor(0);
	}
}

bool Toggle_Lift::IsFinished() {
	return true;
}
