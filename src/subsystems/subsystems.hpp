#pragma once

#include "drive_base.hpp"
#include "subsystems/shooter.hpp"
#include "compressor_system.hpp"

namespace Subsystems {

	extern Drive_Base * drive_base;
	extern Shooter * shooter;
	extern Compressor_System * compressor;
	void initialize();

}
