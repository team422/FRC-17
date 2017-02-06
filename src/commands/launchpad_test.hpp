#pragma once

#include <WPILib.h>

class Launchpad_Test : public Command {
public:
	Launchpad_Test(int button);
	void Initialize();
	void Execute() {};
	bool IsFinished();
	void Interrupted() {};
	void End() {};
private:
	int button;
};
