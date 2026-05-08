#pragma once
#include "ArrMovil.hpp"
#include "Gato.hpp"
#include "Raton.hpp"

class Controller
{
private:
	Gato* gato;
	ArrMovil* ratones;
public:
	Controller();
	~Controller();
	void jugar();
	void imprimirContadorDeRatones();
};

Controller::Controller()
{
	gato = new Gato();
	ratones = new ArrMovil();

	int numeroRatones = rand() % 9 + 7;
	for (int i = 0; i < numeroRatones; i++)
	{
		ratones->agregar(new Raton());
	}
}

Controller::~Controller()
{
}

void Controller::jugar()
{
	while (true)
	{
		// Validacion de colisiones
		for (int i = 0; i < ratones->getSize(); i++)
		{
			if (gato->estaColisionando(ratones->getMovil(i))) {
				ratones->getMovil(i)->borrar();
				ratones->eliminar(i);
				i--;
			}
		}
		gato->animar();
		ratones->animarTodos();

		this->imprimirContadorDeRatones();
		_sleep(60);
	}
}

void Controller::imprimirContadorDeRatones()
{
	Console::SetCursorPosition(WIDTH / 2 - 5, HEIGHT);
	cout << "           ";
	Console::SetCursorPosition(WIDTH / 2 - 5, HEIGHT);
	cout << "Ratones: " << ratones->getSize();
}
