#pragma once
#include <iostream>
#include <string>

using namespace std;

class Personal
{
private:
	string nombre, apellidos;
	string fecha;
public:
	Personal();
	~Personal();
	string obtenerInfo();
};

Personal::Personal()
{
	nombre = "nombre-" + to_string(char(rand() % ('z' - 'a' + 1) + 'a'));
	apellidos = "apellidos-" + to_string(char(rand() % ('z' - 'a' + 1) + 'a'));
	fecha = "ayer";
}

Personal::~Personal()
{
}

string Personal::obtenerInfo()
{
	return "Nombre: " + nombre + "\tApellidos: " + apellidos + "\tFecha: " + fecha + "\n";
}
