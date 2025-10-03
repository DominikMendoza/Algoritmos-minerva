#pragma once
#include "Terrestre.hpp"

class Carro : public Terrestre
{
private:

public:
	Carro(int x, int y);
	~Carro();
	void mover() override;
	void dibujar() override;
	int quitarVidaPersona(int vidaActual) override;

};

Carro::Carro(int x, int y) : Terrestre(x, y)
{
	this->width = 10;
	this->height = 3;
	this->dx = 0;
}

Carro::~Carro()
{
}

void Carro::mover()
{
	int aux = rand() % 3 + 2;
	dx = (dx < 0) ? aux * -1 : aux;
	
	/*if (dx < 0) {
		dx = aux * -1;
	}
	else {
		dx = aux;
	}*/

	if (x + dx < 0 || x + dx + width >= WIDTH) {
		dx *= -1;
	}

	x += dx;
}

void Carro::dibujar()
{
	Console::SetCursorPosition(x, y);
	cout << "____|~\\_";
	Console::SetCursorPosition(x, y + 1);
	cout << "[_____|_|-";
	Console::SetCursorPosition(x, y + 1);
	cout << "(_) (_)";
}

int Carro::quitarVidaPersona(int vidaActual)
{
	return 0;
}
