#pragma once

#include "xbox_controller.hpp"
#include <WPILib.h>

namespace UI {
	namespace Primary_Driver {
		extern Joystick *left_stick,
						*right_stick;
	}

	namespace Secondary_Driver {
		extern Xbox_Controller *controller;
	}

	void initialize();
}
