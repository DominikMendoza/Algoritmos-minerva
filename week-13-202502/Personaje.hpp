#pragma once
#include "Objeto.hpp"

class Personaje : public Objeto
{
private:
	int vidas;
public:
	Personaje(int x, int y, int width, int height, int vidas);
	~Personaje();
	void mover(Graphics^ g, char tecla);
	void resetearCoordenadas();
	int getDireccion();
};

Personaje::Personaje(int x, int y, int width, int height, int vidas) : Objeto(x, y, width, height)
{
	this->width = width;
	this->height = height;
	zoom = 0.7f;
	idx = idy = 0;
	dx = dy = 5;
}

Personaje::~Personaje()
{
}
void Personaje::mover(Graphics^ g, char tecla)
{
	switch (tecla)
	{
	case 'W': {
		if (y - dy < 0) return;
		idy = 3; // sprite hacia arriba
		y -= dy;
		break;
	}
	case 'A': {
		if (x - dx < 0) return;
		idy = 1; // sprite hacia la izquierda
		x -= dx;
		break;
	}
	case 'S': {
		if (y + height * zoom + dy > g->VisibleClipBounds.Height) return;
		idy = 0; // sprite hacia abajo
		y += dy;
		break;
	}
	case 'D': {
		if (x + width * zoom + dx > g->VisibleClipBounds.Width) return;
		idy = 2; // sprite hacia la derecha
		x += dx;
		break;
	}
	}

	idx++;
	if (idx > 3) {
		idx = 0;
	}
}

void Personaje::resetearCoordenadas()
{
	x = y = 150;
}

int Personaje::getDireccion()
{
	return this->idy;
}
