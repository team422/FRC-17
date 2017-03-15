#pragma once

#include <CANTalon.h>
#include <WPILib.h>

class Shooter : public Subsystem {
public:
	Shooter();
	void InitDefaultCommand();
	void set_top_speed(float speed);
	float get_top_speed();
	void set_bottom_speed(float speed);
	float get_bottom_speed();
	float get_top_encoder_speed();
	float get_bottom_encoder_speed();
private:
	CANTalon	*top_motor,
				*bottom_motor;
	float top_speed;
	float bottom_speed;
	float constrain(float input);
};
