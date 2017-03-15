#pragma once

#include <CANTalon.h>
#include <WPILib.h>

class Ball_Intake : public Subsystem {
public:
	Ball_Intake();
	void set_ball_intake(DoubleSolenoid::Value value);
	void set_intake_motor(float speed);
private:
	DoubleSolenoid * ball_intake;
	CANTalon *intake_motor;
};

