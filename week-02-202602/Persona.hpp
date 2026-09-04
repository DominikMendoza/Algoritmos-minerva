#pragma once
#include <iostream>
#include <string>

using namespace std;

class Persona
{
private:
	string nombre;
	int edad;
	int DNI;
	char sexo;
	float peso, altura;
	int generaDNI();
	char comprobarSexo(char sexo);
public:
	Persona();
	Persona(string nombre, int edad, char sexo);
	Persona(string nombre, int edad,char sexo, float peso, float altura);
	~Persona();

	int IMC();
	bool esMayorDeEdad();
	string toString();
	
};

Persona::Persona()
{
	nombre = "";
	edad = 0;
	DNI = generaDNI();
	sexo = 'H';
	peso = altura = 0.0f;
}

Persona::Persona(string nombre, int edad, char sexo)
{
	this->nombre = nombre;
	this->edad = edad;
	DNI = generaDNI();
	this->sexo = comprobarSexo(sexo);
	peso = altura = 0.0f;
}

Persona::Persona(string nombre, int edad, char sexo, float peso, float altura)
{
	this->nombre = nombre;
	this->edad = edad;
	this->DNI = generaDNI();
	this->sexo = comprobarSexo(sexo);
	this->peso = peso;
	this->altura = altura;
}

Persona::~Persona()
{
}

int Persona::IMC()
{
	double imc = peso / (altura * altura);
	if (imc < 20) {
		return -1;
	}
	else {
		if (imc <= 25) {
			return 0;
		}
		else {
			return 1;
		}
	}
	return 0;
}

bool Persona::esMayorDeEdad()
{
	return edad >= 18;
}

char Persona::comprobarSexo(char sexo)
{
	if (sexo == 'H' || sexo == 'M') {
		return sexo;
	}
	return 'H';
}

string Persona::toString()
{
	string info = "";
	info += "\nNombre: " + nombre + "\n";
	info += "Edad: " + to_string(edad) + "\n";
	info += "DNI: " + to_string(DNI) + "\n";
	info += "Sexo: " + string(1, sexo) + "\n";
	info += "Altura: " + to_string(altura) + "\n\n";

	return info;
}

int Persona::generaDNI()
{
	return rand() % (99999999 - 10000000 + 1) + 10000000;
}
