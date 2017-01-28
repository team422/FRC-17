#include "commands/change_shooter_bottom_speed.hpp"
#include "commands/change_shooter_top_speed.hpp"
#include "user_interface.hpp"
#include <WPILib.h>


Joystick *UI::Primary_Driver::left_stick = nullptr;
Joystick *UI::Primary_Driver::right_stick = nullptr;

JoystickButton *UI::Primary_Driver::decrease_bottom_shooter_speed = nullptr;
JoystickButton *UI::Primary_Driver::increase_bottom_shooter_speed = nullptr;
JoystickButton *UI::Primary_Driver::decrease_top_shooter_speed = nullptr;
JoystickButton *UI::Primary_Driver::increase_top_shooter_speed = nullptr;
JoystickButton *UI::Primary_Driver::stop_bottom_shooter = nullptr;
JoystickButton *UI::Primary_Driver::stop_top_shooter = nullptr;

Xbox_Controller *UI::Secondary_Driver::controller = nullptr;
Launchpad *UI::Secondary_Driver::launchpad = nullptr;

void UI::initialize() {
	Primary_Driver::left_stick = new Joystick(3);
	Primary_Driver::right_stick = new Joystick(2);

	Primary_Driver::decrease_bottom_shooter_speed = new JoystickButton(Primary_Driver::left_stick, 2);
	Primary_Driver::increase_bottom_shooter_speed = new JoystickButton(Primary_Driver::left_stick, 3);
	Primary_Driver::decrease_top_shooter_speed = new JoystickButton(Primary_Driver::right_stick, 2);
	Primary_Driver::increase_top_shooter_speed = new JoystickButton(Primary_Driver::right_stick, 3);
	Primary_Driver::stop_bottom_shooter = new JoystickButton(Primary_Driver::left_stick, 1);
	Primary_Driver::stop_top_shooter = new JoystickButton(Primary_Driver::right_stick, 1);

	Primary_Driver::decrease_bottom_shooter_speed->WhenPressed(new Change_Shooter_Bottom_Speed(-1, false));
	Primary_Driver::increase_bottom_shooter_speed->WhenPressed(new Change_Shooter_Bottom_Speed(1, false));
	Primary_Driver::decrease_top_shooter_speed->WhenPressed(new Change_Shooter_Top_Speed(-1, false));
	Primary_Driver::increase_top_shooter_speed->WhenPressed(new Change_Shooter_Top_Speed(1, false));
	Primary_Driver::stop_bottom_shooter->WhenPressed(new Change_Shooter_Bottom_Speed(0, true));
	Primary_Driver::stop_top_shooter->WhenPressed(new Change_Shooter_Top_Speed(0, true));

	Secondary_Driver::controller = new Xbox_Controller(0);
	Secondary_Driver::launchpad = new Launchpad(1);
}
