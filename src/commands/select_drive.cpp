<<<<<<< HEAD
#include "select_drive.hpp"
#include "tank_drive.hpp"
#include "single_joystick.hpp"
=======
#include "./select_drive.hpp"
#include "./tank_drive.hpp"
#include "./single_joystick.hpp"
>>>>>>> origin/feat/change_drive
#include "../subsystems/subsystems.hpp"
//#include "./multi_joystick.hpp"

#include <WPILib.h>

<<<<<<< HEAD
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
=======
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
>>>>>>> origin/feat/change_drive
}

bool Select_Drive::IsFinished() {
  return true;
}
