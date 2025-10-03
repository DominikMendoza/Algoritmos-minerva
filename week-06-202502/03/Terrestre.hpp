#pragma once
#include <iostream>
#include <string>
#define WIDTH 80
#define HEIGHT 40

using namespace System;
using namespace std;

class Terrestre
{
protected:
	int x, y, width, height;
	int dx;
public:
	Terrestre(int x, int y);
	~Terrestre();
	void borrar();
	virtual void mover() = 0;
	virtual void dibujar() = 0;

	void animar();
	virtual int quitarVidaPersona(int vidaActual) = 0;

	int getX();
	int getY();
	int getAncho();
	int getAlto();
};

Terrestre::Terrestre(int x, int y)
{
	this->x = x;
	this->y = y;
}

Terrestre::~Terrestre()
{
}

void Terrestre::borrar()
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			Console::SetCursorPosition(x + i, y + j);
			cout << ' ';
		}
	}
}

void Terrestre::animar()
{
	borrar();
	mover();
	dibujar();
}

int Terrestre::getX()
{
	return x;
}

int Terrestre::getY()
{
	return y;
}

int Terrestre::getAncho()
{
	return width;
}

int Terrestre::getAlto()
{
	return height;
}
