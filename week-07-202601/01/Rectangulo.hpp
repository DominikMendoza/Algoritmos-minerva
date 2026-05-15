#pragma once
#include "Figura.hpp"
class Rectangulo : public Figura
{
public:
	Rectangulo(int _ancho, int _alto);
	~Rectangulo();
	double calculaArea() override;
};

Rectangulo::Rectangulo(int _ancho, int _alto) : Figura(_ancho, _alto)
{
}

Rectangulo::~Rectangulo()
{
}

double Rectangulo::calculaArea() {
	return a * b;
}