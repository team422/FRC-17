#include "Drive_Straight_Time.hpp"

#include <math.h>

#include "../../subsystems/subsystems.hpp"

Drive_Straight_Time::Drive_Straight_Time(double time) : time (time) {
	Requires(Subsystems::drive_base);
	Subsystems::drive_base->reset_encoders();
}

void Drive_Straight_Time::Initialize() {
	timer.Reset();
	timer.Start();
	angle = Subsystems::drive_base->get_angle();
}

void Drive_Straight_Time::Execute() {
	float correction = Subsystems::drive_base->get_angle() - angle;
	correction *= 0.075;
	correction += 1;
	Subsystems::drive_base->set_motors_normalized(left_speed, right_speed * correction);
//	Subsystems::drive_base->set_motors_normalized(0, 0);
}

bool Drive_Straight_Time::IsFinished() {
	return timer.Get() > time;
}

void Drive_Straight_Time::Interrupted() {
	Subsystems::drive_base->set_motors_normalized(0, 0);
	timer.Stop();
}

void Drive_Straight_Time::End() {
	timer.Stop();
	Subsystems::drive_base->set_motors_normalized(0, 0);
	Subsystems::drive_base->reset_encoders();
}
