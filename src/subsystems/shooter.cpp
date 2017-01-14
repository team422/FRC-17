#include "shooter.hpp"
#include <WPILib.h>

#include "../port_mapping.hpp"

Shooter::Shooter() :
Subsystem("Shooter"),
motor1 (new CANTalon(Ports::CANBusIDs::SHOOTER_1)),
motor2 (new CANTalon(Ports::CANBusIDs::SHOOTER_2)) {
	motor1->Set(0);
	motor2->Set(0);
}

