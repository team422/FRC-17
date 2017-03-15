#pragma once

#include "attack_3.hpp"
#include "launchpad.hpp"
#include "xbox_controller.hpp"

namespace UI {
	extern Attack_3 *left_joystick;
	extern Attack_3 *right_joystick;
	extern Launchpad *launchpad;
	extern Xbox_Controller *controller;

	void initialize();
}
