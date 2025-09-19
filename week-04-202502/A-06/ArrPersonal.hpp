#pragma once
#include "Personal.hpp"

class ArrPersonal
{
private:
	Personal** arr;
	int size;
public:
	ArrPersonal();
	~ArrPersonal();
	void agregar();
	int getSize();
	Personal* getElemento(int pos);
};

ArrPersonal::ArrPersonal()
{
	arr = nullptr;
	size = 0;
}

ArrPersonal::~ArrPersonal()
{
}

void ArrPersonal::agregar()
{
	Personal** tmp = new Personal * [size + 1];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = arr[i];
	}

	Personal* diag = new Personal();
	tmp[size] = diag;

	delete[] arr;
	arr = tmp;
	size++;
}

int ArrPersonal::getSize()
{
	return this->size;
}

Personal* ArrPersonal::getElemento(int pos)
{
	return arr[pos];
}
