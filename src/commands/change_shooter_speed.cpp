#include "change_shooter_speed.hpp"

#include "../subsystems/subsystems.hpp"

Change_Shooter_Speed::Change_Shooter_Speed(bool stop, int side, float direction) :
stop (stop),
side (side),
direction (direction) {
	Requires(Subsystems::shooter);
}
void Change_Shooter_Speed::Initialize() {
	if (side == 0) {
		if (stop)  {
			Subsystems::shooter->set_bottom_speed(0);
		} else {
			float speed = Subsystems::shooter->get_bottom_speed();
			speed += (direction * 0.1);
			Subsystems::shooter->set_bottom_speed(speed);
		}
	} else if (side == 1) {
		if (stop) {
			Subsystems::shooter->set_top_speed(0);
		} else {
			float speed = Subsystems::shooter->get_top_speed();
			speed += (direction * 0.1);
			Subsystems::shooter->set_top_speed(speed);
		}
	}
}

bool Change_Shooter_Speed::IsFinished() {
	return true;
}
