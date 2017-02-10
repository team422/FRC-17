#include "shooter.hpp"

#include "../commands/shooter_command.hpp"
#include "../port_mapping.hpp"

Shooter::Shooter() :
	Subsystem("Shooter"),
	top_motor(new CANTalon(Ports::CANBusIDs::TOP_SHOOTER_MOTOR)),
	bot_motor(new CANTalon(Ports::CANBusIDs::BOTTOM_SHOOTER_MOTOR)) {

	setup_speed_mode();
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
	float speed_ticks = bot_motor->Get();
	return to_percent(speed_ticks);
}

float Shooter::get_top_speed() {
	float speed_ticks = top_motor->Get();
	return to_percent(speed_ticks);
}

void Shooter::set_bot_speed(float input) {
	bot_motor->Set(to_ticks(input));
}

void Shooter::set_top_speed(float input) {
	top_motor->Set(to_ticks(input));
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

int Shooter::to_ticks(float percent) {
	return (percent*max_speed*128)/(60*1000*10);
}

float Shooter::to_percent(float ticks) {
	return (ticks*60*1000*10)/(max_speed*128);
}
