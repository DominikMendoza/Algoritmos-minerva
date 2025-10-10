#pragma once
#include <iostream>
#include <string>
#define WIDTH 80
#define HEIGHT 40

using namespace System;
using namespace std;

class Objeto
{
protected:
	int x, y, width, height;
	bool colisionoCon;
public:
	Objeto(int x, int y, int width, int height);
	~Objeto();
	int getX();
	int getY();
	int getAncho();
	int getAlto();
	bool fueColisionado();
	void marcarComoColisionado();
	void borrar();
	virtual void dibujar();
	virtual void animar();
	bool estaColisionando(Objeto* obj);
};

Objeto::Objeto(int x, int y, int width, int height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->colisionoCon = false;
}

Objeto::~Objeto()
{
}

int Objeto::getX()
{
	return x;
}

int Objeto::getY()
{
	return y;
}

int Objeto::getAncho()
{
	return width;
}

int Objeto::getAlto()
{
	return height;
}

bool Objeto::fueColisionado()
{
	return colisionoCon;
}

void Objeto::marcarComoColisionado()
{
	this->colisionoCon = true;
}

void Objeto::borrar()
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			Console::SetCursorPosition(x + i, y + j);
			cout << " ";
		}
	}
}

void Objeto::dibujar()
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			Console::SetCursorPosition(x + i, y + j);
			cout << "*";
		}
	}
}

void Objeto::animar()
{
	borrar();
	dibujar();
}

bool Objeto::estaColisionando(Objeto* obj)
{
	return
		x < obj->getX() + obj->getAncho() &&
		obj->getX() < x + width &&
		y < obj->getY() + obj->getAlto() &&
		obj->getY() < y + height;
}
