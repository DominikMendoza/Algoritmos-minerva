#pragma once
#include <iostream>
#include <string>
using namespace std;

class Equipo
{
protected:
	string marca, modelo;
	float precio;
public:
	Equipo(string marca, string modelo, float precio);
	~Equipo();
	void mostrarInfo();

};

Equipo::Equipo(string marca, string modelo, float precio)
{
	this->marca = marca;
	this->modelo = modelo;
	this->precio = precio;
}

Equipo::~Equipo()
{
}

void Equipo::mostrarInfo()
{
	cout << "Marca: " << marca << endl;
	cout << "Modelo: " << modelo << endl;
	cout << "Precio: " << precio << endl << endl;
}
