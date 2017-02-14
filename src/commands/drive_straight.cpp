#include <WPILib.h>

#include "drive_straight.hpp"
#include "../subsystems/subsystems.hpp"

Drive_Straight::Drive_Straight(float speed, float distance) :
	speed (speed),
	distance (distance) {
	Requires(Subsystems::drive_base);
	remaining_dist = 0;
	//Change to actual values after testing
	Subsystems::drive_base->setPID_left(0, 0, 0);
	Subsystems::drive_base->setPID_right(0, 0, 0);
}

void Drive_Straight::Execute() {
	//Since driving straight, only need distance of one motor to know both

	remaining_dist = distance - Subsystems::drive_base->get_dist_left();

	if (remaining_dist > 0) {
		Subsystems::drive_base->set_motors_normalized(speed, speed);
	} else {
		Subsystems::drive_base->set_motors_normalized(0, 0);
	}

}

bool Drive_Straight::IsFinished() {
	if (!remaining_dist) {
		return true;
	}
	return false;
}

void Drive_Straight::Interrupted() {
	Subsystems::drive_base->set_motors_normalized(0, 0);
}
