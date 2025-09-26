#pragma once
#include "Empleado.hpp"
#include "Universitario.hpp"

class Practicante : public Empleado, public Universitario
{
protected:
	string nombreDelProyecto;
	int totalDeHoras, horasCompletadas;
public:
	Practicante();
	~Practicante();

	void imprimir();
};

Practicante::Practicante() : Empleado(), Universitario()
{
	/*cout << "Ingrese nombre del proyecto: ";
	cin >> nombreDelProyecto;

	cout << "Ingrese el total de horas: ";
	cin >> totalDeHoras;

	cout << "Ingrese las horas completadas: ";
	cin >> horasCompletadas;*/

	this->nombreDelProyecto = "Proy-" + to_string(rand() % 3 + 1);
	this->totalDeHoras = rand() % 5 + 4;
	this->horasCompletadas = totalDeHoras - rand() % 3;

}

Practicante::~Practicante()
{
}

void Practicante::imprimir()
{
	cout << "Nombre de empresa: " << nombreEmpresa << endl;
	cout << "Nombre de universidad: " << nombreUniversidad << endl;
	cout << "Total de horas: " << totalDeHoras << endl << endl;
}
