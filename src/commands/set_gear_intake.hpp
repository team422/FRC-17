#pragma once

#include <WPILib.h>

class Set_Gear_Intake : public frc::Command {
public:
	Set_Gear_Intake(DoubleSolenoid::Value value);
	void Initialize();
	void Execute() {};
	bool IsFinished();
	void Interrupted() {};
	void End() {};
private:
	DoubleSolenoid::Value value;
};
