#include "Cuenta.hpp"
#include "Avion.hpp"

void ejercicio_5() {
	Cuenta* cuenta = new Cuenta("Ejemplo", 98.89);

	cuenta->mostrarCuenta();

	cuenta->retirar(0.89);
	cuenta->retirar(120);
	cuenta->ingresar(5);
	cuenta->ingresar(-8);
	cuenta->retirar(3);

	cuenta->mostrarCuenta();
}

int main()
{
	Console::SetWindowSize(WIDTH, HEIGHT);
	Console::CursorVisible = false;
	srand(time(nullptr));
	Avion* av = new Avion(10, 10, 0, 0);
	bool terminoJuego = false;
	do
	{
		if (_kbhit()) {
			char tecla = _getch();
			tecla = toupper(tecla);

			if (tecla == 'X') {
				av->explotar();
				terminoJuego = true;
				break;
			}
			else {
				av->cambiarMovimiento(tecla);
			}
		}
		av->borrar();
		av->mover();
		av->dibujar();
		_sleep(100);
	} while (!terminoJuego);
	Console::Clear();
	cout << "Perdiste...";
	system("pause");
	return 0;
}