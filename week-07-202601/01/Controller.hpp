#pragma once
#include "Figura.hpp"
#include "Rectangulo.hpp"
#include "Triangulo.hpp"
class Controller
{
private:
	Figura* rectangulo;
	Figura* triangulo;
public:
	Controller();
	~Controller();
	void mostrarDiferenciaDeAreas();
	void datosDelRectangulo();
};

Controller::Controller()
{
	int ladoMayor, ladoMenor, base, altura;
	cout << "-----Datos del rectangulo-----" << endl;
	cout << "Ingrese lado mayor: "; cin >> ladoMayor;
	cout << "Ingrese lado menor: "; cin >> ladoMenor;
	rectangulo = new Rectangulo(ladoMayor, ladoMenor);

	cout << "-----Datos del triangulo-----" << endl;
	cout << "Ingrese base: "; cin >> base;
	cout << "Ingrese altura: "; cin >> altura;
	triangulo = new Triangulo(base, altura);
}

Controller::~Controller()
{
	delete rectangulo, triangulo;
}

void Controller::mostrarDiferenciaDeAreas()
{
	cout << endl << "----Diferencia de areas-----" << endl;
	cout << "Area del rectangulo: " << rectangulo->calculaArea() << " u^2" << endl;
	cout << "Area del triangulo: " << triangulo->calculaArea() << " u^2" << endl;
	cout << "Diferencia de areas: " << rectangulo->calculaArea() - triangulo->calculaArea() << endl << endl;
}

void Controller::datosDelRectangulo()
{
	cout << "----Datos del rectangulo----" << endl;
	cout << "Area del rectangulo: " << rectangulo->calculaArea() << " u^2" << endl;
	cout << "La potencia ^3 es: " << pow(rectangulo->calculaArea(), 3) << endl;
}