#include "robot.hpp"
#include "user_interface.hpp"
#include "subsystems/subsystems.hpp"
#include <WPILib.h>


void Robot::RobotInit() {
	Subsystems::initialize();
	UI::initialize();
	//autonomous = new Autonomous();
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
