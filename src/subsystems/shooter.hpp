#pragma once

#include <CANTalon.h>
#include <WPILib.h>

class Shooter : public Subsystem {
public:
	Shooter();
	void InitDefaultCommand();
	void set_back_speed(float speed);
	float get_back_speed();
	void set_front_speed(float speed);
	float get_front_speed();
	float get_back_encoder_speed();
	float get_front_encoder_speed();
private:
	CANTalon	*back_motor,
				*front_motor;
	float back_speed;
	float front_motor;
	float constrain(float input);
};
