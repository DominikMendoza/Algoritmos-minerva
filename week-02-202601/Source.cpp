#include <conio.h>

#include "Avion.hpp"
#include "Contrasena.hpp"
#include "Estudiante.hpp"


void ejercicio_1() {
	Estudiante* est = new Estudiante(10, 20, 17);
	est->imprimirNotas();
	cout << "El promedio de notas es: " << est->calcularPromedio() << "\n";
	est->determinarSiAprueba();
}

void ejercicio_2() {
	Avion* av = new Avion(0, 0, 14, 0, 0);
	av->setColor(rand() % 15 + 1); // podemos setear el color desde aqui
	while (true)
	{
		if (_kbhit()) {
			char tecla = _getch();
			tecla = toupper(tecla);
			av->cambiarDireccion(tecla);

			if (tecla == 'X') {
				av->borrar();
				av->explotar();
				return;
			}
		}
		av->borrar();
		av->mover();
		av->dibujar();
		_sleep(90);
	}
}

void ejercicio_3() {
	int numeroDeContrasenas = rand() % 6 + 5;
	Contrasena** coleccionPassword = new Contrasena * [numeroDeContrasenas];
	bool* sonSeguras = new bool[numeroDeContrasenas];
	for (int i = 0; i < numeroDeContrasenas; i++)
	{
		coleccionPassword[i] = new Contrasena(15);
		sonSeguras[i] = coleccionPassword[i]->esSegura();
	}

	for (int i = 0; i < numeroDeContrasenas; i++)
	{
		cout << coleccionPassword[i]->getPassword();
		cout << ": Fuerte: ";
		if (sonSeguras[i]) {
			cout << "Verdadero";
		}
		else {
			cout << "Falso";
		}
		cout << "\n";
	}
}

int main()
{
	srand(time(nullptr));
	Console::SetWindowSize(WIDTH, HEIGHT);
	Console::CursorVisible = false;
	ejercicio_3();
	system("pause>0");
	return 0;
}