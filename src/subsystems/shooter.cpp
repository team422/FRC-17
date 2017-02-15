#include "shooter.hpp"

#include "../commands/shooter_command.hpp"
#include "../port_mapping.hpp"

Shooter::Shooter() :
	Subsystem("Shooter"),
	top_motor(new CANTalon(Ports::CANBusIDs::TOP_SHOOTER_MOTOR)),
	bot_motor(new CANTalon(Ports::CANBusIDs::BOTTOM_SHOOTER_MOTOR)),
	top_speed (0),
	bot_speed (0) {

	setup_speed_mode();
<<<<<<< HEAD
	set_top_speed(15000);
=======
	set_top_speed(15000);
>>>>>>> origin/feat/autonomous
	set_bot_speed(4500);
}

void Shooter::InitDefaultCommand() {
	SetDefaultCommand(new Shooter_Command());
}

void Shooter::setup_vbus_mode() {
	top_motor->SetControlMode(CANTalon::ControlMode::kPercentVbus);
	top_motor->SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);
	top_motor->SetP(0);
	top_motor->SetI(0);
	top_motor->SetD(0);
	top_motor->EnableControl();
	bot_motor->SetControlMode(CANTalon::ControlMode::kPercentVbus);
	bot_motor->SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);
	bot_motor->SetP(0);
	bot_motor->SetI(0);
	bot_motor->SetD(0);
	bot_motor->EnableControl();
}

void Shooter::setup_speed_mode() {
	top_motor->SetControlMode(CANTalon::ControlMode::kSpeed);
	top_motor->SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);
	top_motor->SetP(0.12);
	top_motor->SetI(0.0002);
	top_motor->SetD(0);
	// May not be necessary
//	top_motor->SetInverted(true);
	top_motor->ConfigEncoderCodesPerRev(128);
	top_motor->EnableControl();
	bot_motor->SetControlMode(CANTalon::ControlMode::kSpeed);
	bot_motor->SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);
	bot_motor->SetP(0.12);
	bot_motor->SetI(0.0002);
	bot_motor->SetD(0);
	bot_motor->SetInverted(true);
	bot_motor->ConfigEncoderCodesPerRev(128);
	bot_motor->EnableControl();
}

float Shooter::get_bot_speed() {
	return bot_motor->GetSpeed();
<<<<<<< HEAD
}

float Shooter::get_ideal_bot_speed() {
	return bot_speed;
=======
}

float Shooter::get_ideal_bot_speed() {
	return bot_speed;
>>>>>>> origin/feat/autonomous
}

float Shooter::get_top_speed() {
	return top_motor->GetSpeed();
<<<<<<< HEAD
=======
}

float Shooter::get_ideal_top_speed() {
	return top_speed;
>>>>>>> origin/feat/autonomous
}

float Shooter::get_ideal_top_speed() {
	return top_speed;
}

void Shooter::set_bot_speed(float input) {
	bot_speed = input;
	printf("Bottom Speed: %f\n", bot_speed);
	bot_motor->Set(bot_speed); //to_ticks(input)
}

void Shooter::set_top_speed(float input) {
	top_speed = input;
	printf("Top Speed: %f\n", top_speed);
	top_motor->Set(top_speed); //to_ticks(input)
}

void Shooter::reset_encoders() {
	top_motor->SetPosition(0);
	bot_motor->SetPosition(0);
}

float Shooter::constrain(float input) {
	if (input > 1) {
		return 1;
	} else if (input < -1) {
		return -1;
	}

	return input;
}
