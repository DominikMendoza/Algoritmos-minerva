#pragma once
#include "Chasis.hpp"
#include "Llanta.hpp"
#define WIDTH 80
#define HEIGHT 40

class Carro
{
private:
	Chasis* chasis;
	Llanta* llanta;
	int color;
	int x, y, ancho, alto;
public:
	Carro(int y);
	~Carro();
	void borrar();
	void mover();
	void dibujar();
	void animar();
};

Carro::Carro(int y)
{
	//x = rand() % (WIDTH - (ancho + 1));
	//y = rand() % (HEIGHT - (alto + 1));
	this->y = y;
	ancho = 5;
	alto = 3;
	x = 0;
	color = rand() % (15) + 1;
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
			cout << ' ';
		}
	}
}

void Carro::mover()
{
	int dx = rand() % 3 + 2;
	if (x + ancho + dx > WIDTH) {
		x = WIDTH - ancho;
		dx = 0;
	}
	x += dx;
}

void Carro::dibujar()
{
	Console::ForegroundColor = ConsoleColor(color);
	llanta->dibujar(x, y);
	llanta->dibujar(x + 2, y);
	chasis->dibujar(x, y + 1);
	llanta->dibujar(x, y + 2);
	llanta->dibujar(x + 2, y + 2);
	Console::ResetColor();
}

void Carro::animar()
{
	borrar();
	mover();
	dibujar();
}
