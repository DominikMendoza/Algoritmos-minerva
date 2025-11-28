#pragma once
#include "Objeto.hpp"

class Pikachu : public Objeto
{
private:
public:
	Pikachu(int width, int height);
	~Pikachu();
	void mover(Graphics^ g);
};

Pikachu::Pikachu(int width, int height) : Objeto(150, 150, width, height)
{
	dx = 0;
	dy = 5;
	this->width = width;
	this->height = height;
	zoom = 1.2f;
	idx = idy = 0;
}

Pikachu::~Pikachu()
{
}

void Pikachu::mover(Graphics^ g)
{
	// Determinar sprite segun direccion
	if (dy < 0) {
		idy = 3;
	}
	if (dy > 0) {
		idy = 0;
	}
	if (dx < 0) {
		idy = 1;
	}
	if (dx > 0) {
		idy = 2;
	}

	// Evaluar limites
	if (x + dx < 0 || x + dx + width * zoom > g->VisibleClipBounds.Width) {
		dx *= -1;
	}
	if (y + dy < 0 || y + dy + height * zoom > g->VisibleClipBounds.Height) {
		dy *= -1;
	}

	x += dx;
	y += dy;

	idx++;
	if (idx > 3) {
		idx = 0;
	}
}
