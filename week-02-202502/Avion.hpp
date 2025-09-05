#pragma once
#include <iostream>
#include <conio.h>
#define WIDTH 80
#define HEIGHT 40
using namespace System;
using namespace std;
class Avion
{
private:
	int x, y, color, dx, dy;
	int ancho, alto;
public:
	Avion(int x, int y, int dx, int dy);
	~Avion();
	void dibujar();
	void borrar();
	void cambiarMovimiento(char tecla);
	void mover();
	void explotar();
    void limpiar();
};

Avion::Avion(int x, int y, int dx, int dy)
{
	this->x = x;
	this->y = y;
	this->dx = dx;
	this->dy = dy;
	this->color = rand() % (15 - 1 + 1) + 1;
	this->ancho = 7;
	this->alto = 3;
}

Avion::~Avion()
{
}

void Avion::dibujar()
{
	Console::ForegroundColor = ConsoleColor(color);
	Console::SetCursorPosition(x, y);
	cout << "   |\\";
	Console::SetCursorPosition(x, y + 1);
	cout << "|----->";
	Console::SetCursorPosition(x, y + 2);
	cout << "   |/";
}

void Avion::borrar()
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

void Avion::cambiarMovimiento(char tecla)
{
	switch (tecla)
	{
	case 'W': dy = -1; dx = 0; break;
	case 'A': dy = 0; dx = -1; break;
	case 'S': dy = 1; dx = 0; break;
	case 'D': dy = 0; dx = 1; break;
	}
}

void Avion::mover()
{
	if (x + dx < 0 || x + dx + ancho > WIDTH) {
		dx = 0;
	}

	if (y + dy < 0 || y + dy + alto > HEIGHT) {
		dy = 0;
	}

	x += dx;
	y += dy;

	// dx = dy = 0;
}

void Avion::explotar()
{
    Console::Clear();
    Console::ForegroundColor = ConsoleColor::Red;

    Console::SetCursorPosition(x + 2, y + 1);
    cout << "***";
    Console::SetCursorPosition(x + 1, y);
    cout << " *** ";
    Console::SetCursorPosition(x + 1, y + 2);
    cout << " *** ";

    _sleep(500);

    Console::ForegroundColor = ConsoleColor::Yellow;

	limpiar();

    Console::SetCursorPosition(x, y);
    cout << " \\|/ ";
    Console::SetCursorPosition(x, y + 1);
    cout << "--*--";
    Console::SetCursorPosition(x, y + 2);
    cout << " /|\\ ";

    _sleep(500);

    Console::ForegroundColor = ConsoleColor::DarkGray;

    limpiar();

    Console::SetCursorPosition(x + 1, y);
    cout << "~ ~";
    Console::SetCursorPosition(x, y + 1);
    cout << "  .  ";
    Console::SetCursorPosition(x + 1, y + 2);
    cout << ". .";

    _sleep(500);

    Console::ForegroundColor = ConsoleColor::Gray;

    limpiar();

    Console::SetCursorPosition(x + 2, y);
    cout << ".";
    Console::SetCursorPosition(x + 1, y + 1);
    cout << " . ";
    Console::SetCursorPosition(x + 2, y + 2);
    cout << ".";

    _sleep(500);

    limpiar();
}

void Avion::limpiar()
{
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            Console::SetCursorPosition(x + i, y + j);
            cout << " ";
        }
    }
}
