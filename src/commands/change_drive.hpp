#pragma once

#include <WPILib.h>
#include <string>

class Change_Drive : public Command {
public:
	Change_Drive(const std::string & new_drive);
	void Initialize();
	void Execute() {};
	void End() {};
	bool IsFinished();
	void Interrupted() {};
private:
	std::string drive_type;
};
