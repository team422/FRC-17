#include "robot.hpp"

#include "subsystems/subsystems.hpp"
#include "user_interface.hpp"

void Robot::RobotInit() {
	Subsystems::initialize();
	UI::initialize();
	autonomousChooser = SendableChooser<Command*>();
	autonomousChooser.AddDefault("Center Autonomous", new Autonomous_Center());
	autonomousChooser.AddObject("Baseline Autonomous", new Autonomous_Left());
//	autonomousChooser.AddObject("Right Autonomous", new Autonomous_Right());
	SmartDashboard::PutData("Autonomous Modes", &autonomousChooser);
//	autonomous = new Autonomous_Center();
	CameraServer::GetInstance()->StartAutomaticCapture();
}

void Robot::DisabledInit() {

}

void Robot::AutonomousInit() {
	Subsystems::drive_base->reset_gyro();
	Subsystems::drive_base->reset_encoders();
//	autonomous->Start();
	autonomous = (Command*) autonomousChooser.GetSelected();
	if (autonomous != nullptr) {
		autonomous->Start();
	}
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	if (autonomous != nullptr) {
		autonomous->Cancel();
	}
	Subsystems::ball_intake->set_ball_intake(DoubleSolenoid::Value::kReverse);
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
	printf("Gyro: %f\n", Subsystems::drive_base->get_angle());
}

START_ROBOT_CLASS(Robot);
