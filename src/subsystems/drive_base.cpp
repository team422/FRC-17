#include "drive_base.hpp"

#include "../commands/tank_drive.hpp"
#include "../port_mapping.hpp"

Drive_Base::Drive_Base() :
Subsystem ("Drive_Base"),
left_front_motor (new CANTalon(Ports::CANBusIds::LEFT_FRONT_MOTOR)),
left_middle_motor (new CANTalon(Ports::CANBusIds::LEFT_MIDDLE_MOTOR)),
left_rear_motor (new CANTalon(Ports::CANBusIds::LEFT_REAR_MOTOR)),
right_front_motor (new CANTalon(Ports::CANBusIds::RIGHT_FRONT_MOTOR)),
right_middle_motor (new CANTalon(Ports::CANBusIds::RIGHT_MIDDLE_MOTOR)),
right_rear_motor (new CANTalon(Ports::CANBusIds::RIGHT_REAR_MOTOR)),
gyro (new ADXRS450_Gyro()){

//	 Front and Rear motors set to slave motors
	left_front_motor->SetTalonControlMode(CANTalon::TalonControlMode::kFollowerMode);
	left_front_motor->Set(Ports::CANBusIds::LEFT_MIDDLE_MOTOR);
	left_rear_motor->SetTalonControlMode(CANTalon::TalonControlMode::kFollowerMode);
	left_rear_motor->Set(Ports::CANBusIds::LEFT_MIDDLE_MOTOR);
	right_front_motor->SetTalonControlMode(CANTalon::TalonControlMode::kFollowerMode);
	right_front_motor->Set(Ports::CANBusIds::RIGHT_MIDDLE_MOTOR);
	right_rear_motor->SetTalonControlMode(CANTalon::TalonControlMode::kFollowerMode);
	right_rear_motor->Set(Ports::CANBusIds::RIGHT_MIDDLE_MOTOR);
	// Middle motor set to master motor
	left_middle_motor->Set(0);
	right_middle_motor->Set(0);
	// Set 12 encoder ticks per revolution
	left_middle_motor->ConfigEncoderCodesPerRev(128);
	right_middle_motor->ConfigEncoderCodesPerRev(128);

	left_middle_motor->SetInverted(true);

	reset_encoders();

	gyro->Calibrate();
}

void Drive_Base::InitDefaultCommand() {
	SetDefaultCommand(new Tank_Drive());
}

void Drive_Base::set_motors_normalized(float left, float right) {
	left = constrain(left);
	right = constrain(right);
	left_middle_motor->Set(left);
	right_middle_motor->Set(right);
}

int Drive_Base::get_left_encoder_position() {
	return left_middle_motor->GetEncPosition();
}

int Drive_Base::get_right_encoder_position() {
	return right_middle_motor->GetEncPosition();
}

float Drive_Base::get_left_encoder_speed() {
	return left_middle_motor->GetSpeed();
}

float Drive_Base::get_right_encoder_speed() {
	return right_middle_motor->GetSpeed();
}

void Drive_Base::reset_encoders() {
	left_middle_motor->SetEncPosition(0);
	right_middle_motor->SetEncPosition(0);
}

float Drive_Base::get_angle() {
	return gyro->GetAngle();
}

void Drive_Base::reset_gyro() {
	gyro->Reset();
}

float Drive_Base::constrain(float input) {
	if (input > 0.85) {
		return 0.85;
	} else if (input < -0.85) {
		return -0.85;
	}
	return input;
}
