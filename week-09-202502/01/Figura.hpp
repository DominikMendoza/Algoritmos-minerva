#pragma once
#include <iostream>
using namespace System::Drawing;

class Figura
{
protected:
	int x, y;
public:
	Figura(int x, int y);
	~Figura();
	virtual void dibujar(Graphics^ g) = 0;
	virtual double getArea() = 0;
};

Figura::Figura(int x, int y)
	: x(x), y(y)
{
}

Figura::~Figura()
{
}