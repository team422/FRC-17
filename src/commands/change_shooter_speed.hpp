#pragma once

#include <WPILib.h>

class Change_Shooter_Speed : public frc::Command {
public:
	Change_Shooter_Speed(bool stop, int side, float direction);
	void Initialize();
	void Execute() {};
	bool IsFinished();
	void Interrupted() {};
	void End() {};
private:
	bool stop;
	int side;
	float direction;
};
