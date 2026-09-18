#pragma once
#include <iostream>
#include <string>

using namespace std;

class Personal
{
private:
	string nombre;
	string apellidos;
	string fechaContratacion;
public:
	Personal();
	~Personal();
	void imprimir();
};

Personal::Personal()
{
	cout << "Ingrese nombre del personal: ";
	cin >> nombre;

	cout << "Ingrese apellidos: ";
	cin >> apellidos;

	cout << "Ingrese fecha de contratacion: ";
	cin >> fechaContratacion;
}

Personal::~Personal()
{
}

void Personal::imprimir() {
	cout << "Nombre: " << nombre << endl;
	cout << "Apellidos: " << apellidos << endl;
	cout << "Fecha contratacion: " << fechaContratacion << endl;
}