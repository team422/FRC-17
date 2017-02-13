#pragma once

#include <WPILib.h>

class Gear_Intake : public Subsystem {
public:
	Gear_Intake();
	DoubleSolenoid::Value get_gear_intake();
	void set_gear_intake(DoubleSolenoid::Value value);

private:
	DoubleSolenoid *gear_intake;
};
