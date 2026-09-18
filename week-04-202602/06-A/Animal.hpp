#pragma once
#include <iostream>
#include <string>

using namespace std;

class Animal
{
private:
	string tipo;
	string nombre;
	int edad;
public:
	Animal();
	~Animal();
	void imprimir();
};

Animal::Animal()
{
	cout << "Ingrese tipo de animal: ";
	cin >> tipo;

	cout << "Ingrese nombre: ";
	cin >> nombre;
}

Animal::~Animal()
{
}

void Animal::imprimir()
{
	cout << "Tipo: " << tipo << endl;
	cout << "Nombre: " << nombre << endl;
}
