#pragma once

#include <WPILib.h>

class Shooter_Top_Command : public Command {
public:
	Shooter_Top_Command();
	void Initialize() {};
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};
