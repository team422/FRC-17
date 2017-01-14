#include "change_shooter_speed.hpp"
#include "../subsystems/subsystems.hpp"

/*
 * Change the speed of the shooter
 *
 * Parameters
 * side			which side motor (left = 0, right = 1)
 * direction	increase (+1) or decrease (-1) the motor speed
 * stop			should the motor stop (set its speed to 0)
 */
Change_Shooter_Speed::Change_Shooter_Speed(int side, float direction, bool stop) :
side (side),
direction (direction),
stop (stop) {
	Requires(Subsystems::shooter);
}

void Change_Shooter_Speed::Initialize() {
	using namespace Subsystems;
	if (side) {
		// Right side
		if (stop) {
			shooter->set_right_speed(0);
			return;
		}
		float new_speed = shooter->get_right_speed() +
				(direction * 0.05f);
		shooter->set_right_speed(new_speed);
	} else {
		// Left side
		if (stop) {
			shooter->set_left_speed(0);
			return;
		}
		float new_speed = shooter->get_left_speed() +
				(direction * 0.05f);
		shooter->set_left_speed(new_speed);
	}
}

bool Change_Shooter_Speed::IsFinished() {
	return true;
}
