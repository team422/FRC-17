#include <WPILib.h>

#pragma once

namespace Ports {

	namespace CANBusIDs {

		const uint32_t
					   LEFT_FRONT_MOTOR = 41,
					   LEFT_MIDDLE_MOTOR = 46,
					   LEFT_REAR_MOTOR = 42,
					   RIGHT_FRONT_MOTOR = 39,
					   RIGHT_MIDDLE_MOTOR = 44,
					   RIGHT_REAR_MOTOR = 43;
		const uint32_t TOP_SHOOTER_MOTOR = 38,
					   BOTTOM_SHOOTER_MOTOR = 6;
	}

	namespace Relays {
		const uint32_t COMPRESSOR = 0;
	}
	
	namespace Solenoids {
		const uint32_t
						GEAR_INTAKE_IN = 7,
						GEAR_INTAKE_OUT = 0,
						BALL_INTAKE_IN = 6,
						BALL_INTAKE_OUT = 1;
	}
}