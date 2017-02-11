#include "autonomous.hpp"
#include "../launchpad.hpp"
#include "../user_interface.hpp"
#include "../subsystems/subsystems.hpp"

#include <WPILib.h>

Autonomous::Autonomous() {
	//See autonomous diagram, or, if there isn't one, see trello for details on making one
	if (UI::Secondary_Driver::launchpad->SWITCH_1->Get()) {
		Subsystems::drive_base->setup_dist_mode();
		Subsystems::drive_base->reset_encoders();
		//do auton seq 1
	} else if (UI::Secondary_Driver::launchpad->SWITCH_2->Get()) {
		Subsystems::drive_base->setup_dist_mode();
		Subsystems::drive_base->reset_encoders();
		//seq 2, etc.
	} else if (UI::Secondary_Driver::launchpad->SWITCH_3->Get()) {
		Subsystems::drive_base->setup_dist_mode();
		Subsystems::drive_base->reset_encoders();
	} else if (UI::Secondary_Driver::launchpad->SWITCH_4->Get()) {
		Subsystems::drive_base->setup_dist_mode();
		Subsystems::drive_base->reset_encoders();
	}
}
