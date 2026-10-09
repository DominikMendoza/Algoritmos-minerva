#pragma once
#include "Objeto.hpp"

class Dodo : public Objeto
{
public:
	Dodo(int x, int y);
	~Dodo();
private:
};

Dodo::Dodo(int x, int y) : Objeto(x, y)
{
	dy = 1;
	dx = 0;
	ancho = 5;
	alto = 5;
	color = 14;
}

Dodo::~Dodo()
{
}