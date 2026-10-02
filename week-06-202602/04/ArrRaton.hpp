#pragma once
#include "Raton.hpp"

class ArrRaton
{
private:
	Raton** arr;
	int size;
public:
	ArrRaton();
	~ArrRaton();
	void agregar(Raton* r);
	void borrar(int pos);
	void animarTodos();
	void borrarTodos();
	void moverTodos();
	void dibujarTodos();
	Raton* getRaton(int pos);
	int getSize();
};

ArrRaton::ArrRaton()
{
	arr = nullptr;
	size = 0;
}

ArrRaton::~ArrRaton()
{
}

void ArrRaton::agregar(Raton* r)
{
	Raton** tmp = new Raton * [size + 1];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = arr[i];
	}
	tmp[size] = r;

	delete[] arr;
	arr = tmp;
	size++;
}

void ArrRaton::borrar(int pos)
{
	if (pos < 0 || pos >= size) {
		cout << "Fuera de rango...";
		return;
	}
	Raton** tmp = new Raton * [size - 1];
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (i != pos) {
			tmp[j] = arr[i];
			j++;
		}
		/*
		if (pos < i) {
			tmp[i] = arr[i];
		}
		if (pos > i) {
			tmp[i - 1] = arr[i];
		}*/
	}

	delete[] arr;
	arr = tmp;
	size--;
}

void ArrRaton::animarTodos()
{
	for (int i = 0; i < size; i++)
	{
		arr[i]->animar();
	}
}

void ArrRaton::borrarTodos()
{
	for (int i = 0; i < size; i++)
	{
		arr[i]->borrar();
	}
}

void ArrRaton::moverTodos()
{
	for (int i = 0; i < size; i++)
	{
		arr[i]->mover();
	}
}

void ArrRaton::dibujarTodos()
{
	for (int i = 0; i < size; i++)
	{
		arr[i]->dibujar();
	}
}

Raton* ArrRaton::getRaton(int pos)
{
	return arr[pos];
}

int ArrRaton::getSize()
{
	return this->size;
}
