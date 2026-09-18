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
	void agregar(Diagnostico* e);
	void imprimirTodos();
};

ArrDiagnostico::ArrDiagnostico()
{
	arr = nullptr;
	size = 0;
}

ArrDiagnostico::~ArrDiagnostico()
{
}

void ArrDiagnostico::agregar(Diagnostico* e)
{
	Diagnostico** tmp = new Diagnostico * [size + 1];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = arr[i];
	}
	tmp[size] = e;

	delete[] arr;
	arr = tmp;
	size++;
}


void ArrDiagnostico::imprimirTodos()
{
	for (int i = 0; i < size; i++)
	{
		cout << "\n=====Datos del Diagnostico " << i + 1 << "=====" << endl;
		arr[i]->imprimir();
		cout << endl;
	}
}
