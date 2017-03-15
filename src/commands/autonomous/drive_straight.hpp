#pragma once

#include <WPILib.h>

class Drive_Straight : public frc::Command {
public:
	Drive_Straight(int distance);
	void Initialize();
	void Execute();
	bool IsFinished();
	void Interrupted();
	void End();
private:
	int distance;
	bool direction;
	float angle;
	float left_speed, right_speed;
};


