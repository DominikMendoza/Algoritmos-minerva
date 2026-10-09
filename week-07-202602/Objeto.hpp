#pragma once
#include <iostream>
using namespace System::Drawing;
using namespace System;
using namespace std;

#define WIDTH 80
#define HEIGHT 40

class Objeto
{
protected:
	int x, y, dx, dy;
	int ancho, alto;
	bool recolectado;
	int color;
public:
	Objeto(int x, int y);
	~Objeto();
	void borrar();
	virtual void mover();
	virtual void dibujar();
	bool intersectar(Objeto* obj);
	void animar();

	bool fueRecolectado();
};

Objeto::Objeto(int x, int y)
{
	this->x = x;
	this->y = y;
	this->recolectado = false;
	this->color = 15;
}

Objeto::~Objeto()
{
}

void Objeto::borrar()
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

void Objeto::mover()
{
	if (x + dx < 0 || x + dx + ancho > WIDTH) {
		dx *= -1;
	}
	if (y + dy < 0 || y + dy + alto > HEIGHT) {
		dy *= -1;
	}

	x += dx;
	y += dy;
}

void Objeto::dibujar()
{
	Console::ForegroundColor = ConsoleColor(color);
	for (int i = 0; i < ancho; i++)
	{
		for (int j = 0; j < alto; j++)
		{
			Console::SetCursorPosition(x + i, y + j);
			cout << "*";
		}
	}
	Console::ResetColor();
}

bool Objeto::intersectar(Objeto* obj)
{
	if (Rectangle(x, y, ancho, alto)
		.IntersectsWith(Rectangle(obj->x, obj->y, obj->ancho, obj->alto))) {
		this->recolectado = obj->recolectado = true;
		return true;
	}
	
	this->recolectado = obj->recolectado = false;
	return false;
}

void Objeto::animar()
{
	borrar();
	mover();
	dibujar();
}

bool Objeto::fueRecolectado()
{
	return recolectado;
}
