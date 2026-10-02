#pragma once
#include <conio.h>
#include "ObjetoMovil.hpp"

class Gato : public ObjetoMovil
{
private:

public:
	Gato(int x, int y);
	~Gato();
	void mover() override;
	void dibujar() override;
};

Gato::Gato(int x, int y) : ObjetoMovil(x, y)
{
	this->ancho = 5;
	this->alto = 3;
	dx = dy = 0;
}

Gato::~Gato()
{
}

void Gato::mover()
{
	if (_kbhit()) {
		char tecla = toupper(_getch());
		switch (tecla)
		{
		case 'W': dx = 0; dy = -2; break;
		case 'A': dx = -2; dy = 0; break;
		case 'S': dx = 0; dy = 2; break;
		case 'D': dx = 2; dy = 0; break;
		}

		if (x + dx < 0 || x + ancho + dx > WIDTH) {
			dx = 0;
		}
		if (y + dy < 0 || y + alto + dy > HEIGHT) {
			dy = 0;
		}

		x += dx;
		y += dy;

		dx = dy = 0;
	}
}

void Gato::dibujar()
{
	Console::SetCursorPosition(x, y);
	cout << "/\\_/\\";
	Console::SetCursorPosition(x, y + 1);
	cout << "(o.o)";
	Console::SetCursorPosition(x, y + 2);
	cout << "> ^ <";
}
