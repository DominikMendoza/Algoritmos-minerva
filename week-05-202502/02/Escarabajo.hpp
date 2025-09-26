#pragma once
#include "Insecto.hpp"

class Escarabajo : public Insecto
{
private:
	string familia;
	bool puedeVolar;
public:
	Escarabajo(string familia, bool puedeVolar, string nombreCientifico, int numeroPatas, string color);
	~Escarabajo();

	void imprimir();
	void mostrarInfo() override;
};

Escarabajo::Escarabajo(string familia, bool puedeVolar, string nombreCientifico, int numeroPatas, string color)
	: Insecto(nombreCientifico, numeroPatas, color)
{
	this->familia = familia;
	this->puedeVolar = puedeVolar;
}

Escarabajo::~Escarabajo()
{
}

void Escarabajo::imprimir()
{
	cout << "Familia: " << familia << endl;
	cout << "Puede volar: " << (puedeVolar ? "Si" : "No") << endl;
	this->info();
}

void Escarabajo::mostrarInfo()
{
	cout << "Familia: " << familia << endl;
	cout << "Puede volar: " << (puedeVolar ? "Si" : "No") << endl;
	this->info();
}
