#pragma once

#include <WPILib.h>

class Toggle_Roller : public frc::Command {
public:
	Toggle_Roller(bool is_on);
	void Initialize();
	void Execute() {};
	bool IsFinished();
	void Interrupted() {};
	void End() {};
private:
	bool is_on;
};


