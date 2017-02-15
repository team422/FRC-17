#pragma once

#include <WPILib.h>

class Drive_Straight : public Command {
public:
	Drive_Straight(float speed, float distance);
	void Initialize() {};
	void Execute();
	void End() {};
	bool IsFinished();
	void Interrupted();
private:
	float speed;
	float distance;
	float remaining_dist;
};
