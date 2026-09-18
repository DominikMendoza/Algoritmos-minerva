#pragma once
#include "Chasis.hpp"
#include "Llanta.hpp"

#define WIDTH 80
#define HEIGHT 40

class Carro
{
private:
	int x, y, dx, dy;
	int ancho, alto;
	int color;
	Chasis chasis;
	Llanta llanta;
public:
	Carro(int x, int y, int color);
	~Carro();
	void borrar();
	void mover();
	void dibujar();
	void animar();
};

Carro::Carro(int x, int y, int color)
{
	this->x = x;
	this->y = y;
	this->ancho = 5;
	this->alto = 3;
	this->dx = 0;
	this->dy = 0;
	this->color = color;
	chasis = Chasis();
	llanta = Llanta();
}

Carro::~Carro()
{
}

void Carro::borrar()
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

void Carro::mover()
{
	dx = rand() % 3 + 1;
	if (x + dx + ancho > WIDTH) {
		x = WIDTH - ancho;
		dx = 0;
	}
	x += dx;
	y += dy;
}

void Carro::dibujar()
{
	Console::ForegroundColor = ConsoleColor(color);
	chasis.dibujar(x, y + 1);
	llanta.dibujar(x, y);
	llanta.dibujar(x + 2, y);
	llanta.dibujar(x, y + 2);
	llanta.dibujar(x + 2, y + 2);
	Console::ResetColor();
}

void Carro::animar()
{
	borrar();
	mover();
	dibujar();
}
