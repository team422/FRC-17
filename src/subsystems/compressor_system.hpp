#pragma once

#include <WPILib.h>

class Compressor_System : public Subsystem {
public:
	Compressor_System();
private:
	Compressor *compressor;
};


