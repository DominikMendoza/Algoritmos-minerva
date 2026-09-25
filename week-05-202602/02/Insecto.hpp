#pragma once
#include <iostream>
#include <string>

using namespace std;

class Insecto
{
private:
	string nombreCientifico;
	int numeroPatas;
	string color;
public:
	Insecto();
	Insecto(string color);
	~Insecto();
	virtual void imprimir();
	void imprimirBase();
};

Insecto::Insecto()
{
	nombreCientifico = "---";
	numeroPatas = 6;
	color = "rojo";
}

Insecto::Insecto(string color)
{
	this->color = color;
}

Insecto::~Insecto()
{
}

void Insecto::imprimir()
{
	cout << "Insecto base" << endl;
}

void Insecto::imprimirBase()
{
	cout << "Nombre cientifico: " << nombreCientifico << endl;
	cout << "Numero de patas: " << numeroPatas << endl;
	cout << "Color: " << color << endl;
}
