#include "subsystems/shooter_top.hpp"
#include <WPILib.h>

#include "../port_mapping.hpp"
#include "../commands/shooter_top_command.hpp"

Shooter_Top::Shooter_Top() :
Subsystem("Shooter_Top"),
top_motor (new CANTalon(Ports::CANBusIDs::TOP_SHOOTER_MOTOR)),
top_speed (0) {
	top_motor->Set(0);
	printf("Created Shooter Top\n");
}

void Shooter_Top::InitDefaultCommand() {
	SetDefaultCommand(new Shooter_Top_Command());
}

/*
 *	Similar to set_motors_normalized in drive base.
 *	Because the speed of each motor is stored in the variable
 *	top_speed it takes no parameters.
*/
void Shooter_Top::continue_motor() {
//	printf("Shooter Top speed: %f\n", top_speed);
	top_motor->Set(top_speed);
}

/*
 * Set the top motor's speed
 */
void Shooter_Top::set_top_speed(float input) {
	top_speed = constrain(input);
	printf("Set top speed to: %f\n", top_speed);
}

/*
 * Get the top motor's speed
 */
float Shooter_Top::get_top_speed() {
	printf("Returning top speed: %f\n", top_speed);
	return top_speed;
}

float Shooter_Top::constrain(float input) {
	if(input > 1) {
		input = 1;
	}
	else if(input < -1) {
		input = -1;
	}
	return input;
}

