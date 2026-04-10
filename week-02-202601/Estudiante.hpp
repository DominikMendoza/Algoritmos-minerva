#pragma once
#include <iostream>

using namespace std;

class Estudiante
{
private:
	int nota1;
	int nota2;
	int nota3;
public:
	Estudiante(int nota1, int nota2, int nota3);
	~Estudiante();
	float calcularPromedio();
	void determinarSiAprueba();
	void imprimirNotas();
};

Estudiante::Estudiante(int nota1, int nota2, int nota3)
{
	this->nota1 = nota1;
	this->nota2 = nota2;
	this->nota3 = nota3;
}

Estudiante::~Estudiante()
{
}

float Estudiante::calcularPromedio()
{
	float suma = 0.0f;
	suma += nota1 + nota2 + nota3;
	float promedio = suma / 3;
	return promedio;
}

void Estudiante::determinarSiAprueba()
{
	float promedio = calcularPromedio();
	if (promedio < 13) {
		cout << "El estudiante desaprobo\n";
	}
	else {
		cout << "El estudiante aprobo\n";
	}
}

void Estudiante::imprimirNotas()
{
	cout << "nota 1: " << nota1 << "\n";
	cout << "nota 2: " << nota2 << "\n";
	cout << "nota 3: " << nota3 << "\n";
}
