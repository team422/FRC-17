#include "commands/change_shooter_bot.hpp"
#include "commands/change_shooter_top.hpp"
#include "commands/change_drive.hpp"
#include "user_interface.hpp"

#include <WPILib.h>

Joystick *UI::Primary_Driver::left_stick = nullptr;
Joystick *UI::Primary_Driver::right_stick = nullptr;

JoystickButton *UI::Primary_Driver::decrease_bottom_shooter_speed = nullptr;
JoystickButton *UI::Primary_Driver::decrease_bottom_shooter_half_speed = nullptr;
JoystickButton *UI::Primary_Driver::increase_bottom_shooter_speed = nullptr;
JoystickButton *UI::Primary_Driver::increase_bottom_shooter_half_speed = nullptr;
JoystickButton *UI::Primary_Driver::decrease_top_shooter_speed = nullptr;
JoystickButton *UI::Primary_Driver::decrease_top_shooter_half_speed = nullptr;
JoystickButton *UI::Primary_Driver::increase_top_shooter_speed = nullptr;
JoystickButton *UI::Primary_Driver::increase_top_shooter_half_speed = nullptr;
JoystickButton *UI::Primary_Driver::stop_bottom_shooter = nullptr;
JoystickButton *UI::Primary_Driver::stop_top_shooter = nullptr;
JoystickButton *UI::Primary_Driver::change_joydrive = nullptr;

Xbox_Controller *UI::Secondary_Driver::controller = nullptr;

Launchpad *UI::Secondary_Driver::launchpad = nullptr;

void UI::initialize() {
	Primary_Driver::left_stick = new Joystick(2);
	Primary_Driver::right_stick = new Joystick(3);

	Primary_Driver::decrease_bottom_shooter_speed = new JoystickButton(Primary_Driver::left_stick, 2);
	Primary_Driver::decrease_bottom_shooter_half_speed = new JoystickButton(Primary_Driver::left_stick, 4);
	Primary_Driver::increase_bottom_shooter_speed = new JoystickButton(Primary_Driver::left_stick, 3);
	Primary_Driver::increase_bottom_shooter_half_speed = new JoystickButton(Primary_Driver::left_stick, 5);
	Primary_Driver::decrease_top_shooter_speed = new JoystickButton(Primary_Driver::right_stick, 2);
	Primary_Driver::decrease_top_shooter_half_speed = new JoystickButton(Primary_Driver::right_stick, 4);
	Primary_Driver::increase_top_shooter_speed = new JoystickButton(Primary_Driver::right_stick, 3);
	Primary_Driver::increase_top_shooter_half_speed = new JoystickButton(Primary_Driver::right_stick, 5);
	Primary_Driver::stop_bottom_shooter = new JoystickButton(Primary_Driver::left_stick, 1);
	Primary_Driver::stop_top_shooter = new JoystickButton(Primary_Driver::right_stick, 1);
	Primary_Driver::change_joydrive = new JoystickButton(Primary_Driver::right_stick, 6);

	Primary_Driver::decrease_bottom_shooter_speed->WhenPressed(new Change_Shooter_Bottom_Speed(-1, false));
	Primary_Driver::decrease_bottom_shooter_half_speed->WhenPressed(new Change_Shooter_Bottom_Speed(-0.1, false));
	Primary_Driver::increase_bottom_shooter_speed->WhenPressed(new Change_Shooter_Bottom_Speed(1, false));
	Primary_Driver::increase_bottom_shooter_half_speed->WhenPressed(new Change_Shooter_Bottom_Speed(0.1, false));
	Primary_Driver::decrease_top_shooter_speed->WhenPressed(new Change_Shooter_Top_Speed(-1, false));
	Primary_Driver::decrease_top_shooter_half_speed->WhenPressed(new Change_Shooter_Top_Speed(-0.1, false));
	Primary_Driver::increase_top_shooter_speed->WhenPressed(new Change_Shooter_Top_Speed(1, false));
	Primary_Driver::increase_top_shooter_half_speed->WhenPressed(new Change_Shooter_Top_Speed(0.1, false));
	Primary_Driver::stop_bottom_shooter->WhenPressed(new Change_Shooter_Bottom_Speed(0, true));
	Primary_Driver::stop_top_shooter->WhenPressed(new Change_Shooter_Top_Speed(0, true));
	Primary_Driver::change_joydrive->WhenPressed(new Change_Drive(2));	//Single joystick
	Primary_Driver::change_joydrive->WhenReleased(new Change_Drive(1));	//Tank drive

	Secondary_Driver::controller = new Xbox_Controller(0);
	Secondary_Driver::launchpad = new Launchpad(1);

//	Secondary_Driver::launchpad->PANEL_TOP_LEFT->WhenPressed(new Change_Drive(2)); 	//Single Joystick
//	Secondary_Driver::launchpad->PANEL_TOP_LEFT->WhenReleased(new Change_Drive(1));	//Tank drive
////Secondary_Driver::launchpad->PANEL_TOP_MID->WhenPressed(new Change_Drive(3));		//Comp drive (multi joystick)
//	Secondary_Driver::launchpad->PANEL_TOP_MID->WhenReleased(new Change_Drive(1));	//Tank drive


}
