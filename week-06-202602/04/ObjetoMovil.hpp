#pragma once
#include <iostream>
#define WIDTH 80
#define HEIGHT 40
using namespace System;
using namespace std;

class ObjetoMovil
{
protected:
	int x, y, ancho, alto;
	int dx, dy;
public:
	ObjetoMovil(int x, int y);
	~ObjetoMovil();
	void borrar();
	virtual void mover();
	virtual void dibujar();
	void animar();
	bool estaColisionando(ObjetoMovil* obj);
};

ObjetoMovil::ObjetoMovil(int x, int y)
{
	this->x = x;
	this->y = y;
	dx = dy = 0;
}

ObjetoMovil::~ObjetoMovil()
{
}

void ObjetoMovil::borrar()
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

void ObjetoMovil::mover()
{
	if (x + dx < 0 || x + ancho + dx > WIDTH) {
		dx *= -1;
	}
	if (y + dy < 0 || y + alto + dy > HEIGHT) {
		dy *= -1;
	}

	x += dx;
	y += dy;
}

void ObjetoMovil::dibujar()
{
}

void ObjetoMovil::animar()
{
	borrar();
	mover();
	dibujar();
}

bool ObjetoMovil::estaColisionando(ObjetoMovil* obj)
{
	return
		this->x < obj->x + obj->ancho &&
		obj->x < this->x + this->ancho &&
		this->y < obj->y + obj->alto &&
		obj->y < this->y + this->alto;
}
