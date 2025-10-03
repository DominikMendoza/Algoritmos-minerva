#include "Juego.hpp"

int main()
{
	srand(time(nullptr));
	Console::SetWindowSize(WIDTH, HEIGHT);
	Console::CursorVisible = false;
	
	Juego* j = new Juego();
	j->jugar();

	system("pause>0");
	return 0;
}