#pragma once

#include "launchpad.hpp"
#include "xbox_controller.hpp"
#include <WPILib.h>

namespace UI {
	namespace Primary_Driver {
		extern Joystick	*left_stick,
								*right_stick;

		extern JoystickButton	*decrease_bottom_shooter_speed,
								*increase_bottom_shooter_speed,
								*decrease_top_shooter_speed,
								*increase_top_shooter_speed,
								*stop_bottom_shooter,
								*stop_top_shooter;
	}

	namespace Secondary_Driver {
		extern Xbox_Controller *controller;
		extern Launchpad *launchpad;
	}

	void initialize();
}
