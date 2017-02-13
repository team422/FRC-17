#include "autonomous.hpp"
#include "set_ball_intake.hpp"

#include <WPILib.h>

Autonomous::Autonomous() {
	AddSequential( new Set_Ball_Intake());

}

