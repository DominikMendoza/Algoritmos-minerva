#pragma once
#include <iostream>
#define WIDTH 80
#define HEIGHT 40
using namespace System;
using namespace std;

class Movil
{
protected:
	int x, y, dx, dy;
	int ancho, alto;
public:
	Movil(int x, int y);
	~Movil();
	void borrar();
	virtual void mover() = 0;
	virtual void dibujar() = 0;
	void animar();
	bool estaColisionando(Movil* m);
};

Movil::Movil(int x, int y)
{
	this->x = x;
	this->y = y;
	dx = dy = 0;
}

Movil::~Movil()
{
}

void Movil::borrar()
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

void Movil::animar()
{
	this->borrar();
	this->mover();
	this->dibujar();
}

bool Movil::estaColisionando(Movil* m)
{
	return
		this->x < m->x + m->ancho &&
		m->x < this->x + this->ancho &&
		this->y < m->y + m->alto &&
		m->y < this->y + this->alto;
}
