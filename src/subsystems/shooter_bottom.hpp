#pragma once

#include <CANTalon.h>
#include <WPILib.h>

class Shooter_Bottom : public Subsystem {
public:
	Shooter_Bottom();
	void InitDefaultCommand();
	void continue_motor();
	void set_bottom_speed(float input);
	float get_bottom_speed();
private:
	CANTalon	*bottom_motor;
	float bottom_speed;
	float constrain(float input);
};
