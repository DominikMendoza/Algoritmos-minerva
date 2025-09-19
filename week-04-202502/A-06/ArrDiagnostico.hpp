#pragma once
#include "Diagnostico.hpp"

class ArrDiagnostico
{
private:
	Diagnostico** arr;
	int size;
public:
	ArrDiagnostico();
	~ArrDiagnostico();
	void agregar(Animal* animal, Personal* personal);
	int getSize();
	Diagnostico* getElemento(int pos);
	void mostrarTodos();
};

ArrDiagnostico::ArrDiagnostico()
{
	arr = nullptr;
	size = 0;
}

ArrDiagnostico::~ArrDiagnostico()
{
}

void ArrDiagnostico::agregar(Animal* animal, Personal* personal)
{
	Diagnostico** tmp = new Diagnostico * [size + 1];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = arr[i];
	}

	Diagnostico* diag = new Diagnostico(animal, personal);
	tmp[size] = diag;

	delete[] arr;
	arr = tmp;
	size++;
}

int ArrDiagnostico::getSize()
{
	return this->size;
}

Diagnostico* ArrDiagnostico::getElemento(int pos)
{
	return arr[pos];
}

void ArrDiagnostico::mostrarTodos()
{
	cout << "====================\n";
	cout << "Reporte de diagnosticos\n";
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << ") ";
		arr[i]->mostrar();
	}
	cout << "====================\n";
}
