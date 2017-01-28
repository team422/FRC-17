#include "subsystems/shooter_bottom.hpp"
#include <WPILib.h>

#include "../port_mapping.hpp"
#include "../commands/shooter_command.hpp"

Shooter_Bottom::Shooter_Bottom() :
Subsystem("Shooter_Bottom"),
bottom_motor (new CANTalon(Ports::CANBusIDs::BOTTOM_SHOOTER_MOTOR)),
bottom_speed (0) {
	bottom_motor->Set(0);
	printf("Created Shooter Bottom\n");
}

void Shooter_Bottom::InitDefaultCommand() {
	SetDefaultCommand(new Shooter_Command());
}

/*
 *	Similar to set_motors_normalized in drive base.
 *	Because the speed of each motor is stored in bottom_speed
 *	it takes no parameters.
*/
void Shooter_Bottom::continue_motor() {
//	printf("Shooter Bottom speed: %f\n", bottom_speed);
	bottom_motor->Set(bottom_speed);
}

/*
 * Set the bottom motor's speed
 */
void Shooter_Bottom::set_bottom_speed(float input) {
	bottom_speed = constrain(input);
	printf("Set bottom speed to: %f\n", bottom_speed);
}

/*
 * Get the bottom motor's speed
 */
float Shooter_Bottom::get_bottom_speed() {
	printf("Returning bottom speed: %f\n", bottom_speed);
	return bottom_speed;
}

float Shooter_Bottom::constrain(float input) {
	if(input > 1) {
		input = 1;
	}
	else if(input < -1) {
		input = -1;
	}
	return input;
}

