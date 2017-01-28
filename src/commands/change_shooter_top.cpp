#include <commands/change_shooter_top.hpp>
#include "../subsystems/subsystems.hpp"

Change_Shooter_Top_Speed::Change_Shooter_Top_Speed(float direction, bool stop) :
direction (direction),
stop (stop) {
	Requires(Subsystems::shooter);
}

void Change_Shooter_Top_Speed::Initialize() {
	if (stop) {
		Subsystems::shooter->set_top_speed(0);
	} else {
		float new_speed =  Subsystems::shooter->get_top_speed() + (direction * .1);
		Subsystems::shooter->set_top_speed(new_speed);
	}
}

bool Change_Shooter_Top_Speed::IsFinished() {
	return true;
}
