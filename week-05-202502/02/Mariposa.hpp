#pragma once
#include "Insecto.hpp"

class Mariposa: public Insecto
{
private:
	double envergaduraAlas;
	string tipoAlimentacion;
public:
	Mariposa(double envergaduraAlas, string tipoAlimentacion, string nombreCientifico, int numeroPatas, string color);
	~Mariposa();

	void imprimir();
	void mostrarInfo() override;
};

Mariposa::Mariposa(double envergaduraAlas, string tipoAlimentacion, string nombreCientifico, int numeroPatas, string color)
	: Insecto(nombreCientifico, numeroPatas, color)
{
	this->envergaduraAlas = envergaduraAlas;
	this->tipoAlimentacion = tipoAlimentacion;
}

Mariposa::~Mariposa()
{
}

void Mariposa::imprimir()
{
	cout << "Envergadura alas: " << envergaduraAlas << "cm" << endl;
	cout << "Tipo de alimentacion: " << tipoAlimentacion << endl;
	this->info();
}

void Mariposa::mostrarInfo()
{
	cout << "Envergadura alas: " << envergaduraAlas << "cm" << endl;
	cout << "Tipo de alimentacion: " << tipoAlimentacion << endl;
	this->info();
}
