#pragma once
#include <conio.h>
#include "Movil.hpp"

class Gato : public Movil
{
private:

public:
	Gato();
	~Gato();
	void mover() override;
	void dibujar() override;
};

Gato::Gato() : Movil(WIDTH / 2, HEIGHT / 2)
{
	this->alto = 3;
	this->ancho = 5;
}

Gato::~Gato()
{
}

void Gato::mover()
{
	if (_kbhit()) {
		char tecla = _getch();
		tecla = toupper(tecla);

		switch (tecla)
		{
		case 'W': dx = 0; dy = -1; break;
		case 'A': dx = -1; dy = 0; break;
		case 'S': dx = 0; dy = 1; break;
		case 'D': dx = 1; dy = 0; break;
		}

		if (x + dx < 0 || x + dx + ancho > WIDTH) {
			dx = 0;
		}
		if (y + dy < 0 || y + dy + alto > HEIGHT) {
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
