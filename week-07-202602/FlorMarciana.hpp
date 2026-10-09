#pragma once
#include "Objeto.hpp"

class FlorMarciana: public Objeto
{
public:
	FlorMarciana(int x, int y);
	~FlorMarciana();
private:
};

FlorMarciana::FlorMarciana(int x, int y) : Objeto(x, y)
{
	dx = 0; dy = 0;
	ancho = 3;
	alto = 4;
	color = 10;
}

FlorMarciana::~FlorMarciana()
{
}