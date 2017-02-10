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
    case 1: tank_drive = new Tank_Drive();
            tank_drive.Schedule();
            break;
    case 2: single_joystick = new Single_Joystick();
            single_joystick.Schedule();
            break;
//  case 3: multi_joystick = new Multi_Joystick();
//          multi_joystick.Schedule();
//          break;
  }
}

bool Select_Drive::IsFinished() {
  return true;
}
