#pragma once

#include <WPILib.h>

class Comp_Drive : public Command {
public:
  Comp_Drive();
  void Initialize() {};
  void Execute();
  bool IsFinished();
  void Interrupted() {};
  void End() {};
private:
  float scale_turn(float turn_value);
};
