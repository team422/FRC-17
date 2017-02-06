#include "launchpad_test.hpp"

Launchpad_Test::Launchpad_Test(int button) : button (button) {}

void Launchpad_Test::Initialize() {
	switch (button) {
	case 0:
		printf("Fourth switch was turned on!");
		break;
	case 1:
		printf("The first large green button was pressed!");
		break;
	case 2:
		printf("The second large green button was pressed!");
		break;
	case 3:
		printf("The master switch was turned on!");
		break;
	}
}

bool Launchpad_Test::IsFinished() {
	return true;
}
