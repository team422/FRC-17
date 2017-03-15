#include "autonomous_left.hpp"

#include "drive_straight_time.hpp"
#include "drive_straight.hpp"
#include "turn.hpp"
#include "../set_ball_intake.hpp"
#include "../toggle_lift.hpp"
#include "../toggle_shooter.hpp"
#include "../set_gear_intake.hpp"

Autonomous_Left::Autonomous_Left() {
//	AddSequential(new Set_Ball_Intake(DoubleSolenoid::Value::kForward));
//	AddSequential(new Drive_Straight(2604));
//	AddSequential(new Turn(60));
//	AddSequential(new Drive_Straight(3727));
//	AddSequential(new Set_Gear_Intake(DoubleSolenoid::Value::kForward));
	AddSequential(new Drive_Straight_Time(3.5));
	AddSequential(new Toggle_Shooter(true));
	AddSequential(new Turn(60));
	AddSequential(new Drive_Straight_Time(3.5));
	Wait(1);
	AddSequential(new Toggle_Lift(true));
}
