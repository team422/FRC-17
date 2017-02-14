#include "subsystems.hpp"

Drive_Base * Subsystems::drive_base = nullptr;
Shooter * Subsystems::shooter = nullptr;
Compressor_System * Subsystems::compressor = nullptr;
Gear_Intake * Subsystems::gear_intake = nullptr;
Ball_Intake * Subsystems::ball_intake = nullptr;

void Subsystems::initialize() {
	drive_base = new Drive_Base();
	shooter = new Shooter();
	compressor = new Compressor_System();
	gear_intake = new Gear_Intake();
	ball_intake = new Ball_Intake();
}
