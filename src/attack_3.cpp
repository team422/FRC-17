#include "attack_3.hpp"

Attack_3::Attack_3(uint32_t port) :
	joystick (new Joystick(port)),
	TRIGGER (new JoystickButton(joystick, 1)),
	BUTTON_2 (new JoystickButton(joystick, 2)),
	BUTTON_3 (new JoystickButton(joystick, 3)),
	BUTTON_4 (new JoystickButton(joystick, 4)),
	BUTTON_5 (new JoystickButton(joystick, 5)) {

}

float Attack_3::get_x() {
	return joystick->GetX();
}

float Attack_3::get_y() {
	return joystick->GetY();
}
