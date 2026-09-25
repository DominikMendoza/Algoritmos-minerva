#include "Controller.hpp"

int main()
{
	Console::SetWindowSize(WIDTH, HEIGHT);
	Console::CursorVisible = false;

	Controller* ctrl = new Controller();
	ctrl->jugar();
	system("pause>0");
	return 0;
}