#pragma once

#define PID

#include <WPILib.h>

namespace Ports {

	namespace CANBusIDs {
	//40 should be 44, changed for testing
		const uint32_t
					   //Change back to 44
					   LEFT_FRONT_MOTOR = 41,
					   //Change back to 46
					   LEFT_MIDDLE_MOTOR = 42,
					   LEFT_REAR_MOTOR = 46,
					   RIGHT_FRONT_MOTOR = 39,
					   RIGHT_MIDDLE_MOTOR = 43,
					   RIGHT_REAR_MOTOR = 10; // 44
		const uint32_t TOP_SHOOTER_MOTOR = 38, //
					   BOTTOM_SHOOTER_MOTOR = 6;

}

	namespace Relays {
		const uint32_t COMPRESSOR = 0;
}

}
