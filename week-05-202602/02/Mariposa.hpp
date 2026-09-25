#pragma once
#include "Insecto.hpp"

class Mariposa : public Insecto
{
private:
	double envergaduraAlas;
	string tipoAlimentacion;
public:
	Mariposa();
	~Mariposa();
	void imprimir();
};

Mariposa::Mariposa() : Insecto()
{
	envergaduraAlas = 6.5f;
	tipoAlimentacion = "fruta";
}

Mariposa::~Mariposa()
{
}

void Mariposa::imprimir()
{
	this->imprimirBase();
	cout << "Envergadura de alas: " << envergaduraAlas << " cm" << endl;
	cout << "Tipo de alimentacion: " << tipoAlimentacion << endl << endl;
}