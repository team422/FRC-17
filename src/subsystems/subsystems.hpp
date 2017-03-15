#pragma once

#include "ball_intake.hpp"
#include "climber.hpp"
#include "compressor_system.hpp"
#include "drive_base.hpp"
#include "gear_intake.hpp"
#include "lift.hpp"
#include "shooter.hpp"

namespace Subsystems {
	extern Ball_Intake *ball_intake;
	extern Climber *climber;
	extern Compressor_System *compressor_system;
	extern Drive_Base *drive_base;
	extern Gear_Intake *gear_intake;
	extern Lift *lift;
	extern Shooter *shooter;

	void initialize();
}
