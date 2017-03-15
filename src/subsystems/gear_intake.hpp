#pragma once

#include <WPILib.h>

class Gear_Intake : public Subsystem {
public:
	Gear_Intake();
	void set_intake_value(DoubleSolenoid::Value value);
	DoubleSolenoid::Value get_intake_value();
private:
	DoubleSolenoid *intake_solenoid;
};


