
#include "gear_intake.hpp"
#include "../port_mapping.hpp"
#include "../commands/set_gear_intake.hpp"
#include <WPILib.h>

Gear_Intake::Gear_Intake() :
Subsystem("Gear_Intake"),
gear_intake( new DoubleSolenoid(Ports::Solenoids::GEAR_INTAKE_OUT,
									Ports::Solenoids::GEAR_INTAKE_IN) ){
	gear_intake->Set(DoubleSolenoid::kReverse);
}

DoubleSolenoid::Value Gear_Intake::get_gear_intake() {
	return gear_intake->Get();
}

void Gear_Intake::set_gear_intake(DoubleSolenoid::Value value) {
	gear_intake->Set(value);
}
