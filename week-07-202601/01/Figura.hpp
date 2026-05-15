#pragma once
#include <iostream>
using namespace std;

class Figura
{
protected:
	int a;
	int b;
public:
	Figura(int _ancho, int _alto);
	~Figura();
	virtual double calculaArea() = 0;
};

Figura::Figura(int _ancho = 0, int _alto = 0)
{
	a = _ancho;
	b = _alto;
}

Figura::~Figura()
{
}