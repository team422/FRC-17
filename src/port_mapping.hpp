#pragma once

//#define MK1

namespace Ports {

	namespace CANBusIds {

#ifdef MK1
		// Ids for CANTalons on Drive Base
		const uint32_t	LEFT_FRONT_MOTOR = 42,
						LEFT_MIDDLE_MOTOR = 46,
						LEFT_REAR_MOTOR = 41,
						RIGHT_FRONT_MOTOR = 39,
						RIGHT_MIDDLE_MOTOR = 43,
						RIGHT_REAR_MOTOR = 44;
		// Ids for CANTalons on Shooter
		const uint32_t	SHOOTER_TOP = 38,
						SHOOTER_BOTTOM = 6;
		// Ids for CANTalons on Lift
		const uint32_t	LIFT_MOTOR = 45;
		// Ids for CANTalons on Ball Intake
		const uint32_t	INTAKE_MOTOR = 40;
		const uint32_t	CLIMBER_MOTOR = 56;
#else
		// Ids for CANTalons on Drive Base
		const uint32_t	LEFT_FRONT_MOTOR = 13,
						LEFT_MIDDLE_MOTOR = 23,
						LEFT_REAR_MOTOR = 21,
						RIGHT_FRONT_MOTOR = 16,
						RIGHT_MIDDLE_MOTOR = 10,
						RIGHT_REAR_MOTOR = 11;
		// Ids for CANTalons on Shooter
		const uint32_t	SHOOTER_TOP = 18,
						SHOOTER_BOTTOM = 7;
		// Ids for CANTalons on Lift
		const uint32_t	LIFT_MOTOR = 12;
		// Ids for CANTalons on Ball Intake
		const uint32_t	INTAKE_MOTOR = 62;
		const uint32_t	CLIMBER_MOTOR = 61;
#endif
	}

	namespace Relays {
		const uint32_t COMPRESSOR_NODE = 0;
	}

	namespace Solenoids {
//#ifdef MK1
		const uint32_t	GEAR_INTAKE_FORWARD = 0,
						GEAR_INTAKE_REVERSE = 7,
						BALL_INTAKE_FORWARD = 1,
						BALL_INTAKE_REVERSE = 6;
//#else
//		const uint32_t	GEAR_INTAKE_FORWARD = 1,
//						GEAR_INTAKE_REVERSE = 6,
//						BALL_INTAKE_FORWARD = 7,
//						BALL_INTAKE_REVERSE = 0;
//#endif
	}

}
