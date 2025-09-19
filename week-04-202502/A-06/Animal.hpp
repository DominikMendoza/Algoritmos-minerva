#pragma once
#include <iostream>
#include <string>

using namespace std;

class Animal
{
private:
	string tipo, nombre;
	int edad;
public:
	Animal();
	Animal(string tipo, string nombre, int edad);
	~Animal();
	string obtenerInfo();
};

Animal::Animal()
{
	tipo = "Ejemplo-" + to_string(char(rand() % ('z' - 'a' + 1) + 'a'));
	nombre = "nombre-" + to_string(char(rand() % ('z' - 'a' + 1) + 'a'));
	edad = rand() % 5 + 4;
}

Animal::Animal(string tipo, string nombre, int edad)
{
	this->tipo = tipo;
	this->nombre = nombre;
	this->edad = edad;
}

Animal::~Animal()
{
}

string Animal::obtenerInfo()
{
	return "Tipo: " + tipo + "\tNombre:" + nombre + "\tEdad: " + to_string(edad) + "\n";
}

