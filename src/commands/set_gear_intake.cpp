#include "set_gear_intake.hpp"
#include "../subsystems/subsystems.hpp"
#include <WPILib.h>

Set_Gear_Intake::Set_Gear_Intake() {
	Requires(Subsystems::gear_intake);
}

void Set_Gear_Intake::Initialize() {
	if (Subsystems::gear_intake->get_gear_intake() == DoubleSolenoid::Value::kForward) {
		Subsystems::gear_intake->set_gear_intake(DoubleSolenoid::Value::kReverse);
	} else if (Subsystems::gear_intake->get_gear_intake() == DoubleSolenoid::Value::kReverse) {
		Subsystems::gear_intake->set_gear_intake(DoubleSolenoid::Value::kForward);
	} else {
		Subsystems::gear_intake->set_gear_intake(DoubleSolenoid::Value::kOff);
	}



}

bool Set_Gear_Intake::IsFinished() {
	return true;
}
