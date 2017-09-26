#include "drive_straight.hpp"

#include <math.h>

#include "../../subsystems/subsystems.hpp"

Drive_Straight::Drive_Straight(int distance) :
distance (distance),
direction (distance > 0),
angle (Subsystems::drive_base->get_angle()),
left_speed (direction ? -0.2 : 0.2),
right_speed (direction ? -0.2 : 0.2) {
	Requires(Subsystems::drive_base);
	Subsystems::drive_base->reset_encoders();
}

void Drive_Straight::Initialize() {
	Subsystems::drive_base->reset_encoders();
	Subsystems::drive_base->set_motors_normalized(left_speed, right_speed);
	angle = Subsystems::drive_base->get_angle();
}

void Drive_Straight::Execute() {
	float correction = 0;
	if (direction) {
		correction = Subsystems::drive_base->get_angle() - angle;
	} else {
		correction = angle - Subsystems::drive_base->get_angle();
	}
	correction *= 0.075;
	correction += 1;
	Subsystems::drive_base->set_motors_normalized(left_speed, right_speed * correction);
}

bool Drive_Straight::IsFinished() {
	int left_count = abs(Subsystems::drive_base->get_left_encoder_position());
	int right_count = abs(Subsystems::drive_base->get_right_encoder_position());
	int abs_distance = abs(distance);
	return (left_count > abs_distance) || (right_count > abs_distance);
}

void Drive_Straight::Interrupted() {
	Subsystems::drive_base->set_motors_normalized(0, 0);
}

void Drive_Straight::End() {
	Subsystems::drive_base->set_motors_normalized(0, 0);
	Subsystems::drive_base->reset_encoders();
}
