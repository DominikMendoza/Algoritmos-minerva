#pragma once
#include "Figura.hpp"

class Rectangulo: public Figura
{
private:
	int lado1, lado2;
public:
	Rectangulo(int x, int y, int lado1, int lado2);
	~Rectangulo();
	void dibujar(Graphics^ g) override;
	double calcularArea() override;
};

Rectangulo::Rectangulo(int x, int y, int lado1, int lado2) :Figura(x, y)
{
	this->lado1 = lado1;
	this->lado2 = lado2;
}

Rectangulo::~Rectangulo()
{
}

void Rectangulo::dibujar(Graphics^ g)
{
	SolidBrush^ sb = gcnew SolidBrush(Color::Red);
	g->FillRectangle(sb, Rectangle(x, y, lado1, lado2));
}

double Rectangulo::calcularArea()
{
	return lado1 * lado2;
}
