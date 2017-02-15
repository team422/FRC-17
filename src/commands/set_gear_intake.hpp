#pragma once

#include <WPILib.h>

class Set_Gear_Intake : public Command {
public:
	Set_Gear_Intake();
	void Initialize();
	void Execute() {};
	bool IsFinished();
	void End() {};
	void Interrupted() {};

};
