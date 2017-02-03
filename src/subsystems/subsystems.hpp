#pragma once

#include "drive_base.hpp"
#include "shooter.hpp"

namespace Subsystems {

	extern Drive_Base * drive_base;
	extern Shooter * shooter;
	void initialize();

	extern bool is_joydrive;
	extern bool is_compdrive;

}
