#pragma once
#include <iostream>

using namespace std;

class Estudiante
{
private:
	int notaT1, notaT2, notaT3;
	void leerNotas();
public:
	Estudiante();
	Estudiante(int notaT1, int notaT2, int notaT3);
	~Estudiante();
	double obtenerPromedio();
};

void Estudiante::leerNotas()
{
	cout << "Ingrese nota 1: "; cin >> notaT1;
	cout << "Ingrese nota 2: "; cin >> notaT2;
	cout << "Ingrese nota 3: "; cin >> notaT3;
}

Estudiante::Estudiante()
{
	this->leerNotas();
}

Estudiante::Estudiante(int notaT1, int notaT2, int notaT3)
{
	this->notaT1 = notaT1;
	this->notaT2 = notaT2;
	this->notaT3 = notaT3;
}

Estudiante::~Estudiante()
{
}

double Estudiante::obtenerPromedio()
{
	double promedio = 0.0;
	promedio = (notaT1 + notaT2 + notaT3) / 3.0;
	return promedio;
}
