#include "robot.hpp"
#include "user_interface.hpp"
#include "subsystems/subsystems.hpp"
#include "commands/autonomous.hpp"
#include <WPILib.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>


void Robot::RobotInit() {
//	chooser.AddDefault("Default Auto", new Autonomous());
//	chooser.AddObject("Left Gear", new LeftAutoCommand());
//	chooser.AddObject("Center Gear", new CenterAutoCommand());
//	chooser.AddObject("Right Gear", new RightAutoCommand());
//	frc::SmartDashboard::PutData("Auto Modes", &chooser);
	Subsystems::initialize();
	UI::initialize();
	//autonomous = new Autonomous();
	CameraServer::GetInstance()->StartAutomaticCapture();
}

void Robot::DisabledInit() {

}

void Robot::AutonomousInit() {
	autonomous->Start();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	autonomous->Cancel();
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TestInit() {

}

START_ROBOT_CLASS(Robot);
