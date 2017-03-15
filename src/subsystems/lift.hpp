#pragma once

#include <CANTalon.h>
#include <WPILib.h>

class Lift : public Subsystem {
public:
	Lift();
	void InitDefaultCommand();
	void set_motor(float speed);
private:
	CANTalon *lift_motor;
	float constrain(float input);
};
