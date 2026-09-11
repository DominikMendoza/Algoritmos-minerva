#pragma once
#include "Eclipse.hpp"

class ArrEclipse
{
private:
	Eclipse** arr;
	int size;
public:
	ArrEclipse();
	~ArrEclipse();
	void agregar(Eclipse* e);
	void modificarDatos(int pos);
	void eliminarElemento(int pos);
	void imprimirTodos();

	void reporteDeEclipsesVisiblesEnEuropa();
	void reporteDeEclipsesSismos();
	void reporteDeEclipsesNocturnos();
};

ArrEclipse::ArrEclipse()
{
	arr = nullptr;
	size = 0;
}

ArrEclipse::~ArrEclipse()
{
}

void ArrEclipse::agregar(Eclipse* e)
{
	Eclipse** tmp = new Eclipse * [size + 1];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = arr[i];
	}
	tmp[size] = e;

	delete[] arr;
	arr = tmp;
	size++;
}

void ArrEclipse::modificarDatos(int pos)
{
	if (pos < 0 || pos >= size) {
		cout << "Posicion invalida...\n";
		return;
	}

	arr[pos]->leerDatos();
}

void ArrEclipse::eliminarElemento(int pos)
{
	if (pos < 0 || pos >= size) {
		cout << "Posicion invalida...\n";
		return;
	}

	Eclipse** tmp = new Eclipse * [size - 1];
	for (int i = 0; i < size; i++)
	{
		if (i < pos) {
			tmp[i] = arr[i];
		}
		else if (i > pos) {
			tmp[i - 1] = arr[i];
		}
	}

	delete[] arr;
	arr = tmp;
	size--;

	cout << "\nElemento en la posicion " << pos << " eliminado\n";
}

void ArrEclipse::imprimirTodos()
{
	for (int i = 0; i < size; i++)
	{
		cout << "----Datos del eclipse " << i + 1 << "----" << endl;
		arr[i]->imprimir();
		cout << endl;
	}
}

void ArrEclipse::reporteDeEclipsesVisiblesEnEuropa()
{
	cout << "-----Eclipses visibles en Europa------\n";
	for (int i = 0; i < size; i++)
	{
		if (arr[i]->getContinenteDeMayorVisibilidad() == "Europa") {
			arr[i]->imprimir();
			cout << endl;
		}
	}
	cout << "\n------Final de reporte de eclipses visibles en Europa\n";
}

void ArrEclipse::reporteDeEclipsesSismos()
{
	cout << "-----Eclipses con sismos------\n";
	for (int i = 0; i < size; i++)
	{
		if (arr[i]->getHuboSimos()) {
			arr[i]->imprimir();
			cout << endl;
		}
	}
	cout << "\n------Final de reporte de eclipses con sismos\n";
}

void ArrEclipse::reporteDeEclipsesNocturnos()
{
	cout << "-----Eclipses nocturnos------\n";
	for (int i = 0; i < size; i++)
	{
		if (arr[i]->getTipoDeEclipse() == "lunar") {
			arr[i]->imprimir();
			cout << endl;
		}
	}
	cout << "\n------Final de reporte de eclipses nocturnos\n";
}
