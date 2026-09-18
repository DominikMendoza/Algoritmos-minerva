#pragma once
#include "Personal.hpp"
#include "Animal.hpp"

class Diagnostico
{
private:
	string fecha;
	string descripcion;
	Personal* per;
	Animal* ani;
public:
	Diagnostico(Personal* per, Animal* ani);
	Diagnostico(string fecha, string descripcion, Personal* per, Animal* ani);
	~Diagnostico();
	void imprimir();
};

Diagnostico::Diagnostico(Personal* per, Animal* ani)
{
	cout << "Ingrese fecha: ";
	cin >> fecha;

	cout << "Ingrese descripcion: ";
	cin >> descripcion;

	this->per = per;
	this->ani = ani;
}

Diagnostico::Diagnostico(string fecha, string descripcion, Personal* per, Animal* ani)
{
	this->fecha = fecha;
	this->descripcion = descripcion;
	this->per = per;
	this->ani = ani;
}

Diagnostico::~Diagnostico()
{
}

void Diagnostico::imprimir() {
	cout << "Fecha: " << fecha << endl;
	cout << "Descripcion: " << descripcion << endl;
	cout << "---Datos del animal---\n";
	ani->imprimir();
	cout << "---Datos del personal---\n";
	per->imprimir();
	cout << "=============================" << endl;
}