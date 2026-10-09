#pragma once
#include "Objeto.hpp"

class ArrObjeto
{
private:
	Objeto** arr;
	int size;
public:
	ArrObjeto();
	~ArrObjeto();
	void agregar(Objeto* obj);
	void eliminar(int pos);
	int getSize();
	Objeto* getObjeto(int pos);
	void animarTodos();
};

ArrObjeto::ArrObjeto()
{
	arr = nullptr;
	size = 0;
}

ArrObjeto::~ArrObjeto()
{
	for (int i = 0; i < size; i++)
	{
		delete arr[i];
	}
	delete[] arr;
}

void ArrObjeto::agregar(Objeto* obj)
{
	Objeto** tmp = new Objeto * [size + 1];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = arr[i];
	}
	tmp[size] = obj;

	delete[] arr;
	arr = tmp;
	size++;
}

void ArrObjeto::eliminar(int pos)
{
	if (pos < 0 || pos >= size) return;

	Objeto** tmp = new Objeto * [size + 1];
	for (int i = 0; i < size; i++)
	{
		if (i < pos)
			tmp[i] = arr[i];
		if (i > pos)
			tmp[i - 1] = arr[i];
	}

	delete[] arr;
	arr = tmp;
	size--;
}

int ArrObjeto::getSize()
{
	return this->size;
}

Objeto* ArrObjeto::getObjeto(int pos)
{
	return arr[pos];
}

void ArrObjeto::animarTodos()
{
	for (int i = 0; i < size; i++)
	{
		arr[i]->animar();
	}
}
