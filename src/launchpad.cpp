#include "launchpad.hpp"

#include <WPILib.h>

Launchpad::Launchpad(uint32_t port) :
	launchpad( new Joystick(port) ),
	LARGE_RED (new JoystickButton(launchpad, 13)),
	LARGE_GREEN_1 (new JoystickButton(launchpad, 14)),
	LARGE_GREEN_2 (new JoystickButton(launchpad, 15)),
	PANEL_1_1( new JoystickButton(launchpad, 1) ),
	PANEL_1_2( new JoystickButton(launchpad, 4) ),
	PANEL_1_3( new JoystickButton(launchpad, 7) ),
	PANEL_1_4( new JoystickButton(launchpad, 10) ),
	PANEL_2_1( new JoystickButton(launchpad, 2) ),
	PANEL_2_2( new JoystickButton(launchpad, 5) ),
	PANEL_2_3( new JoystickButton(launchpad, 8) ),
	PANEL_2_4( new JoystickButton(launchpad, 11) ),
	PANEL_3_1( new JoystickButton(launchpad, 3) ),
	PANEL_3_2( new JoystickButton(launchpad, 6) ),
	PANEL_3_3( new JoystickButton(launchpad, 9) ),
	PANEL_3_4( new JoystickButton(launchpad, 12) ),
	SWITCH_1 ( new JoystickButton(launchpad, 16)),
	SWITCH_2 ( new JoystickButton(launchpad, 17)),
	SWITCH_3 ( new JoystickButton(launchpad, 18)),
	SWITCH_4 ( new JoystickButton(launchpad, 19)),
	LARGE_SWITCH (new JoystickButton(launchpad, 20))
	{}
