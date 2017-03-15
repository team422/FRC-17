#include "autonomous_center.hpp"

#include "drive_straight.hpp"
#include "drive_straight_time.hpp"
#include "../set_ball_intake.hpp"
#include "../set_gear_intake.hpp"

Autonomous_Center::Autonomous_Center() {
//	AddSequential(new Set_Ball_Intake(DoubleSolenoid::Value::kForward));
//	AddSequential(new Drive_Straight(3400)); //3424 or 3400
	AddSequential(new Drive_Straight_Time(3.2)); //3424 or 3400
	AddSequential(new Set_Gear_Intake(DoubleSolenoid::Value::kForward));
}
