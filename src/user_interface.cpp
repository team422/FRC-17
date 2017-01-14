#include "user_interface.hpp"

Joystick *UI::Primary_Driver::left_stick = nullptr;
Joystick *UI::Primary_Driver::right_stick = nullptr;

Xbox_Controller *UI::Secondary_Driver::controller = nullptr;

void UI::initialize() {
	Primary_Driver::left_stick = new Joystick(1);
	Primary_Driver::right_stick = new Joystick(2);
	Secondary_Driver::controller = new Xbox_Controller(0);
}
