#include "subsystems.hpp"

Drive_Base * Subsystems::drive_base = nullptr;
Shooter * Subsystems::shooter = nullptr;
bool Subsystems::is_joydrive;
bool Subsystems::is_compdrive;

void Subsystems::initialize() {
	drive_base = new Drive_Base();
	shooter = new Shooter();
	is_joydrive = false;
	is_compdrive = false;
}
