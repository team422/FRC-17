#include "gear_intake.hpp"

#include "../port_mapping.hpp"

Gear_Intake::Gear_Intake() :
Subsystem("Gear_Intake"),
intake_solenoid (new DoubleSolenoid(Ports::Solenoids::GEAR_INTAKE_FORWARD, Ports::Solenoids::GEAR_INTAKE_REVERSE)) {
//	intake_solenoid->Set(DoubleSolenoid::Value::kReverse);
}

void Gear_Intake::set_intake_value(DoubleSolenoid::Value value) {
	intake_solenoid->Set(value);
}

DoubleSolenoid::Value Gear_Intake::get_intake_value() {
	return intake_solenoid->Get();
}
