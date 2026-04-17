#pragma once
#include <iostream>
#include <string>
using namespace std;
class Contacto
{
private:
	string telefono;
	char sexo;
	string fechaCump;
	string facultad, email, redSocial;

public:
	Contacto();
	Contacto(string telefono, char sexo, string fechaCump, string facultad, string email, string redSocial);
	~Contacto();
	void leerDatos();
	void imprimir();
	char getSexo();
	string getRedSocial();
	int getMesDeCumpleanos();
};

Contacto::Contacto()
{
	this->telefono = "+519999" + to_string(rand() % 10);
	this->sexo = 'V';
	this->fechaCump = "22/03/2019";
	this->facultad = "Ingenieria";
	this->email = "sample@gmail.com";
	this->redSocial = "Facebook";
}

Contacto::Contacto(string telefono, char sexo, string fechaCum, string facultad, string email, string redSocial)
{
	this->telefono = telefono;
	this->sexo = sexo;
	this->fechaCump = fechaCum;
	this->facultad = facultad;
	this->email = email;
	this->redSocial = redSocial;
}

Contacto::~Contacto()
{
}

void Contacto::leerDatos()
{
	cout << "Ingrese sexo (V | M): "; cin >> sexo;
	cout << "Ingrese fecha de cumpleanos (DD/MM/YYYY): "; cin >> fechaCump;
	cout << "Ingrese red social: "; cin >> redSocial;
}

void Contacto::imprimir()
{
	cout << "Telefono: " << telefono << "\n";
	cout << "Sexo: " << sexo << "\n";
	cout << "Red social: " << redSocial << "\n\n";
}

char Contacto::getSexo()
{
	return this->sexo;
}

string Contacto::getRedSocial()
{
	return this->redSocial;
}

int Contacto::getMesDeCumpleanos()
{
	// Extraer el mes, si la fecha de cumpleanos tiene este formato DD/MM/YYYY
	// Transformamos a entero
	return stoi(this->fechaCump.substr(3, 2));
}
