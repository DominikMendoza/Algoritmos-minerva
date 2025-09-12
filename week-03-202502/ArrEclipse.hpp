#pragma once
#include "Eclipse.hpp"

class ArrEclipse
{
private:
	Eclipse** arr;
	int size;
public:
	ArrEclipse();
	~ArrEclipse();
	void add(Eclipse* e);
	void removeLast();
	void printAllElements();
	void removeInPos(int pos);
	void modify(int pos);
	void eclipsesQueOcasionaronSismos();
	void eclipsesQueSeProdujeronDeNoche();
};

ArrEclipse::ArrEclipse()
{
	arr = nullptr;
	size = 0;
}

ArrEclipse::~ArrEclipse()
{
}

void ArrEclipse::add(Eclipse* e)
{
	Eclipse** tmp = new Eclipse * [size + 1];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = arr[i];
	}
	
	tmp[size] = e;

	delete[] arr;
	arr = tmp;
	size++;
}

void ArrEclipse::removeLast()
{
	Eclipse** tmp = new Eclipse * [size - 1];
	for (int i = 0; i < size - 1; i++)
	{
		tmp[i] = arr[i];
	}

	delete[] arr;
	arr = tmp;
	size--;
}

void ArrEclipse::printAllElements()
{
	for (int i = 0; i < size; i++)
	{
		arr[i]->imprimir();
	}
}

void ArrEclipse::removeInPos(int pos)
{
	if (pos < 0 || pos >= size) {
		cout << "La posicion ingresada esta fuera de rango...\n";
		return;
	}

	Eclipse** tmp = new Eclipse * [size - 1];
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

void ArrEclipse::modify(int pos)
{
	if (pos < 0 || pos >= size) {
		cout << "La posicion ingresada esta fuera de rango...\n";
		return;
	}

	arr[pos]->readData();
}

void ArrEclipse::eclipsesQueOcasionaronSismos()
{
	cout << "Eclipses que ocasionaron sismos:\n";
	for (int i = 0; i < size; i++)
	{
		if (arr[i]->provocoSismos()) {
			arr[i]->imprimir();
		}
	}
}

void ArrEclipse::eclipsesQueSeProdujeronDeNoche()
{
	cout << "Eclipses que se produjeron durante la noche:\n";
	for (int i = 0; i < size; i++)
	{
		if (arr[i]->fueNocturno()) {
			arr[i]->imprimir();
		}
	}
}
