#pragma once

#include <WPILib.h>

class Change_Shooter_Speed : public Command {
public:
	Change_Shooter_Speed(int side, float direction, bool stop);
	void Initialize();
	void Execute() {};
	bool IsFinished();
	void End() {};
	void Interrupted() {};
private:
	int side;
	float direction;
	bool stop;
};

