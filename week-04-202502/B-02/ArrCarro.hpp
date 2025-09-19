#pragma once
#include "Carro.hpp"

class ArrCarro
{
private:
	Carro** arr;
	int size;
public:
	ArrCarro();
	~ArrCarro();
	void agregar(int y);
	int getSize();
	Carro* getElemento(int pos);
	void animarTodos();
};

ArrCarro::ArrCarro()
{
	arr = nullptr;
	size = 0;
}

ArrCarro::~ArrCarro()
{
}

void ArrCarro::agregar(int y)
{
	Carro** tmp = new Carro * [size + 1];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = arr[i];
	}

	Carro* car = new Carro(y);
	tmp[size] = car;

	delete[] arr;
	arr = tmp;
	size++;
}

int ArrCarro::getSize()
{
	return this->size;
}

Carro* ArrCarro::getElemento(int pos)
{
	return arr[pos];
}

void ArrCarro::animarTodos()
{
	for (int i = 0; i < size; i++)
	{
		arr[i]->animar();
	}
}
