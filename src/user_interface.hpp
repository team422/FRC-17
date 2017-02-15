#pragma once

#include "attack_3.hpp"
#include "launchpad.hpp"
#include "xbox_controller.hpp"
#include <WPILib.h>

namespace UI {
	namespace Primary_Driver {
		extern Attack_3	*left_stick,
						*right_stick;
	}

	namespace Secondary_Driver {
		extern Xbox_Controller *controller,
								*toggle_gear_intake;
		extern Launchpad *launchpad;
	}

	void initialize();
}
