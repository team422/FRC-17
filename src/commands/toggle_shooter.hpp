#pragma once

#include <WPILib.h>

class Toggle_Shooter : public frc::Command {
public:
	Toggle_Shooter(bool is_on);
	void Initialize();
	void Execute() {};
	bool IsFinished();
	void Interrupted() {};
	void End() {};
private:
	bool is_on;
};


