#include <subsystems/subsystems.hpp>

Drive_Base * Subsystems::drive_base = 0;

void Subsystems::initialize() {
	drive_base = new Drive_Base();
}
