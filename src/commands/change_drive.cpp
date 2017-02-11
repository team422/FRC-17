#include "change_drive.hpp"
#include "tank_drive.hpp"
#include "../subsystems/subsystems.hpp"

#include <WPILib.h>

Change_Drive::Change_Drive(const int & new_drive) :
drive_type (new_drive) {
	Requires(Subsystems::drive_base);
	printf("Change drive initialized with value of: " + new_drive);
}

void Change_Drive::Initialize() {
	Subsystems::drive_base->set_drive_type(drive_type);
}

bool Change_Drive::IsFinished() {
	return true;
}
