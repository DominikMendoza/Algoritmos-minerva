#pragma once
#include "Persona.hpp"

class Estudiante : public Persona
{
protected:
	string DNI, nivelDeEstudios;
public:
	Estudiante();
	~Estudiante();
};

Estudiante::Estudiante()
{
	/*cout << "Ingrese DNI: ";
	cin >> this->DNI;

	cout << "Ingrese nivel de estudios: ";
	cin >> this->nivelDeEstudios;*/

	this->DNI = to_string(rand() % (99999 - 10000 + 1) + 10000);
	this->nivelDeEstudios = "Nivel-" + to_string(rand() % 3 + 1);
}

Estudiante::~Estudiante()
{
}