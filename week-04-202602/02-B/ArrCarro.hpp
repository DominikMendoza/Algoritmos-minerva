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
	void agregar(Carro* e);
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

void ArrCarro::agregar(Carro* e)
{
	Carro** tmp = new Carro * [size + 1];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = arr[i];
	}
	tmp[size] = e;

	delete[] arr;
	arr = tmp;
	size++;
}


void ArrCarro::animarTodos()
{
	for (int i = 0; i < size; i++)
	{
		arr[i]->animar();
	}
}
