#pragma once
#include "Figura.hpp"

class Rectangulo : public Figura
{
private:
	int lado1, lado2;
public:
	Rectangulo(int x, int y, int lado1, int lado2);
	~Rectangulo();
	void dibujar(Graphics^ g) override;
	double getArea() override;
};

Rectangulo::Rectangulo(int x, int y, int lado1, int lado2)
	: Figura(x, y)
{
	this->lado1 = lado1;
	this->lado2 = lado2;
}

Rectangulo::~Rectangulo()
{
}

void Rectangulo::dibujar(Graphics^ g)
{
	SolidBrush^ b = gcnew SolidBrush(Color::Green);
	g->FillRectangle(b, x, y, lado1, lado2);
}

double Rectangulo::getArea()
{
	return lado1 * lado2;
}
