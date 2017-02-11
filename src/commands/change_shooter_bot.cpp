#include <commands/change_shooter_bot.hpp>
#include "../subsystems/subsystems.hpp"

/*
 * Change the speed of the shooter
 *
 * Parameters
 * side			which side motor (left = 0, right = 1)
 * direction	increase (+1) or decrease (-1) the motor speed
 * stop			should the motor stop (set its speed to 0)
 */
Change_Shooter_Bottom_Speed::Change_Shooter_Bottom_Speed(float direction, bool stop) :
direction (direction),
stop (stop) {
	Requires(Subsystems::shooter);
}

void Change_Shooter_Bottom_Speed::Initialize() {
	if (stop) {
		Subsystems::shooter->set_bot_speed(0);
	} else {
		float new_speed = Subsystems::shooter->get_ideal_bot_speed() + (direction * 1000);
		Subsystems::shooter->set_bot_speed(new_speed);
		printf("Bottom speed set to %f", new_speed);
	}
}

bool Change_Shooter_Bottom_Speed::IsFinished() {
	return true;
}
