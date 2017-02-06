#pragma once

#include <WPILib.h>

class Tank_Drive : public Command {
public:
	Tank_Drive();
	void Initialize() {};
	void Execute();
	bool IsFinished();
	void Interrupted() {};
	void End();
};
