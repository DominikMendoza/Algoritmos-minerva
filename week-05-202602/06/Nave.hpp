#pragma once
#include <iostream>
#include <string>
#define WIDTH 80
#define HEIGHT 40

using namespace System;
using namespace std;

class Nave
{
protected:
	int x, y, dy;
	int ancho, alto;
	int color;
public:
	Nave(int x, int y);
	~Nave();
	void borrar();
	void mover();
	virtual void dibujar();
	void animar();
};

Nave::Nave(int x, int y)
{
	this->x = x;
	this->y = y;
	this->dy = 1;
}

Nave::~Nave()
{
}

void Nave::borrar()
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

void Nave::mover()
{
	if (y + alto + dy > HEIGHT) {
		dy = 0;
	}
	y += dy;
}

void Nave::dibujar()
{
}

void Nave::animar()
{
	borrar();
	mover();
	dibujar();
}
