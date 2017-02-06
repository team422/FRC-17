#pragma once

#include <CANTalon.h>
#include <WPILib.h>

class Shooter : public Subsystem {
public:
	Shooter();
	void InitDefaultCommand();
	void setup_vbus_mode();
	void setup_speed_mode();
	float get_top_speed();
	float get_bot_speed();
	void set_top_speed(float input);
	void set_bot_speed(float input);
	void reset_encoders();
private:
	CANTalon *top_motor;
	CANTalon *bot_motor;
	float constrain(float input);
	const float max_speed = 5840;
	int to_ticks(float percent);
	float to_percent(float ticks);
};
