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
	void agregar(Objeto* e);
	void eliminar(int pos);
	Objeto* get(int pos);
	int getSize();
	void animarTodos();
};

ArrObjeto::ArrObjeto()
{
	arr = nullptr;
	size = 0;
}

ArrObjeto::~ArrObjeto()
{
}

void ArrObjeto::agregar(Objeto* e)
{
	Objeto** tmp = new Objeto * [size + 1];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = arr[i];
	}

	tmp[size] = e;

	delete[] arr;
	arr = tmp;
	size++;
}

void ArrObjeto::eliminar(int pos)
{
	Objeto** tmp = new Objeto * [size - 1];
	for (int j = 0, i = 0; i < size; i++)
	{
		if (i != pos) {
			tmp[j++] = arr[i];
		}
	}

	delete[] arr;
	arr = tmp;
	size--;
}

Objeto* ArrObjeto::get(int pos)
{
	return arr[pos];
}

int ArrObjeto::getSize()
{
	return this->size;
}

void ArrObjeto::animarTodos()
{
	for (int i = 0; i < size; i++)
	{
		arr[i]->animar();
	}
}
