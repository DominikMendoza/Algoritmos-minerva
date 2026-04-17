#pragma once
#include "Contacto.hpp"

class ArrContacto
{
private:
	Contacto** arr;
	int size;
public:
	ArrContacto();
	~ArrContacto();
	void agregar(Contacto* contacto);
	void eliminar(int pos);
	void modificar(int pos);
	void imprimirTodos();
	Contacto* get(int pos);
	int getSize();
};

ArrContacto::ArrContacto()
{
	arr = nullptr;
	size = 0;
}

ArrContacto::~ArrContacto()
{
	for (int i = 0; i < size; i++)
	{
		delete arr[i];
	}
	delete[] arr;
}

void ArrContacto::agregar(Contacto* contacto)
{
	Contacto** tmp = new Contacto * [size + 1];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = arr[i];
	}

	tmp[size] = contacto;

	delete[] arr;
	arr = tmp;
	size++;
}

void ArrContacto::eliminar(int pos)
{
	if (pos < 0 || pos >= size) {
		cout << "Posicion " << pos << " a eliminar invalida\n";
		return;
	}

	Contacto** tmp = new Contacto * [size - 1];
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (i != pos) {
			tmp[j] = arr[i];
			j++;
		}
	}

	delete[] arr;
	arr = tmp;
	size--;
}

void ArrContacto::modificar(int pos)
{
	if (pos < 0 || pos >= size) {
		cout << "Posicion " << pos << " a modificar invalida\n";
		return;
	}

	arr[pos]->leerDatos();
}

void ArrContacto::imprimirTodos()
{
	for (int i = 0; i < size; i++)
	{
		arr[i]->imprimir();
	}
}

Contacto* ArrContacto::get(int pos)
{
	return this->arr[pos];
}

int ArrContacto::getSize()
{
	return this->size;
}
