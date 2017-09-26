#pragma once

#include <CANTalon.h>
#include <WPILib.h>

class Climber : public frc::Subsystem {
public:
	Climber();
	void set_motor(float speed);
private:
	CANTalon *climber1;
	float constrain(float input);
};


