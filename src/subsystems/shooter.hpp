#pragma once

#include <CANTalon.h>
#include <WPILib.h>

class Shooter : public Subsystem {
public:
	Shooter();
	void InitDefaultCommand();
	void continue_motor();
	float get_top_speed();
	float get_bot_speed();
	void set_top_speed(float input);
	void set_bot_speed(float input);
private:
	CANTalon *top_motor;
	CANTalon *bot_motor;
	float top_speed;
	float bot_speed;
	float constrain(float input);
};
