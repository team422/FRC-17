#pragma once

#include <CANTalon.h>
#include <WPILib.h>

class Drive_Base : public Subsystem {
public:
	Drive_Base();
	void InitDefaultCommand();
	void set_motors_normalized(float left, float right);
	int get_left_encoder_position();
	int get_right_encoder_position();
	float get_left_encoder_speed();
	float get_right_encoder_speed();
	void reset_encoders();
	float get_angle();
	void reset_gyro();
private:
	CANTalon	*left_front_motor,
				*left_middle_motor,
				*left_rear_motor,
				*right_front_motor,
				*right_middle_motor,
				*right_rear_motor;
	ADXRS450_Gyro *gyro;
	float constrain(float input);
};
