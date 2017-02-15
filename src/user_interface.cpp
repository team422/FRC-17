#include "commands/change_shooter_top.hpp"
#include "commands/change_shooter_bot.hpp"
#include "commands/change_drive.hpp"
#include "commands/change_shooter_top.hpp"
#include "commands/launchpad_test.hpp"
#include "user_interface.hpp"
#include <WPILib.h>


Attack_3 *UI::Primary_Driver::left_stick = nullptr;
Attack_3 *UI::Primary_Driver::right_stick = nullptr;

Attack_3 *UI::Primary_Driver::decrease_bottom_shooter_speed = nullptr;
Attack_3 *UI::Primary_Driver::decrease_bottom_shooter_half_speed = nullptr;
Attack_3 *UI::Primary_Driver::increase_bottom_shooter_speed = nullptr;
Attack_3 *UI::Primary_Driver::increase_bottom_shooter_half_speed = nullptr;
Attack_3 *UI::Primary_Driver::decrease_top_shooter_speed = nullptr;
Attack_3 *UI::Primary_Driver::decrease_top_shooter_half_speed = nullptr;
Attack_3 *UI::Primary_Driver::increase_top_shooter_speed = nullptr;
Attack_3 *UI::Primary_Driver::increase_top_shooter_half_speed = nullptr;
Attack_3 *UI::Primary_Driver::stop_bottom_shooter = nullptr;
Attack_3 *UI::Primary_Driver::stop_top_shooter = nullptr;
Attack_3 *UI::Primary_Driver::change_joydrive = nullptr;


Xbox_Controller *UI::Secondary_Driver::controller = nullptr;
Launchpad *UI::Secondary_Driver::launchpad = nullptr;

void UI::initialize() {
	Primary_Driver::left_stick = new Attack_3(3);
	Primary_Driver::right_stick = new Attack_3(2);

	Primary_Driver::left_stick->BUTTON_2->WhenPressed(new Change_Shooter_Bottom_Speed(-1, false));
	Primary_Driver::left_stick->BUTTON_4->WhenPressed(new Change_Shooter_Bottom_Speed(-0.5, false));
	Primary_Driver::left_stick->BUTTON_3->WhenPressed(new Change_Shooter_Bottom_Speed(1, false));
	Primary_Driver::left_stick->BUTTON_5->WhenPressed(new Change_Shooter_Bottom_Speed(0.5, false));
	Primary_Driver::right_stick->BUTTON_2->WhenPressed(new Change_Shooter_Top_Speed(-1, false));
	Primary_Driver::right_stick->BUTTON_4->WhenPressed(new Change_Shooter_Top_Speed(-0.5, false));
	Primary_Driver::right_stick->BUTTON_3->WhenPressed(new Change_Shooter_Top_Speed(1, false));
	Primary_Driver::right_stick->BUTTON_5->WhenPressed(new Change_Shooter_Top_Speed(0.5, false));
	Primary_Driver::left_stick->TRIGGER->WhenPressed(new Change_Shooter_Bottom_Speed(0, true));
	Primary_Driver::right_stick->TRIGGER->WhenPressed(new Change_Shooter_Top_Speed(0, true));

	Secondary_Driver::controller = new Xbox_Controller(0);
	Secondary_Driver::launchpad = new Launchpad(1);

	Secondary_Driver::launchpad->SWITCH_4->WhenPressed(new Launchpad_Test(0));
	Secondary_Driver::launchpad->LARGE_GREEN_1->WhenPressed(new Launchpad_Test(1));
	Secondary_Driver::launchpad->LARGE_GREEN_2->WhenPressed(new Launchpad_Test(2));
	Secondary_Driver::launchpad->LARGE_SWITCH->WhenPressed(new Launchpad_Test(3));
	Secondary_Driver::launchpad->PANEL_TOP_LEFT->WhenPressed(new Change_Drive(2)); 	//Single Joystick
	Secondary_Driver::launchpad->PANEL_TOP_LEFT->WhenReleased(new Change_Drive(1));	//Tank drive
	Secondary_Driver::launchpad->PANEL_TOP_MID->WhenPressed(new Change_Drive(3));		//Comp drive (multi joystick)
	Secondary_Driver::launchpad->PANEL_TOP_MID->WhenReleased(new Change_Drive(1));	//Tank drive
}
