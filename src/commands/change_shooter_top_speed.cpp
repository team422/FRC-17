#include "change_shooter_top_speed.hpp"
#include "../subsystems/subsystems.hpp"

Change_Shooter_Top_Speed::Change_Shooter_Top_Speed(float direction, bool stop) :
direction (direction),
stop (stop) {
	Requires(Subsystems::shooter_top);
	printf("Calling Change Top Speed");
	printf("Value of direction at Change top speed constructor: %f\n", direction);
}

void Change_Shooter_Top_Speed::Initialize() {
	if (stop) {
		Subsystems::shooter_top->set_top_speed(0);
		printf("Stopping Top\n");
	} else {
		float old_speed = Subsystems::shooter_top->get_top_speed();
		printf("Old top speed: %f\n", old_speed);
		float new_speed =  old_speed + (direction * .2);
		printf("New top speed: %f\n", new_speed);
		Subsystems::shooter_top->set_top_speed(new_speed);
		printf("Verify top speed: %f\n\n", Subsystems::shooter_top->get_top_speed());
	}
}

bool Change_Shooter_Top_Speed::IsFinished() {
	return true;
}
