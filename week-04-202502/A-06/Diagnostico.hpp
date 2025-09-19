#pragma once
#include "Animal.hpp"
#include "Personal.hpp"

class Diagnostico
{
private:
	string descripcion;
	string fecha;
public:
	Diagnostico(Animal* animal, Personal* personal);
	~Diagnostico();
	void mostrar();
};

Diagnostico::Diagnostico(Animal* animal, Personal* personal)
{
	descripcion =
		"Datos del animal: " + animal->obtenerInfo() +
		"Datos del personal: " + personal->obtenerInfo();
	fecha = "---";
}


Diagnostico::~Diagnostico()
{
}

void Diagnostico::mostrar()
{
	cout << "Descripcion\n" << descripcion;
}
