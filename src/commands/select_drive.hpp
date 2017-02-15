#pragma once

#include <WPILib.h>

#include "tank_drive.hpp"
#include "single_joystick.hpp"

class Select_Drive : public Command {
public:
  Select_Drive();
  void Initialize();
  void Execute() {};
  bool IsFinished();
  void Interrupted() {};
  void End() {};
private:
  Tank_Drive * tank_drive;
  Single_Joystick * single_joystick;
};
