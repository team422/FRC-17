#pragma once

#include <WPILib.h>

class Ball_Intake : public Subsystem {
public:
	Ball_Intake();
	void InitDefaultCommand();
	void set_ball_intake(DoubleSolenoid::Value value);

private:
	DoubleSolenoid * ball_intake;
};

