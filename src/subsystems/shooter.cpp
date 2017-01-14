#include "shooter.hpp"
#include <WPILib.h>

#include "../port_mapping.hpp"
#include "../commands/shooter_command.hpp"

Shooter::Shooter() :
Subsystem("Shooter"),
left_motor (new CANTalon(Ports::CANBusIDs::LEFT_SHOOTER_MOTOR)),
right_motor (new CANTalon(Ports::CANBusIDs::RIGHT_SHOOTER_MOTOR)),
left_speed (0),
right_speed (0) {
	left_motor->Set(0);
	right_motor->Set(0);
}

void Shooter::InitDefaultCommand() {
	SetDefaultCommand(new Shooter_Command());
}

/*
 *	Similar to set_motors_normalized in drive base.
 *	Because the speed of each motor is stored in the variables
 *	left_ and right_speed, it takes no parameters.
*/
void Shooter::continue_motors() {
	printf("Shooter Left speed: %f\n", left_speed);
	printf("Shooter Right Speed: %f\n", right_speed);
	left_motor->Set(-left_speed);
	right_motor->Set(right_speed);
}

/*
 * Set the left motor's speed
 */
void Shooter::set_left_speed(float input) {
	left_speed = constrain(input);
}

/*
 * Get the left motor's speed
 */
float Shooter::get_left_speed() {
	return left_speed;
}

/*
 * Set the right motor's speed
 */
void Shooter::set_right_speed(float input) {
	right_speed = constrain(input);
}

/*
 * Get the right motor's speed
 */
float Shooter::get_right_speed() {
	return right_speed;
}

float Shooter::constrain(float input) {
	if(input > 0.5) {
		input = 0.5;
	}
	else if(input < -0.5) {
		input = -0.5;
	}
	return input;
}

