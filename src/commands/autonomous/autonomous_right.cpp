#include "autonomous_right.hpp"

#include "drive_straight.hpp"
#include "drive_straight_time.hpp"
#include "turn.hpp"
#include "../set_ball_intake.hpp"
#include "../set_gear_intake.hpp"

Autonomous_Right::Autonomous_Right() {
//	AddSequential(new Set_Ball_Intake(DoubleSolenoid::Value::kForward));
//	AddSequential(new Drive_Straight(2604));
//	AddSequential(new Turn(-60));
//	AddSequential(new Drive_Straight(3727));
//	AddSequential(new Set_Gear_Intake(DoubleSolenoid::Value::kForward));
	AddSequential(new Drive_Straight_Time(3.5));
}
