#pragma once
#include "Estudiante.hpp"

class Universitario : public Estudiante
{
protected:
	string nombreUniversidad;/*, carrera, materiasInscritas, notas;*/
public:
	Universitario();
	~Universitario();
	string getNombreUniversidad();
};

Universitario::Universitario()
{
	/*cout << "Ingrese nombre de la universidad: ";
	cin >> nombreUniversidad;*/
	this->nombreUniversidad = "Uni-" + to_string(rand() % 3 + 1);

	/*cout << "Ingrese carrera: ";
	cin >> carrera;

	cout << "Materias inscritas: ";
	cin >> materiasInscritas;

	cout << "Ingrese notas: ";
	cin >> notas;*/
}

Universitario::~Universitario()
{
}

string Universitario::getNombreUniversidad()
{
	return this->nombreUniversidad;
}
