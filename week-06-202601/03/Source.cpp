#include "Controller.hpp"

int main()
{
	Console::SetWindowSize(WIDTH, HEIGHT);
	Console::CursorVisible = false;
	srand(time(nullptr));

	Controller* ctrl = new Controller();
	ctrl->jugar();
	return 0;
}