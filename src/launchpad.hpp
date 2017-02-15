#pragma once

#include <WPILib.h>

class Launchpad {
public:
	Launchpad(uint32_t port);

private:
	Joystick *launchpad;

public:
//	Button * const BIG_RED;
	Button * const PANEL_TOP_LEFT;
	Button * const PANEL_TOP_MID;
	Button * const PANEL_TOP_RIGHT;
	Button * const PANEL_MID_LEFT;
	Button * const PANEL_MID_MID;
	Button * const PANEL_MID_RIGHT;
	Button * const PANEL_BOTTOM_LEFT;
	Button * const PANEL_BOTTOM_MID;
	Button * const PANEL_BOTTOM_RIGHT;
	Button * const PANEL_COLUMN_TOP;
	Button * const PANEL_COLUMN_MID;
	Button * const PANEL_COLUMN_BOTTOM;
	Button * const BIG_GREEN_LEFT;
	Button * const BIG_GREEN_RIGHT;
	Button * const SWITCH_1;
	Button * const SWITCH_2;
	Button * const SWITCH_3;
	Button * const SWITCH_4;
	Button * const BIG_SWITCH;
};
