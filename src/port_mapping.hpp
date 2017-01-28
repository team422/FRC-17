#include <WPILib.h>

#pragma once

namespace Ports {

	namespace CANBusIDs {
	//40 should be 44, changed for testing
		const uint32_t
					   //Change back to 44
					   LEFT_FRONT_MOTOR = 1,
					   //Change back to 46
					   LEFT_MIDDLE_MOTOR = 46,
					   LEFT_REAR_MOTOR = 2,
					   RIGHT_FRONT_MOTOR = 14,
					   RIGHT_MIDDLE_MOTOR = 13,
					   RIGHT_REAR_MOTOR = 39;
		const uint32_t TOP_SHOOTER_MOTOR = 42,
					   BOTTOM_SHOOTER_MOTOR = 41;
	}

}


