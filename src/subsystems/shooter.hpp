#pragma once

#include <CANTalon.h>
#include <WPILib.h>

class Shooter : public Subsystem {
public:
	Shooter();
private:
	CANTalon	*motor1,
				*motor2;
};
