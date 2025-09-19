#pragma once
#include "Animal.hpp"

class ArrAnimal
{
private:
	Animal** arr;
	int size;
public:
	ArrAnimal();
	~ArrAnimal();
	void agregar();
	int getSize();
	Animal* getElemento(int pos);
	void mostrarTodos();
};

ArrAnimal::ArrAnimal()
{
	arr = nullptr;
	size = 0;
}

ArrAnimal::~ArrAnimal()
{
}

void ArrAnimal::agregar()
{
	Animal** tmp = new Animal * [size + 1];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = arr[i];
	}

	Animal* diag = new Animal();
	tmp[size] = diag;

	delete[] arr;
	arr = tmp;
	size++;
}

int ArrAnimal::getSize()
{
	return this->size;
}

Animal* ArrAnimal::getElemento(int pos)
{
	return arr[pos];
}

void ArrAnimal::mostrarTodos()
{
	cout << "====================\n";
	cout << "Reporte de animales\n";
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << ") " << arr[i]->obtenerInfo();
	}
	cout << "====================\n";
}
