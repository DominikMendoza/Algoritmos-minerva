#pragma once
#include "Figura.hpp"
class Triangulo : public Figura
{
private:
	int base;
	int altura;
public:
	Triangulo(int _base, int _altura);
	~Triangulo();
	double calculaArea() override;
};

Triangulo::Triangulo(int _base, int _altura) : Figura()
{
	base = _base;
	altura = _altura;
}

Triangulo::~Triangulo()
{
}

double Triangulo::calculaArea() {
	return (base * altura) / 2.0;
}