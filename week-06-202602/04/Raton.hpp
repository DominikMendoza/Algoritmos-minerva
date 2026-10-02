#pragma once
#include "ObjetoMovil.hpp"

class Raton : public ObjetoMovil
{
private:

public:
	Raton(int x, int y);
	~Raton();
	void dibujar() override;
};

Raton::Raton(int x, int y) : ObjetoMovil(x, y)
{
	this->ancho = 7;
	this->alto = 1;
	do
	{
		dx = rand() % 2;
		dy = rand() % 2;
	} while (dx == 0 && dy == 0);
	
}

Raton::~Raton()
{
}

void Raton::dibujar()
{
	Console::SetCursorPosition(x, y);
	cout << "--(_c'>";
}
