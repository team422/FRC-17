#include "compressor_system.hpp"

#include "../port_mapping.hpp"

Compressor_System::Compressor_System() :
Subsystem("Compressor_System"),
compressor (new Compressor(Ports::Relays::COMPRESSOR_NODE)) {
	compressor->Start();
}
