#pragma once

#include "commands/autonomous/autonomous_left.hpp"
#include "commands/autonomous/autonomous_center.hpp"
#include "commands/autonomous/autonomous_right.hpp"
#include <WPILib.h>

class Robot : public frc::IterativeRobot {
public:
	void RobotInit();
	void DisabledInit();
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
private:
//	Autonomous_Center *autonomous;
	Command *autonomous;
	SendableChooser<Command*> autonomousChooser;
};
