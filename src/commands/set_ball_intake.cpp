#include "set_ball_intake.hpp"
#include "../subsystems/subsystems.hpp"
#include <WPILib.h>

Set_Ball_Intake::Set_Ball_Intake() {
	Requires(Subsystems::ball_intake);
}

void Set_Ball_Intake::Initialize() {
		Subsystems::ball_intake->set_ball_intake(DoubleSolenoid::Value::kForward);
}

bool Set_Ball_Intake::IsFinished() {
	return true;
}
