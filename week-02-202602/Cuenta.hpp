#pragma once
#include <iostream>

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

	void ingresar(double cnt);
	void retirar(double cnt);
	void mostrarSaldo();
};

Cuenta::Cuenta(string titular)
{
	this->titular = titular;
	this->cantidad = 0.0;
}

Cuenta::Cuenta(string titular, double cantidad)
{
	this->titular = titular;
	this->cantidad = cantidad;
}

Cuenta::~Cuenta()
{
}

void Cuenta::ingresar(double cnt)
{
	if (cnt > 0) {
		this->cantidad += cnt;
	}
	// mostrarSaldo();
}

void Cuenta::retirar(double cnt)
{
	this->cantidad -= cnt;
	this->cantidad = max(this->cantidad, 0.0);
	// mostrarSaldo();
}

void Cuenta::mostrarSaldo()
{
	cout << "El saldo actual es: " << cantidad << endl;
}
