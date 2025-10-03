#pragma once
#include <conio.h>
#include "ArrTerrestre.hpp"
#include "Bicicleta.hpp"
#include "Carro.hpp"
#include "Persona.hpp"

class Juego
{
private:
	Persona* p;
	ArrTerrestre* arr;
public:
	Juego();
	~Juego();
	void jugar();
	void mostrarVidaJugador();
	void verificarColisiones();
};

Juego::Juego()
{
	p = new Persona();
	arr = new ArrTerrestre();
	arr->agregar(new Bicicleta(WIDTH / 2, 1));
	arr->agregar(new Carro(0, HEIGHT / 2));
	arr->agregar(new Bicicleta(15, 30));
}

Juego::~Juego()
{
}

void Juego::jugar()
{
	while (p->getVida() > 0)
	{
		p->borrar();
		if (_kbhit()) {
			char tecla = toupper(_getch());
			p->mover(tecla);
		}
		p->dibujar();
		arr->animarTodos();

		verificarColisiones();
		mostrarVidaJugador();
		_sleep(90);
	}
	_sleep(2000);
	Console::Clear();
	Console::ForegroundColor = ConsoleColor::Red;
	Console::SetCursorPosition((WIDTH - 10)/ 2, HEIGHT /2);
	cout << "GAME OVER";
}

void Juego::mostrarVidaJugador()
{
	Console::SetCursorPosition(WIDTH - 3, 0);
	cout << p->getVida();
	Console::ForegroundColor = ConsoleColor::Red;
	cout << char(3);
	Console::ResetColor();
}

void Juego::verificarColisiones()
{
	for (int i = 0; i < arr->getSize(); i++)
	{
		Terrestre* terr = arr->getElement(i);
		if (p->estaColisionandoConVehiculo(terr)) {
			p->intersectarConVehiculo(terr);
		}
	}
}
