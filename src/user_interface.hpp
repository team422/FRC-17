#pragma once

#include "xbox_controller.hpp"
#include <WPILib.h>

namespace UI {
	namespace Primary_Driver {
		extern Joystick	*left_stick,
								*right_stick;
		extern JoystickButton	*decrease_left_shooter_speed,
								*increase_left_shooter_speed,
								*decrease_right_shooter_speed,
								*increase_right_shooter_speed,
								*stop_left_shooter,
								*stop_right_shooter;
	}

	namespace Secondary_Driver {
		extern Xbox_Controller *controller;
	}

	void initialize();
}
