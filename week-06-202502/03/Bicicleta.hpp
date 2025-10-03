#pragma once
#include "Terrestre.hpp"

class Bicicleta : public Terrestre
{
private:

public:
	Bicicleta(int x, int y);
	~Bicicleta();
	void mover() override;
	void dibujar() override;
	int quitarVidaPersona(int vidaActual) override;

};

Bicicleta::Bicicleta(int x, int y) : Terrestre(x, y)
{
	this->width = 6;
	this->height = 2;
	this->dx = 2;
}

Bicicleta::~Bicicleta()
{
}

void Bicicleta::mover()
{
	if (x + dx < 0 || x + dx + width >= WIDTH) {
		dx *= -1;
	}

	x += dx;
}

void Bicicleta::dibujar()
{
	Console::SetCursorPosition(x, y);
	cout << ".._\\";
	Console::SetCursorPosition(x, y + 1);
	cout << "(o)(o)";
}

int Bicicleta::quitarVidaPersona(int vidaActual)
{
	return vidaActual - 1;
}
