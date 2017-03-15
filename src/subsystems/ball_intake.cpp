#include "ball_intake.hpp"
#include "../port_mapping.hpp"
#include <WPILib.h>

Ball_Intake::Ball_Intake() :
Subsystem("Ball_Intake"),
ball_intake( new DoubleSolenoid(Ports::Solenoids::BALL_INTAKE_FORWARD,Ports::Solenoids::BALL_INTAKE_FORWARD)),
intake_motor (new CANTalon(Ports::CANBusIds::INTAKE_MOTOR)) {
	ball_intake->Set(DoubleSolenoid::Value::kReverse);
	intake_motor->SetInverted(true);
	intake_motor->Set(0);
}

void Ball_Intake::set_ball_intake(DoubleSolenoid::Value value) {
	ball_intake->Set(value);
}

void Ball_Intake::set_intake_motor(float speed) {
	intake_motor->Set(speed);
}
