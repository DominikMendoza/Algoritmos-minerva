#pragma once
#include "Movil.hpp"

class ArrMovil
{
private:
	Movil** arr;
	int size;
public:
	ArrMovil();
	~ArrMovil();
	void agregar(Movil* e);
	void eliminar(int pos);
	void animarTodos();
	int getSize();
	Movil* getMovil(int pos);
};

ArrMovil::ArrMovil()
{
	arr = nullptr;
	size = 0;
}

ArrMovil::~ArrMovil()
{
	for (int i = 0; i < size; i++)
	{
		delete arr[i];
	}
	delete[] arr;
}

void ArrMovil::agregar(Movil* e)
{
	Movil** tmp = new Movil * [size + 1];

	for (int i = 0; i < size; i++)
	{
		tmp[i] = arr[i];
	}
	tmp[size] = e;

	delete[] arr;

	arr = tmp;
	size++;
}

void ArrMovil::eliminar(int pos)
{
	Movil** tmp = new Movil * [size - 1];

	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (i != pos) {
			tmp[j] = arr[i];
			j++;
		}
	}

	delete[] arr;

	arr = tmp;
	size--;
}

void ArrMovil::animarTodos()
{
	for (int i = 0; i < size; i++)
	{
		arr[i]->animar();
	}
}

int ArrMovil::getSize()
{
	return this->size;
}

Movil* ArrMovil::getMovil(int pos)
{
	return arr[pos];
}
