#pragma once
#include "Animal.hpp"
#include "ArrObjeto.hpp"
#include "Dodo.hpp"
#include "NaveTerricola.hpp"
#include "FlorMarciana.hpp"
#include "ParticulaMarciana.hpp"

class Controladora
{
private:
	ArrObjeto* flores;
	ArrObjeto* animales;
	ArrObjeto* particulas;
	NaveTerricola* nave;
	Dodo* dodo;
	int cntVidaVegetal;
	int cntVidaAnimal;
	int cntParticulaMarciana;
public:
	Controladora();
	~Controladora();
	void mostrarMetricas();
	void evaluarColisiones();
	void jugar();
};

Controladora::Controladora()
{
	cntVidaVegetal = 0;
	cntVidaAnimal = 0;
	cntParticulaMarciana = 0;
	nave = new NaveTerricola(0, 10);
	dodo = new Dodo(rand() % (WIDTH - 5), rand() % (HEIGHT - 5));
	flores = new ArrObjeto();
	animales = new ArrObjeto();
	particulas = new ArrObjeto();
	for (int i = 0; i < rand() % 3 + 2; i++)
	{
		flores->agregar(new FlorMarciana(rand() % (WIDTH - 3), rand() % (HEIGHT - 4)));
	}
	for (int i = 0; i < 2; i++)
	{
		animales->agregar(new Animal(rand() % (WIDTH - 5), rand() % (HEIGHT - 2), 1));
	}
	for (int i = 0; i < 2; i++)
	{
		animales->agregar(new Animal(rand() % (WIDTH - 5), rand() % (HEIGHT - 2), -1));
	}
	for (int i = 0; i < 6; i++)
	{
		particulas->agregar(new ParticulaMarciana(rand() % (WIDTH - 1), rand() % (HEIGHT - 1)));
	}
}

Controladora::~Controladora()
{
	delete flores;
}

void Controladora::mostrarMetricas()
{
	Console::SetCursorPosition(WIDTH / 2 - 10, 0);
	cout << "Vida vegetal: " << cntVidaVegetal;

	Console::SetCursorPosition(WIDTH / 2 - 10, 1);
	cout << "Vida animal: " << cntVidaAnimal;

	Console::SetCursorPosition(WIDTH / 2 - 10, 2);
	cout << "Particulas marcianas: " << cntParticulaMarciana;

	Console::SetCursorPosition(WIDTH / 2 - 10, 3);
	Console::ForegroundColor = ConsoleColor::Red;
	cout << "Vidas: " << nave->getVidas() << char(3);
	Console::ResetColor();
}

void Controladora::evaluarColisiones()
{
	if (dodo->intersectar(nave)) {
		if (dodo->fueRecolectado() && nave->fueRecolectado()) {
			nave->disminuirVidas();
		}	
	}

	for (int i = 0; i < flores->getSize(); i++)
	{
		if (!flores->getObjeto(i)->fueRecolectado() &&
			flores->getObjeto(i)->intersectar(nave)) {
			cntVidaVegetal++;
		}
	}

	for (int i = 0; i < animales->getSize(); i++)
	{
		if (!animales->getObjeto(i)->fueRecolectado() &&
			animales->getObjeto(i)->intersectar(nave)) {
			cntVidaAnimal++;
		}
	}

	for (int i = 0; i < particulas->getSize(); i++)
	{
		if (particulas->getObjeto(i)->intersectar(nave)) {
			particulas->getObjeto(i)->borrar();
			particulas->eliminar(i);
			cntParticulaMarciana++;
			i--;
		}
	}
}

void Controladora::jugar()
{
	do
	{
		mostrarMetricas();
		evaluarColisiones();
		nave->animar();
		dodo->animar();
		flores->animarTodos();
		animales->animarTodos();
		particulas->animarTodos();
		_sleep(120);
	} while (nave->getVidas() > 0);
}
