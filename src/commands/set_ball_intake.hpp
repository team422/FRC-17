#pragma once

#include <WPILib.h>

class Set_Ball_Intake : public Command {
public:
	Set_Ball_Intake();
	void Initialize();
	void Execute() {};
	bool IsFinished();
	void End() {};
	void Interrupted() {};

};
