#pragma once

#include <WPILib.h>

class Launchpad {
public:
	Launchpad(uint32_t port);

private:
	Joystick *launchpad;

public:
	Button * const LARGE_RED;
	Button * const LARGE_GREEN_1;
	Button * const LARGE_GREEN_2;
	Button * const PANEL_1_1;
	Button * const PANEL_1_2;
	Button * const PANEL_1_3;
	Button * const PANEL_1_4;
	Button * const PANEL_2_1;
	Button * const PANEL_2_2;
	Button * const PANEL_2_3;
	Button * const PANEL_2_4;
	Button * const PANEL_3_1;
	Button * const PANEL_3_2;
	Button * const PANEL_3_3;
	Button * const PANEL_3_4;
	Button * const SWITCH_1;
	Button * const SWITCH_2;
	Button * const SWITCH_3;
	Button * const SWITCH_4;
	Button * const LARGE_SWITCH;
};
