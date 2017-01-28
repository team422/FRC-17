#pragma once

#include <CANTalon.h>
#include <WPILib.h>

class Shooter_Top : public Subsystem {
public:
	Shooter_Top();
	void InitDefaultCommand();
	void continue_motor();
	void set_top_speed(float input);
	float get_top_speed();
private:
	CANTalon	*top_motor;
	float top_speed;
	float constrain(float input);
};
