#pragma once
#include "Equipo.hpp"

class Laptop : public Equipo
{
private:
	int ramGb, almacenamientoGb;

public:
	Laptop(int ramGb, int almacenamientoGb, string marca, string modelo, float precio);
	~Laptop();
	void mostrarDatos();
};

Laptop::Laptop(int ramGb, int almacenamientoGb, string marca, string modelo, float precio)
	: Equipo(marca, modelo, precio)
{
	this->ramGb = ramGb;
	this->almacenamientoGb = almacenamientoGb;
}

Laptop::~Laptop()
{
}

void Laptop::mostrarDatos()
{
	cout << "Ram: " << ramGb << " GB" << endl;
	cout << "Almacenamiento: " << almacenamientoGb << " GB" << endl;
	this->mostrarInfo();
}
