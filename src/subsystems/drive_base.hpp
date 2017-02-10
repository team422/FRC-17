#pragma once

#include <CANTalon.h>
#include <WPILib.h>

class Drive_Base : public Subsystem {
public:
	Drive_Base();
	void InitDefaultCommand();
	void set_motors_normalized(float left_speed, float right_speed);
	int get_drive_type();
	void set_drive_type(int new_drive);
	void reset_encoders();
	void set_speed(float speed);
	void print();
private:
	CANTalon 	*left_front_motor,
				*left_middle_motor,
				*left_rear_motor,
				*right_front_motor,
				*right_middle_motor,
				*right_rear_motor;
	int drive_type;
	float constrain(float input);
};
