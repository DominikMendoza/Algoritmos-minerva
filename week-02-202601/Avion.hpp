#pragma once
#include <iostream>
#define WIDTH 80
#define HEIGHT 40

using namespace System;
using namespace std;

class Avion
{
private:
	int posX;
	int posY;
	int color;
	int dx;
	int dy;
public:
	Avion(int posX, int posY, int color, int dx, int dy);
	~Avion();
	void dibujar();
	void borrar();
	void mover();
	void explotar();
	void cambiarDireccion(char tecla);
	void setColor(int color);
};

Avion::Avion(int posX, int posY, int color, int dx, int dy)
{
	this->posX = posX;
	this->posY = posY;
	this->color = color;
	this->dx = dx;
	this->dy = dy;
}

Avion::~Avion()
{
}

void Avion::dibujar()
{
	Console::ForegroundColor = ConsoleColor(color);

	Console::SetCursorPosition(posX, posY);
	cout << "|\\___\\__";
	Console::SetCursorPosition(posX, posY + 1);
	cout << "|       \\";
	Console::SetCursorPosition(posX, posY + 2);
	cout << "|/----/--";

	Console::ResetColor();
}

void Avion::borrar()
{
	Console::SetCursorPosition(posX, posY);
	cout << "         ";
	Console::SetCursorPosition(posX, posY + 1);
	cout << "         ";
	Console::SetCursorPosition(posX, posY + 2);
	cout << "         ";
}

void Avion::mover()
{
	// Nos aseguramos de que no nos salgamos de la pantalla
	if (posX + dx < 0 || posX + dx + 9 > WIDTH) {
		// dx = 0; cancela movimiento
		dx = dx * -1;
	}
	if (posY + dy < 0 || posY + dy + 3 > HEIGHT) {
		// dy = 0; cancela movimiento
		dy = dy * -1;
	}
	posX = posX + dx;
	posY = posY + dy;
}

void Avion::explotar()
{
	Console::SetCursorPosition(posX, posY);
	cout << "    --   ";
	Console::SetCursorPosition(posX, posY + 1);
	cout << " --   -- ";
	Console::SetCursorPosition(posX, posY + 2);
	cout << "   --    ";
}

void Avion::cambiarDireccion(char tecla)
{
	switch (tecla)
	{
	case 'W': dx = 0; dy = -1; break;
	case 'A': dx = -1; dy = 0; break;
	case 'S': dx = 0; dy = 1; break;
	case 'D': dx = 1; dy = 0; break;
	default:
		break;
	}
}

void Avion::setColor(int color)
{
	this->color = color;
}