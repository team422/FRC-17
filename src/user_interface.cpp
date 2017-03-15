#include "user_interface.hpp"

#include "commands/toggle_roller.hpp"
#include "commands/toggle_lift.hpp"
#include "commands/toggle_shooter.hpp"
#include "commands/toggle_climber.hpp"
#include "commands/autonomous/turn.hpp"
#include "commands/change_shooter_speed.hpp"
#include "commands/set_ball_intake.hpp"
#include "commands/set_gear_intake.hpp"
#include "commands/autonomous/turn.hpp"

Attack_3 *UI::left_joystick = nullptr;
Attack_3 *UI::right_joystick = nullptr;
Launchpad *UI::launchpad = nullptr;
Xbox_Controller *UI::controller = nullptr;

void UI::initialize() {
	left_joystick = new Attack_3(3);
	right_joystick = new Attack_3(2);
	launchpad = new Launchpad(1);
	controller = new Xbox_Controller(0);

	controller->B->WhenPressed(new Set_Gear_Intake(DoubleSolenoid::Value::kForward));
	controller->A->WhenPressed(new Set_Gear_Intake(DoubleSolenoid::Value::kReverse));
	controller->X->WhenPressed(new Set_Ball_Intake(DoubleSolenoid::Value::kForward));
	controller->RIGHT_BUMPER->WhenPressed(new Toggle_Climber(true, true));
	controller->RIGHT_BUMPER->WhenReleased(new Toggle_Climber(false, true));
	controller->LEFT_BUMPER->WhenPressed(new Toggle_Climber(true, false));
	controller->LEFT_BUMPER->WhenReleased(new Toggle_Climber(false, false));
	launchpad->SWITCH_2->WhenPressed(new Toggle_Roller(true));
	launchpad->SWITCH_2->WhenReleased(new Toggle_Roller(false));
	launchpad->SWITCH_3->WhenPressed(new Toggle_Lift(true));
	launchpad->SWITCH_3->WhenReleased(new Toggle_Lift(false));
	launchpad->SWITCH_4->WhenPressed(new Toggle_Shooter(true));
	launchpad->SWITCH_4->WhenReleased(new Toggle_Shooter(false));

	launchpad->PANEL_TOP_MID->WhenPressed(new Set_Ball_Intake(DoubleSolenoid::Value::kReverse));
}
