#pragma once
#include "Persona.hpp"

class Empleado: public Persona
{
protected:
	float salario;
	string nombreEmpresa;
public:
	Empleado();
	~Empleado();

	string getNombreEmpresa();
};

Empleado::Empleado()
{
	/*cout << "Ingrese salario: ";
	cin >> salario;*/
	this->salario = rand() % 30000 / 100.0f;
	this->nombreEmpresa = "Empresa-" + to_string(rand() % 3 + 1);
}

Empleado::~Empleado()
{
}

string Empleado::getNombreEmpresa()
{
	return this->nombreEmpresa;
}
