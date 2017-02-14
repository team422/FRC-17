#include "drive_base.hpp"
#include "../commands/select_drive.hpp"
#include "../port_mapping.hpp"

#include <CANTalon.h>
#include <WPILib.h>

Drive_Base::Drive_Base() :
Subsystem("Drive_Base"),
left_front_motor(new CANTalon(Ports::CANBusIDs::LEFT_FRONT_MOTOR)),
left_middle_motor (new CANTalon(Ports::CANBusIDs::LEFT_MIDDLE_MOTOR)),
left_rear_motor (new CANTalon(Ports::CANBusIDs::LEFT_REAR_MOTOR)),
right_front_motor (new CANTalon(Ports::CANBusIDs::RIGHT_FRONT_MOTOR)),
right_middle_motor (new CANTalon(Ports::CANBusIDs::RIGHT_MIDDLE_MOTOR)),
right_rear_motor (new CANTalon(Ports::CANBusIDs::RIGHT_REAR_MOTOR)),
drive_type(1) { //TANK_DRIVE=1, SINGLE_JOYSTICK=2, MULTI_JOYSTICK=3
	set_motors_normalized(0, 0);
}

void Drive_Base::InitDefaultCommand() {
	SetDefaultCommand( new Select_Drive() );
}

void Drive_Base::set_motors_normalized(float left_speed, float right_speed) {
	float left = constrain(left_speed);
	float right = -constrain(right_speed);
//Currently set as negative for reversed joysticks
	left_front_motor->Set(-left);
	left_middle_motor->Set(-left);
	left_rear_motor->Set(-left);
	right_front_motor->Set(-right);
	right_middle_motor->Set(-right);
	right_rear_motor->Set(-right);
}

float Drive_Base::constrain(float input) {
	if(input > 0.85) {
		input = 0.85;
	}
	else if(input < -0.85) {
		input = -0.85;
	}
	return input;
}

int Drive_Base::get_drive_type() {
	return drive_type;
}

void Drive_Base::set_drive_type(int new_drive) {
	printf("set_drive_type called with value of: " + new_drive);
	drive_type = new_drive;
}

void Drive_Base::setup_dist_mode() {

	//Maybe only need one motor to get distance They'll all be going the same distance (while traveling straight)
	left_front_motor->SetControlMode(CANTalon::ControlMode::kPosition);
	left_front_motor->SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);
	left_front_motor->SetP(0);
	left_front_motor->SetI(0);
	left_front_motor->SetD(0);
	left_front_motor->EnableControl();

	right_front_motor->SetControlMode(CANTalon::ControlMode::kPosition);
	right_front_motor->SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);
	right_front_motor->SetP(0);
	right_front_motor->SetI(0);
	right_front_motor->SetD(0);
	right_front_motor->EnableControl();

}

float Drive_Base::get_dist_left() {
	printf("Position is %f", left_front_motor->GetPosition());
	return left_front_motor->GetPosition();
}

float Drive_Base::get_dist_right() {
	printf("Position is %f", right_front_motor->GetPosition());
	return right_front_motor->GetPosition();
}

void Drive_Base::reset_encoders() {
	left_front_motor->SetPosition(0);
	right_front_motor->SetPosition(0);
}

//Can't access motors from commands because they are private. Clean up later
void Drive_Base::setPID_right(float P, float I, float D) {
	left_front_motor->SetPID(P, I, D);
	left_middle_motor->SetPID(P, I, D);
	left_rear_motor->SetPID(P, I, D);
}

void Drive_Base::setPID_left(float P, float I, float D) {
	right_front_motor->SetPID(P, I, D);
	right_middle_motor->SetPID(P, I, D);
	right_rear_motor->SetPID(P, I, D);
}
