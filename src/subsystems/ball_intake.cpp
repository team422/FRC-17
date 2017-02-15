#include "ball_intake.hpp"
#include "../port_mapping.hpp"
#include "../commands/set_ball_intake.hpp"
#include <WPILib.h>

Ball_Intake::Ball_Intake() :
Subsystem("Ball_Intake"),
ball_intake( new DoubleSolenoid(Ports::Solenoids::BALL_INTAKE_OUT,
									Ports::Solenoids::BALL_INTAKE_IN) ){}

void Ball_Intake::InitDefaultCommand(){
	SetDefaultCommand(new Set_Ball_Intake());
}

void Ball_Intake::set_ball_intake(DoubleSolenoid::Value value) {
	ball_intake->Set(value);
}
