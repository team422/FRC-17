#pragma once

#include "drive_base.hpp"
#include "subsystems/shooter.hpp"

namespace Subsystems {

	extern Drive_Base * drive_base;
	extern Shooter * shooter;
	void initialize();

}
