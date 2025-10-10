#pragma once
#include "Objeto.hpp"

class NaveTerricola : public Objeto
{
protected:
	int dx, dy;
	int vida;
public:
	NaveTerricola();
	~NaveTerricola();
	void mover(char tecla);
	void dibujar() override;
	/*bool estaColisionandoConVehiculo(Objeto* t);
	void intersectarConVehiculo(Objeto* t);*/

	int getVida();
};

NaveTerricola::NaveTerricola() : Objeto(0, 3, 8, 5)
{
	this->vida = 3;
}

NaveTerricola::~NaveTerricola()
{
}

void NaveTerricola::mover(char tecla)
{
	switch (tecla)
	{
	case 'W': dx = 0; dy = -1; break;
	case 'A': dx = -1; dy = 0; break;
	case 'S': dx = 0; dy = 1; break;
	case 'D': dx = 1; dy = 0; break;
	}

	if (x + dx < 0 || x + dx + width >= WIDTH) dx = 0;
	if (y + dy < 0 || y + dy + height > HEIGHT) dy = 0;

	x += dx;
	y += dy;

	dx = dy = 0;
}

void NaveTerricola::dibujar()
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			if (i == 0 || i == width - 1 || j == 0 || j == height - 1) {
				Console::SetCursorPosition(x + i, y + j);
				cout << "*";
			}
		}
	}
}

int NaveTerricola::getVida()
{
	return this->vida;
}