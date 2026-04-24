#pragma once
#include "Ala.hpp"
#include "Fuselaje.hpp"
#include "TrenDeAterrizaje.hpp"

#define WIDTH 80
#define HEIGHT 40
class Avion
{
private:
	int x, y, ancho, alto;
	int dx, dy;
	int color;
	Ala* ala;
	Fuselaje* fuselaje;
	TrenDeAterrizaje* tren;
public:
	Avion(int x, int y);
	~Avion();
	void borrar();
	void mover();
	void dibujar();
	void animar();
};

Avion::Avion(int x, int y)
{
	this->x = x;
	this->y = y;
	this->ancho = 10;
	this->alto = 3;
	this->dx = 0;
	this->dy = 1;
	this->color = rand() % 15 + 1;

	ala = new Ala();
	fuselaje = new Fuselaje();
	tren = new TrenDeAterrizaje();
}

Avion::~Avion()
{
	delete ala;
	delete fuselaje;
	delete tren;
}

void Avion::borrar()
{
	for (int i = 0; i < ancho; i++)
	{
		for (int j = 0; j < alto; j++)
		{
			Console::SetCursorPosition(x + i, y + j);
			cout << " ";
		}
	}
}

void Avion::mover()
{
	// Ajustamos aleatoriedad
	if (rand() % 8 == 7) {
		// cambia la direccion
		if (rand() % 2 == 0) {
			dx = 1;
		}
		else {
			dx = -1;
		}
	}

	if (x + dx < 0 || x + dx + ancho > WIDTH) {
		dx = 0;
	}
	if (y + dy < 0 || y + dy + alto > HEIGHT) {
		dy = 0;
	}

	if (y + alto >= HEIGHT) {
		dx = 0;
	}

	x += dx;
	y += dy;
}

void Avion::dibujar()
{
	Console::ForegroundColor = ConsoleColor(color);
	ala->dibujar(x + 3, y);
	fuselaje->dibujar(x + 1, y + 1);
	tren->dibujar(x, y + 1);
	Console::ResetColor();
}

void Avion::animar()
{
	this->borrar();
	this->mover();
	this->dibujar();
}
