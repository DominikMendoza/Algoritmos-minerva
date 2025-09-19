#include <conio.h>
#include "Carrera.hpp"

int main()
{
	srand(time(nullptr));
	Console::SetWindowSize(WIDTH, HEIGHT);
	Console::CursorVisible = false;
	Carrera* carrera = new Carrera(WIDTH - 6);
	while (true)
	{
		if (_kbhit()) {
			char tecla = _getch();
			tecla = toupper(tecla);
			if (tecla == 'G') {
				carrera->iniciarCarrera();
			}
		}
	}
	
	system("pause>0");
	return 0;
}