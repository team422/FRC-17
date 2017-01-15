#pragma once

#include <WPILib.h>

class Shooter_Command : public Command {
public:
	Shooter_Command();
	void Initialize() {};
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};


