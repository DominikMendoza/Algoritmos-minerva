#pragma once
#include "Insecto.hpp"

class Escarabajo : public Insecto
{
private:
	string familia;
	bool puedeVolar;
public:
	Escarabajo();
	~Escarabajo();
	void imprimir();
};

Escarabajo::Escarabajo() : Insecto()
{
	familia = "insecto";
	puedeVolar = true;
}

Escarabajo::~Escarabajo()
{
}

void Escarabajo::imprimir()
{
	this->imprimirBase();
	cout << "Familia: " << familia << endl;
	cout << "Puede volar: " << (puedeVolar ? "Si" : "No") << endl << endl;
}