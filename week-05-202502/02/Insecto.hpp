#pragma once
#include <iostream>
#include <string>

using namespace std;

class Insecto
{
protected:
	string nombreCientifico, color;
	int numeroPatas;
public:
	Insecto(string nombreCientifico, int numeroPatas, string color);
	~Insecto();

	void info();
	void virtual mostrarInfo();
};

Insecto::Insecto(string nombreCientifico, int numeroPatas, string color)
{
	this->nombreCientifico = nombreCientifico;
	this->numeroPatas = numeroPatas;
	this->color = color;
}

Insecto::~Insecto()
{
}

void Insecto::info()
{
	cout << "Nombre cientifico: " << nombreCientifico << endl;
	cout << "Numero de patas: " << numeroPatas << endl;
	cout << "Color: " << color << endl << endl;
}

void Insecto::mostrarInfo()
{
}
