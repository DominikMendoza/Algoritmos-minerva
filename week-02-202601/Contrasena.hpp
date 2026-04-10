#pragma once
#include <iostream>
using namespace std;

class Contrasena
{
private:
	int longitud;
	string password;
	void generarNuevaPassword();
public:
	Contrasena();
	~Contrasena();
	Contrasena(int longitud);
	bool esSegura();
	string getPassword();
	int getLongitud();
	void setLongitud(int longitud);
};

void Contrasena::generarNuevaPassword()
{
	password = "";
	
	for (int i = 0; i < longitud; i++)
	{
		int valor = rand() % 3;
		char letra = '-';
		switch (valor)
		{
		case 0: letra = rand() % ('Z' - 'A' + 1) + 'A'; break;
		case 1: letra = rand() % ('z' - 'a' + 1) + 'a'; break;
		case 2: letra = rand() % ('9' - '0' + 1) + '0'; break;
		}
		password += letra;
	}
}

Contrasena::Contrasena()
{
	this->longitud = rand() % 6 + 5;
	this->generarNuevaPassword();
}

Contrasena::Contrasena(int longitud)
{
	this->longitud = longitud;
	this->generarNuevaPassword();
}

bool Contrasena::esSegura()
{
	/*
	* +2 mayusculas
	* +1 minuscula
	* +5 numeros
	*/
	int cntMayusculas, cntMinusculas, cntNumeros;
	cntMayusculas = cntMinusculas = cntNumeros = 0;
	for (int i = 0; i < longitud; i++)
	{
		if (password[i] >= 'A' && password[i] <= 'Z') {
			cntMayusculas++;
		}
		if (password[i] >= 'a' && password[i] <= 'z') {
			cntMinusculas++;
		}
		if (password[i] >= '0' && password[i] <= '9') {
			cntNumeros++;
		}
	}

	// cout << "Mayusculas: " << cntMayusculas << "\t" << "Minusculas: ";
	// cout << cntMinusculas << "\t" << "Numeros: " << cntNumeros << "\n";

	if (cntMayusculas > 2 && cntMinusculas > 1 && cntNumeros > 5) {
		return true;
	}

	return false;
}

string Contrasena::getPassword()
{
	return this->password;
}

int Contrasena::getLongitud()
{
	return this->longitud;
}

void Contrasena::setLongitud(int longitud)
{
	this->longitud = longitud;
	this->generarNuevaPassword();
}

Contrasena::~Contrasena()
{
}