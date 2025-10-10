#pragma once
#include "Objeto.hpp"

class ObjetoMovil : public Objeto
{
protected:
	int dx, dy;
public:
	ObjetoMovil(int x, int y, int width, int height, int dx, int dy);
	~ObjetoMovil();
	virtual void mover() = 0;
	void animar() override;
};

ObjetoMovil::ObjetoMovil(int x, int y, int width, int height, int dx, int dy)
	: Objeto(x, y, width, height)
{
	this->dx = dx;
	this->dy = dy;
}

ObjetoMovil::~ObjetoMovil()
{
}

void ObjetoMovil::animar()
{
	borrar();
	mover();
	dibujar();
}
