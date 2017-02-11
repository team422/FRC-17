#include "select_drive.hpp"
#include "tank_drive.hpp"
#include "single_joystick.hpp"
#include "../subsystems/subsystems.hpp"
//#include "./multi_joystick.hpp"

#include <WPILib.h>

//Tank_Drive * Select_Drive::tank_drive = nullptr;
//Single_Joystick * Select_Drive::single_joystick = nullptr;

Select_Drive::Select_Drive() {
  Requires(Subsystems::drive_base);
  printf("Select_Drive initialized");
  tank_drive = new Tank_Drive();
  single_joystick = new Single_Joystick();

}

void Select_Drive::Initialize() {
	printf("Drive type: " + Subsystems::drive_base->get_drive_type());
  if(Subsystems::drive_base->get_drive_type() == 1) {
    	Scheduler::GetInstance()->AddCommand(tank_drive);
  } else if (Subsystems::drive_base->get_drive_type() == 2) {
    	Scheduler::GetInstance()->AddCommand(single_joystick);
  }
//  case 3: multi_joystick = new Multi_Joystick();
//          multi_joystick.Schedule();
//          break;
}

bool Select_Drive::IsFinished() {
  return true;
}
