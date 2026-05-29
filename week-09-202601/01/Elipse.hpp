#pragma once
#include "Figura.hpp"
#define PI 3.1416

class Elipse : public Figura
{
private:
	int radio;
public:
	Elipse(int x, int y, int radio);
	~Elipse();
	void dibujar(Graphics^ g) override;
	double calcularArea() override;
};

Elipse::Elipse(int x, int y, int radio) :Figura(x, y)
{
	this->radio = radio;
}

Elipse::~Elipse()
{
}

void Elipse::dibujar(Graphics^ g)
{
	SolidBrush^ sb = gcnew SolidBrush(Color::Blue);
	g->FillEllipse(sb, x, y, radio, radio);
}

double Elipse::calcularArea()
{
	return PI * radio * radio;
}
