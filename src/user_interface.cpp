#include "commands/change_shooter_speed.hpp"
#include "user_interface.hpp"
#include <WPILib.h>


Joystick *UI::Primary_Driver::left_stick = nullptr;
Joystick *UI::Primary_Driver::right_stick = nullptr;

JoystickButton *UI::Primary_Driver::decrease_left_shooter_speed = nullptr;
JoystickButton *UI::Primary_Driver::increase_left_shooter_speed = nullptr;
JoystickButton *UI::Primary_Driver::decrease_right_shooter_speed = nullptr;
JoystickButton *UI::Primary_Driver::increase_right_shooter_speed = nullptr;
JoystickButton *UI::Primary_Driver::stop_left_shooter = nullptr;
JoystickButton *UI::Primary_Driver::stop_right_shooter = nullptr;

Xbox_Controller *UI::Secondary_Driver::controller = nullptr;

void UI::initialize() {
	Primary_Driver::left_stick = new Joystick(2);
	Primary_Driver::right_stick = new Joystick(3);

	Primary_Driver::decrease_left_shooter_speed = new JoystickButton(Primary_Driver::left_stick, 2);
	Primary_Driver::increase_left_shooter_speed = new JoystickButton(Primary_Driver::left_stick, 3);
	Primary_Driver::decrease_right_shooter_speed = new JoystickButton(Primary_Driver::right_stick, 2);
	Primary_Driver::increase_right_shooter_speed = new JoystickButton(Primary_Driver::right_stick, 3);
	Primary_Driver::stop_left_shooter = new JoystickButton(Primary_Driver::left_stick, 1);
	Primary_Driver::stop_right_shooter = new JoystickButton(Primary_Driver::right_stick, 1);

	Primary_Driver::decrease_left_shooter_speed->WhenPressed(new Change_Shooter_Speed(0, -1, false));
	Primary_Driver::increase_left_shooter_speed->WhenPressed(new Change_Shooter_Speed(0, 1, false));
	Primary_Driver::decrease_right_shooter_speed->WhenPressed(new Change_Shooter_Speed(1, -1, false));
	Primary_Driver::increase_right_shooter_speed->WhenPressed(new Change_Shooter_Speed(1, 1, false));
	Primary_Driver::stop_left_shooter->WhenPressed(new Change_Shooter_Speed(0, 0, true));
	Primary_Driver::stop_right_shooter->WhenPressed(new Change_Shooter_Speed(1, 0, true));

	Secondary_Driver::controller = new Xbox_Controller(0);


}
