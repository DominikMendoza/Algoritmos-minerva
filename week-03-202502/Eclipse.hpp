#pragma once
#include <iostream>
using namespace std;

class Eclipse
{
private:
	char tipo;
	bool huboSismos;
	long long hora;
public:
	Eclipse();
	~Eclipse();
	void readData();
	void imprimir();

	bool provocoSismos();
	bool fueNocturno();
};

Eclipse::Eclipse()
{
	tipo = rand() % ('Z' - 'A' + 1) + 'A';
	huboSismos = rand() % 2;
	hora = rand() % 5000;
	/*this->readData();*/
}

Eclipse::~Eclipse()
{
}

void Eclipse::readData()
{
	cout << "Ingrese tipo: "; cin >> tipo;
	cout << "Ingrese si hubo sismos (0 | 1): "; cin >> huboSismos;
	cout << "Ingrese la hora: "; cin >> hora;
}

void Eclipse::imprimir()
{
	cout << "Tipo: " << tipo << endl;
	cout << "Hubo sismos: " << huboSismos << endl;
	cout << "Hora: " << hora << endl << endl;
}

bool Eclipse::provocoSismos()
{
	return huboSismos;
}

bool Eclipse::fueNocturno()
{
	// rango nocturno
	return ((hora >= 0 && hora <= 300) || (hora >= 1900 && hora <= 2400));
}
