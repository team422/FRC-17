#pragma once

#include <WPILib.h>

class Turn : public frc::Command {
public:
	Turn(float angle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void Interrupted();
	void End();
private:
	float angle;
	bool direction;
	float left_speed;
	float right_speed;
	bool in_range(float target, float error, float value);
};


