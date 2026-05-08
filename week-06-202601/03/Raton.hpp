#pragma once
#include "Movil.hpp"

class Raton : public Movil
{
private:

public:
	Raton();
	~Raton();
	void mover() override;
	void dibujar() override;
};

Raton::Raton() : Movil(rand() % (WIDTH - 7), rand() % HEIGHT)
{
	this->alto = 1;
	this->ancho = 7;
	dx = dy = 1;
}

Raton::~Raton()
{
}

void Raton::mover()
{
	if (x + dx < 0 || x + dx + ancho > WIDTH) {
		dx *= -1;
	}
	if (y + dy < 0 || y + dy + alto > HEIGHT) {
		dy *= -1;
	}

	x += dx;
	y += dy;
}

void Raton::dibujar()
{
	Console::SetCursorPosition(x, y);
	cout << "--(_c'>";
}
