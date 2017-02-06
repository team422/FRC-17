#include "./select_drive.hpp"
#include "./tank_drive.hpp"
#include "./single_joystick.hpp"
#include "../subsystems/subsystems.hpp"
//#include "./multi_joystick.hpp"

#include <WPILib.h>

Select_Drive::Select_Drive() {
  Requires(Subsystems::drive_base);
}

void Select_Drive::Initialize() {
  switch(Subsystems::drive_base->get_drive_type()) {
    case 1: Scheduler::Schedule( new Tank_Drive() );
            break;
    case 2: Scheduler::Schedule( new Single_Joystick() );
            break;
//  case 3: Scheduler::Schedule( new Multi_Joystick() );
//          break;
  }
}

bool Select_Drive::IsFinished() {
  return true;
}
