#include "subsystems.hpp"

Drive_Base * Subsystems::drive_base = nullptr;

void Subsystems::initialize() {
	drive_base = new Drive_Base();
}
