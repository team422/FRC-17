#pragma once

#include <WPILib.h>

class Attack_3 {
public:
	Attack_3(uint32_t port);
	float get_x();
	float get_y();
private:
	Joystick * joystick;
public:
	Button * const TRIGGER;
	Button * const BUTTON_2;
	Button * const BUTTON_3;
	Button * const BUTTON_4;
	Button * const BUTTON_5;
};
