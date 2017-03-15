#include "set_ball_intake.hpp"

#include "../subsystems/subsystems.hpp"

Set_Ball_Intake::Set_Ball_Intake(DoubleSolenoid::Value value) :
value (value) {
	Requires(Subsystems::ball_intake);
}

void Set_Ball_Intake::Initialize() {
	Subsystems::ball_intake->set_ball_intake(value);
}

bool Set_Ball_Intake::IsFinished() {
	return true;
}
