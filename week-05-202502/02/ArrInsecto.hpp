#pragma once
#include "Insecto.hpp"

class ArrInsecto
{
private:
	Insecto** arr;
	int size;
public:
	ArrInsecto();
	~ArrInsecto();
	void agregar(Insecto* e);
	int getSize();
	Insecto* getElemento(int pos);
	void mostrarInfoDeTodos();
};

ArrInsecto::ArrInsecto()
{
	arr = nullptr;
	size = 0;
}

ArrInsecto::~ArrInsecto()
{
}

void ArrInsecto::agregar(Insecto* e)
{
	Insecto** tmp = new Insecto * [size + 1];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = arr[i];
	}

	tmp[size] = e;

	delete[] arr;
	arr = tmp;
	size++;
}

int ArrInsecto::getSize()
{
	return this->size;
}

Insecto* ArrInsecto::getElemento(int pos)
{
	return arr[pos];
}

void ArrInsecto::mostrarInfoDeTodos()
{
	for (int i = 0; i < size; i++)
	{
		arr[i]->mostrarInfo();
	}
}
