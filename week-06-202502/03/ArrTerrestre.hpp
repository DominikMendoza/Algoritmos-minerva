#pragma once
#include "Terrestre.hpp"

class ArrTerrestre
{
private:
	Terrestre** arr;
	int size;
public:
	ArrTerrestre();
	~ArrTerrestre();
	void agregar(Terrestre* e);
	Terrestre* getElement(int pos);
	int getSize();
	void animarTodos();
};

ArrTerrestre::ArrTerrestre()
{
	arr = nullptr;
	size = 0;
}

ArrTerrestre::~ArrTerrestre()
{
}

void ArrTerrestre::agregar(Terrestre* e)
{
	Terrestre** tmp = new Terrestre * [size + 1];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = arr[i];
	}

	tmp[size] = e;

	delete[] arr;
	arr = tmp;
	size++;
}

Terrestre* ArrTerrestre::getElement(int pos)
{
	return arr[pos];
}

int ArrTerrestre::getSize()
{
	return this->size;
}

void ArrTerrestre::animarTodos()
{
	for (int i = 0; i < size; i++)
	{
		arr[i]->animar();
	}
}

