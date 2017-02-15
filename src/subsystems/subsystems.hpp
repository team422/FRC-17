#pragma once

#include "drive_base.hpp"
#include "shooter.hpp"
#include "compressor_system.hpp"
#include "gear_intake.hpp"
#include "ball_intake.hpp"

namespace Subsystems {

	extern Drive_Base * drive_base;
	extern Shooter * shooter;
	extern Compressor_System * compressor;
	extern Gear_Intake * gear_intake;
	extern Ball_Intake * ball_intake;
	void initialize();

}
