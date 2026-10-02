#pragma once
#include "ArrRaton.hpp"
#include "Gato.hpp"

class Controladora
{
private:
	ArrRaton* arr;
	Gato* cat;
	int ratonesEliminados;
public:
	Controladora();
	~Controladora();
	void evaluarColisiones();
	void juego();
};

Controladora::Controladora()
{
	arr = new ArrRaton();
	cat = new Gato((WIDTH - 5) / 2, (HEIGHT - 3)/ 2);
	ratonesEliminados = 0;
	int numeroDeRatones = rand() % (15 - 7 + 1) + 7;
	for (int i = 0; i < numeroDeRatones; i++)
	{
		arr->agregar(new Raton(rand() % (WIDTH - 8), rand() % HEIGHT));
	}
}

Controladora::~Controladora()
{
}

void Controladora::evaluarColisiones()
{
	for (int i = 0; i < arr->getSize(); i++)
	{
		if (arr->getRaton(i)->estaColisionando(cat)) {
			arr->getRaton(i)->borrar();
			arr->borrar(i);
			ratonesEliminados++;
			return;
		}
	}
}

void Controladora::juego()
{
	while (true)
	{
		evaluarColisiones();
		cat->animar();
		arr->animarTodos();
		_sleep(120);
	}
}
