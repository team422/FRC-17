#pragma once

#include <WPILib.h>

class Select_Drive : public Command {
public:
  Select_Drive();
  void Initialize();
  void Execute() {};
  bool IsFinished();
  void Interrupted() {};
  void End() {};
};
