#include "commands/change_shooter_bot.hpp"
#include "commands/change_shooter_top.hpp"
#include "commands/launchpad_test.hpp"
#include "user_interface.hpp"
#include <WPILib.h>


Attack_3 *UI::Primary_Driver::left_stick = nullptr;
Attack_3 *UI::Primary_Driver::right_stick = nullptr;

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
}
