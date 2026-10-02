#include "Controladora.hpp"

int main() {
	Console::SetWindowSize(WIDTH, HEIGHT);
	Console::CursorVisible = false;
	srand(time(nullptr));

	Controladora* ctrl = new Controladora();
	ctrl->juego();

	return 0;
}