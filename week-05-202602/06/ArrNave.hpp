#pragma once
#include "Nave.hpp"

class ArrNave
{
private:
	Nave** arr;
	int size;
public:
	ArrNave();
	~ArrNave();
	void agregar(Nave* nave);
	void animarTodos();

	int getSize();
};

ArrNave::ArrNave()
{
	arr = nullptr;
	size = 0;
}

ArrNave::~ArrNave()
{
}

void ArrNave::agregar(Nave* nave)
{
	Nave** tmp = new Nave * [size + 1];

	for (int i = 0; i < size; i++)
	{
		tmp[i] = arr[i];
	}
	tmp[size] = nave;

	delete[] arr;
	arr = tmp;
	size++;
}

void ArrNave::animarTodos()
{
	for (int i = 0; i < size; i++)
	{
		arr[i]->animar();
	}
}

int ArrNave::getSize()
{
	return this->size;
}
