#pragma once
#include "Terrestre.hpp"

class Persona
{
protected:
	int x, y, dx, dy;
	int vida;
public:
	Persona();
	~Persona();
	void borrar();
	void mover(char tecla);
	void dibujar();
	bool estaColisionandoConVehiculo(Terrestre* t);
	
	void intersectarConVehiculo(Terrestre* t);

	int getVida();
};

Persona::Persona()
{
	this->x = WIDTH / 2;
	this->y = HEIGHT - 1;
	this->vida = 3;
}

Persona::~Persona()
{
}

void Persona::borrar()
{
	Console::SetCursorPosition(x, y);
	cout << ' ';
}

void Persona::mover(char tecla)
{
	switch (tecla)
	{
	case 'W': dx = 0; dy = -1; break;
	case 'A': dx = -1; dy = 0; break;
	case 'S': dx = 0; dy = 1; break;
	case 'D': dx = 1; dy = 0; break;
	}

	x += dx;
	y += dy;

	dx = dy = 0;
}

void Persona::dibujar()
{
	// Console::ForegroundColor = ConsoleColor(10);
	Console::ForegroundColor = ConsoleColor::Green;
	Console::SetCursorPosition(x, y);
	cout << char(254);
	Console::ResetColor();
}

bool Persona::estaColisionandoConVehiculo(Terrestre* t)
{
	return (
		this->x >= t->getX() &&
		this->x <= (t->getX() + t->getAncho()) &&
		this->y >= t->getY() &&
		this->y <= (t->getY() + t->getAlto()));
}

void Persona::intersectarConVehiculo(Terrestre* t)
{
	this->vida = t->quitarVidaPersona(this->vida);
	this->x = WIDTH / 2;
	this->y = HEIGHT - 1;
}

int Persona::getVida()
{
	return this->vida;
}
