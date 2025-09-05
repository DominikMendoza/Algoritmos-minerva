#pragma once
#include <iostream>
#include <string>
using namespace std;

class Cuenta
{
private:
	string titular;
	double cantidad;
public:
	Cuenta(string titular);
	Cuenta(string titular, double cantidad);
	~Cuenta();

	void mostrarCuenta();
	void ingresar(double cantidad);
	void retirar(double cantidad);


	string getTitular();
	double getCantidad();
	void setTitular(string titular);
	void setCantidad(double cantidad);
};

Cuenta::Cuenta(string titular)
{
	this->titular = titular;
	cantidad = 0.0;
}

Cuenta::Cuenta(string titular, double cantidad)
{
	this->titular = titular;
	this->cantidad = cantidad;
}

Cuenta::~Cuenta()
{
}

string Cuenta::getTitular()
{
	return this->titular;
}

double Cuenta::getCantidad()
{
	return this->cantidad;
}

void Cuenta::setTitular(string titular)
{
	this->titular = titular;
}

void Cuenta::setCantidad(double cantidad)
{
	this->cantidad = cantidad;
}

void Cuenta::mostrarCuenta()
{
	cout << "Titular: " << titular << endl;
	cout << "Cantidad: " << cantidad << endl << endl;
}

void Cuenta::ingresar(double cantidad)
{
	// negativa
	if (cantidad > 0) { // si la cantidad es mayor la sumo
		this->cantidad += cantidad;
		cout << "Se ingreso " << cantidad << " saldo, resultante: " << this->cantidad << endl;
	}
}

void Cuenta::retirar(double cantidad)
{
	this->cantidad -= cantidad;
	cout << "Se retiro " << cantidad << " saldo";

	if (this->cantidad < 0) {
		this->cantidad = 0;
	}
	cout << ", resultante: " << this->cantidad << endl;
}

