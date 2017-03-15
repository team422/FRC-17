#pragma once

#include <WPILib.h>

class Toggle_Lift : public frc::Command {
public:
	Toggle_Lift(bool is_on);
	void Initialize();
	void Execute() {};
	bool IsFinished();
	void Interrupted() {};
	void End() {};
private:
	bool is_on;
};


