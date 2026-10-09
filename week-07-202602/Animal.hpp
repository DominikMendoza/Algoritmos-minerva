#pragma once
#include "Objeto.hpp"

class Animal : public Objeto
{
public:
	Animal(int x, int y, int dx);
	~Animal();
private:
};

Animal::Animal(int x, int y, int dx) : Objeto(x, y)
{
	this->dx = dx;
	dy = 0;
	ancho = 7;
	alto = 3;
	color = 9;
}

Animal::~Animal()
{
}