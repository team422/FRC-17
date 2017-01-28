#pragma once

#include "drive_base.hpp"
#include "subsystems/shooter_top.hpp"
#include "subsystems/shooter_bottom.hpp"

namespace Subsystems {

	extern Drive_Base * drive_base;
	extern Shooter_Top * shooter_top;
	extern Shooter_Bottom * shooter_bottom;
	void initialize();

}
