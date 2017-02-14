#pragma once

#include <WPILib.h>

class Single_Joystick : public Command {
public:
  Single_Joystick();
  void Initialize() {};
  void Execute();
  bool IsFinished();
  void End() {};
  void Interrupted() {};
};
