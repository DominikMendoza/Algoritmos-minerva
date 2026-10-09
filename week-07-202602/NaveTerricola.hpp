#pragma once
#include <conio.h>
#include "Objeto.hpp"

class NaveTerricola : public Objeto
{
private:
	int vidas;
public:
	NaveTerricola(int x, int y);
	~NaveTerricola();
	void mover() override;
	int getVidas();
	void disminuirVidas();
};

NaveTerricola::NaveTerricola(int x, int y) : Objeto(x, y)
{
	vidas = 3;
	dx = 0; dy = 0;
	ancho = 6;
	alto = 6;
	color = 12;
}

NaveTerricola::~NaveTerricola()
{
}

void NaveTerricola::mover()
{
	if (_kbhit()) {
		char tecla = toupper(_getch());
		switch (tecla)
		{
		case 'W': dx = 0; dy = -1; break;
		case 'A': dx = -1; dy = 0; break;
		case 'S': dx = 0; dy = 1; break;
		case 'D': dx = 1; dy = 0; break;
		}
	}
	if (x + dx < 0 || x + dx + ancho > WIDTH) {
		dx = 0;
	}
	if (y + dy < 0 || y + dy + alto > HEIGHT) {
		dy = 0;
	}

	x += dx;
	y += dy;

	/*dx = 0;
	dy = 0;*/
}

int NaveTerricola::getVidas()
{
	return this->vidas;
}

void NaveTerricola::disminuirVidas()
{
	this->vidas--;
}
