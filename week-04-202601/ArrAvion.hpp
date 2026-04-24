#pragma once
#include "Avion.hpp"

class ArrAvion
{
private:
	Avion** arr;
	int size;
public:
	ArrAvion();
	~ArrAvion();
	void agregar(Avion* avion);
	void animarTodos();
};

ArrAvion::ArrAvion()
{
	arr = nullptr;
	size = 0;
}

ArrAvion::~ArrAvion()
{
	for (int i = 0; i < size; i++)
	{
		delete arr[i];
	}
	delete[] arr;
}

void ArrAvion::agregar(Avion* avion)
{
	Avion** tmp = new Avion * [size + 1];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = arr[i];
	}

	tmp[size] = avion;

	delete[] arr;
	arr = tmp;
	size++;
}

void ArrAvion::animarTodos()
{
	for (int i = 0; i < size; i++)
	{
		arr[i]->animar();
	}
}
