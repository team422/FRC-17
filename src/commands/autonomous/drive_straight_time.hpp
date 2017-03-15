#pragma once

#include <WPILib.h>

class Drive_Straight_Time : public frc::Command {
public:
	Drive_Straight_Time(double time);
	void Initialize();
	void Execute();
	bool IsFinished();
	void Interrupted();
	void End();
private:
	double time;
	float angle = 0;
	float left_speed = -0.3, right_speed = -0.3;
	Timer timer;
};


