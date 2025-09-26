#pragma once
#include "Equipo.hpp"

class Smartphone: public Equipo
{
private:
	int numCamaras;
	bool soporta5G;

public:
	Smartphone(int numCamaras, bool soporta5G, string marca, string modelo, float precio);
	~Smartphone();
	void mostrarDatos();
};

Smartphone::Smartphone(int numCamaras, bool soporta5G, string marca, string modelo, float precio)
	: Equipo(marca, modelo, precio)
{
	this->numCamaras = numCamaras;
	this->soporta5G = soporta5G;
}

Smartphone::~Smartphone()
{
}

void Smartphone::mostrarDatos()
{
	cout << "Numero de camaras: " << numCamaras << endl;
	cout << "Soporta 5G: " << (soporta5G ? "Si" : "No") << endl;
	this->mostrarInfo();
}
