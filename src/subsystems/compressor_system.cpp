/*
 * CompressorSystem.cpp
 *
 *  Created on: Feb 5, 2017
 *      Author: 6420Owner
 */

#include "compressor_system.hpp"
#include "../port_mapping.hpp"
#include <WPILib.h>

Compressor_System::Compressor_System():
	Subsystem(""),
	compressor( new Compressor(Ports::Relays::COMPRESSOR) ) {
		compressor->Start();
	}

