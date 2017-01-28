#include <commands/change_shooter_bottom_speed.hpp>
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
	Requires(Subsystems::shooter_bottom);
	printf("\nCalling Change bottom speed");
	printf("Value of direction at Change bottom speed constructor: %f\n", direction);
}

void Change_Shooter_Bottom_Speed::Initialize() {
	if (stop) {
		Subsystems::shooter_bottom->set_bottom_speed(0);
		printf("Stopping Bottom\n");
	} else {
		float old_speed = Subsystems::shooter_bottom->get_bottom_speed();
		printf("Old bottom speed: %f\n", old_speed);
		float new_speed = old_speed + (direction * .2);
		printf("New bottom speed: %f\n", new_speed);
		Subsystems::shooter_bottom->set_bottom_speed(new_speed);
		printf("Verify bottom speed: %f\n\n", Subsystems::shooter_bottom->get_bottom_speed());
	}
}

bool Change_Shooter_Bottom_Speed::IsFinished() {
	return true;
}
