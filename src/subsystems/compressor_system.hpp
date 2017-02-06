/*
 * CompressorSystem.hpp
 *
 *  Created on: Feb 5, 2017
 *      Author: 6420Owner
 */

#pragma once

#include <WPILib.h>

class Compressor_System : public Subsystem {
public:
	Compressor_System();
private:
	Compressor *compressor;
};

