#include "launchpad.hpp"

#include <WPILib.h>

Launchpad::Launchpad(uint32_t port) :
	launchpad( new Joystick(port) ),
	PANEL_TOP_LEFT( new JoystickButton(launchpad, 3) ),
	PANEL_TOP_MID( new JoystickButton(launchpad, 6) ),
	PANEL_TOP_RIGHT( new JoystickButton(launchpad, 8) ),
	PANEL_MID_LEFT( new JoystickButton(launchpad, 2) ),
	PANEL_MID_MID( new JoystickButton(launchpad, 5) ),
	PANEL_MID_RIGHT( new JoystickButton(launchpad, 7) ),
	PANEL_BOTTOM_LEFT( new JoystickButton(launchpad, 1) ),
	PANEL_BOTTOM_MID( new JoystickButton(launchpad, 4) ),
	PANEL_BOTTOM_RIGHT( new JoystickButton(launchpad, 16) ),
	PANEL_COLUMN_TOP( new JoystickButton(launchpad, 10) ),
	PANEL_COLUMN_MID( new JoystickButton(launchpad, 3) ),
    PANEL_COLUMN_BOTTOM( new JoystickButton(launchpad, 12) ),
	SWITCH_1( new JoystickButton(launchpad, 12) ),
	SWITCH_2( new JoystickButton(launchpad, 13) ),
	SWITCH_3( new JoystickButton(launchpad, 14) ),
	SWITCH_4( new JoystickButton(launchpad, 15) ),
	BIG_SWITCH( new JoystickButton(launchpad, 16 ) ),
	BIG_GREEN_LEFT( new JoystickButton(launchpad, 0) ),
	BIG_GREEN_RIGHT( new JoystickButton(launchpad, 0) )
	{}
