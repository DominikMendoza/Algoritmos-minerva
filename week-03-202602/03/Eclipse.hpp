#pragma once
#include <iostream>
#include <string>

using namespace std;

class Eclipse
{
private:
	string tipoEclipse;
	string fecha;
	int hora;
	bool huboSismos;
	bool huboLluvias;
	string continenteVisibilidad;
    void obtenerContinenteValido();
public:
	Eclipse();
	Eclipse(string tipoEclipse, string fecha, int hora, bool huboSismos, bool huboLluvias, string continenteVisibilidad);
	~Eclipse();

	void leerDatos();
	void imprimir();

    string getTipoDeEclipse();
    bool getHuboSimos();
    string getContinenteDeMayorVisibilidad();
};

void Eclipse::obtenerContinenteValido()
{
    int opcion;
    do
    {
        system("cls");
        cout << "Ingrese el continente de mayor visibilidad:\n";
        cout << "1. America del Sur\n";
        cout << "2. Europa\n";
        cout << "3. Africa\n";
        cout << "4. America del Norte\n";
        cout << "5. Asia\n";
        cout << "Seleccione una opcion (1-5): ";
        cin >> opcion;

    } while (opcion < 1 || opcion > 5);

	switch (opcion) {
	case 1: this->continenteVisibilidad = "America del Sur"; break;
	case 2: this->continenteVisibilidad = "Europa"; break;
	case 3: this->continenteVisibilidad = "Africa"; break;
	case 4: this->continenteVisibilidad = "America del Norte"; break;
	case 5: this->continenteVisibilidad = "Asia"; break;
	};
}

Eclipse::Eclipse()
{
	tipoEclipse = "lunar";
	fecha = "24-03-1999";
	hora = rand() % 1000 + 300;
	huboSismos = rand() % 2;
	huboLluvias = rand() % 2;
	continenteVisibilidad = "America del Sur";
}

Eclipse::Eclipse(string tipoEclipse, string fecha, int hora, bool huboSismos, bool huboLluvias, string continenteVisibilidad)
	: tipoEclipse(tipoEclipse), fecha(fecha) // sugar sintax
{
	this->hora = hora;
	this->huboSismos = huboSismos;
	this->huboLluvias = huboLluvias;
	this->continenteVisibilidad = continenteVisibilidad;
}

Eclipse::~Eclipse()
{
}

void Eclipse::leerDatos()
{
    do
    {
        cout << "Ingrese tipo de eclipse (solar o lunar): ";
        cin >> tipoEclipse;
    } while (tipoEclipse != "solar" && tipoEclipse != "lunar");

    cout << "Ingrese fecha (ejemplo: 24-03-1999): ";
    cin >> fecha;

    do
    {
        cout << "Ingrese hora (ejemplo: 100, 300, 1200, 1400): ";
        cin >> hora;
    } while (hora < 0 || hora > 2400);


    int huboSismos;
    do
    {
        cout << "Hubo sismos (0: no | 1: si): ";
        cin >> huboSismos;
    } while (huboSismos < 0 || huboSismos > 1);
    this->huboSismos = huboSismos;

    int huboLluvias;
    do
    {
        cout << "Hubo lluvias (0: no | 1: si): ";
        cin >> huboLluvias;
    } while (huboLluvias < 0 || huboLluvias > 1);
    this->huboLluvias = huboLluvias;

	obtenerContinenteValido();
}

void Eclipse::imprimir()
{
	cout << "Tipo de eclipse: " << tipoEclipse << endl;
	cout << "Fecha: " << fecha << endl;
	cout << "Hora: " << hora << endl;
	cout << "Hubo sismos: " << (huboSismos ? "Si" : "No") << endl;
	cout << "Hubo lluvias: " << (huboLluvias ? "Si" : "No") << endl;
	cout << "Continente de visibilidad: " << continenteVisibilidad << endl;
}

string Eclipse::getTipoDeEclipse()
{
    return this->tipoEclipse;
}

bool Eclipse::getHuboSimos()
{
    return this->huboSismos;
}

string Eclipse::getContinenteDeMayorVisibilidad()
{
    return this->continenteVisibilidad;
}
