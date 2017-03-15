#include "set_gear_intake.hpp"

#include "../subsystems/subsystems.hpp"

Set_Gear_Intake::Set_Gear_Intake(DoubleSolenoid::Value value) :
value (value) {
	Requires(Subsystems::gear_intake);
}

void Set_Gear_Intake::Initialize() {
	Subsystems::gear_intake->set_intake_value(value);
}

bool Set_Gear_Intake::IsFinished() {
	return true;
}
