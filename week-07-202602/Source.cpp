#include "Controladora.hpp"

int main()
{
	srand(time(nullptr));
	Console::SetWindowSize(WIDTH, HEIGHT);
	Console::CursorVisible = false;
	Controladora* ctrl = new Controladora();
	ctrl->jugar();

	delete ctrl;
	system("pause>0");
	return 0;
}