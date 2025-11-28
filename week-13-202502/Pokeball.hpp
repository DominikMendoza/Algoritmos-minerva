#pragma once
#include "Objeto.hpp"

class Pokeball : public Objeto
{
private:
	void determinarDireccion(int direccionPersonaje);
public:
	Pokeball(int width, int height); // W_TOTAL / 3; H_TOTAL / 1
	~Pokeball();
	void mover(Graphics^ g, int direccionPersonaje);
	void resetearPokeball(int x, int y, int direccionPersonaje);
};

void Pokeball::determinarDireccion(int direccionPersonaje)
{
	switch (direccionPersonaje)
	{
	case 0: dy = 15; dx = 0; break;
	case 1: dy = 0; dx = -15; break;
	case 2: dy = 0; dx = 15; break;
	case 3: dy = -15; dx = 0; break;
	default:
		break;
	}
}

Pokeball::Pokeball(int width, int height) : Objeto(500, 250, width, height)
{
	this->width = width;
	this->height = height;
	zoom = 0.6f;
	visible = false;
}

Pokeball::~Pokeball()
{
}

void Pokeball::mover(Graphics^ g, int direccionPersonaje)
{
	if (!visible) return;

	if (x + dx < 0 || x + dx + width * zoom > g->VisibleClipBounds.Width) {
		dx = 0;
		cambiarVisibilidad();
	}
	if (y + dy < 0 || y + dy + height * zoom > g->VisibleClipBounds.Height) {
		dy = 0;
		cambiarVisibilidad();
	}

	x += dx;
	y += dy;
	
	idx++;
	if (idx > 2) {
		idx = 0;
	}
}

void Pokeball::resetearPokeball(int x, int y, int direccionPersonaje)
{
	this->setPosicion(x, y);
	this->determinarDireccion(direccionPersonaje);
}
