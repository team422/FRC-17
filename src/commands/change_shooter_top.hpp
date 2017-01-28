#pragma once

#include <WPILib.h>

class Change_Shooter_Top_Speed : public Command {
public:
	Change_Shooter_Top_Speed(float direction, bool stop);
	void Initialize();
	void Execute() {};
	bool IsFinished();
	void End() {};
	void Interrupted() {};
private:
	float direction;
	bool stop;
};


