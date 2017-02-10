#include "change_drive.hpp"
#include "tank_drive.hpp"
#include "../subsystems/subsystems.hpp"

#include <WPILib.h>

Change_Drive::Change_Drive(const std::string & new_drive) :
drive_type (new_drive) {}

void Change_Drive::Initialize() {
	if (drive_type == "joydrive") {
		Subsystems::is_joydrive = true;
		Subsystems::is_compdrive = false;
	} else if (drive_type == "compdrive") {
		Subsystems::is_compdrive = true;
		Subsystems::is_joydrive = false;
	} else {
		Subsystems::is_joydrive = false;
		Subsystems::is_joydrive = false;
	}
}

bool Change_Drive::IsFinished() {
	return true;
}
