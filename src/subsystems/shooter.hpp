#pragma once

#include <CANTalon.h>
#include <WPILib.h>

class Shooter : public Subsystem {
public:
	Shooter();
	void InitDefaultCommand();
	void continue_motors();
	void set_left_speed(float input);
	float get_left_speed();
	void set_right_speed(float input);
	float get_right_speed();
private:
	CANTalon	*left_motor,
				*right_motor;
	float left_speed;
	float right_speed;
	float constrain(float input);
};
