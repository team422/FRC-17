#include "user_interface.hpp"

Joystick *UI::Primary_Driver::left_stick = new Joystick(1);
Joystick *UI::Primary_Driver::right_stick = new Joystick(2);

Xbox_Controller *UI::Secondary_Driver::controller = new Xbox_Controller(3);

void UI::initialize() {
	//set up all button bindings
}
