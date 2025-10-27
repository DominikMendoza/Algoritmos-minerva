#pragma once
#include "Figura.hpp"
#define PI 3.1416

class Circulo : public Figura
{
private:
	int diametro;
public:
	Circulo(int x, int y, int radio);
	~Circulo();
	void dibujar(Graphics^ g) override;
	double getArea() override;
};

Circulo::Circulo(int x, int y, int radio)
	: Figura(x, y)
{
	this->diametro = radio * 2;
}

Circulo::~Circulo()
{
}

void Circulo::dibujar(Graphics^ g)
{
	SolidBrush^ b = gcnew SolidBrush(Color::Red);
	g->FillEllipse(b, x, y, diametro, diametro);
}

double Circulo::getArea()
{
	return (PI * diametro * diametro) / 4.0;
}
