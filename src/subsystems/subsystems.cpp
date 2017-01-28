#include "subsystems.hpp"

Drive_Base * Subsystems::drive_base = nullptr;
Shooter_Top * Subsystems::shooter_top = nullptr;
Shooter_Bottom * Subsystems::shooter_bottom = nullptr;

void Subsystems::initialize() {
	drive_base = new Drive_Base();
	shooter_top = new Shooter_Top();
	shooter_bottom = new Shooter_Bottom();
}
