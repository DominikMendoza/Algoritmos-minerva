#include "Juego.hpp"

int main()
{
	srand(time(nullptr));
	Console::SetWindowSize(WIDTH, HEIGHT);
	Console::CursorVisible = false;

	Juego* juego = new Juego();
	juego->jugar();
	system("pause>0");
	return 0;
}