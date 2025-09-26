#pragma once
#include "Practicante.hpp"

class ArrPracticante
{
private:
	Practicante** arr;
	int size;
public:
	ArrPracticante();
	~ArrPracticante();
	void agregar(Practicante* e);
	int getSize();
	Practicante* getElemento(int pos);

	void imprimirTodos();

	void filtrarPorEmpresa(string nombreEmpresa);

	void imprimirUniversidadConMayorNumeroDeEstudiantes(string nombreEmpresa);
};

ArrPracticante::ArrPracticante()
{
	arr = nullptr;
	size = 0;
}

ArrPracticante::~ArrPracticante()
{
}

void ArrPracticante::agregar(Practicante* e)
{
	Practicante** tmp = new Practicante * [size + 1];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = arr[i];
	}

	tmp[size] = e;

	delete[] arr;
	arr = tmp;
	size++;
}

int ArrPracticante::getSize()
{
	return this->size;
}

Practicante* ArrPracticante::getElemento(int pos)
{
	return arr[pos];
}

void ArrPracticante::imprimirTodos()
{
	if (size <= 0) {
		cout << "No hay practicantes para mostrar" << endl;
		return;
	}

	for (int i = 0; i < size; i++)
	{
		cout << "Practicante " << i + 1 << endl;
		arr[i]->imprimir();
	}
}

void ArrPracticante::filtrarPorEmpresa(string nombreEmpresa)
{
	if (size <= 0) {
		cout << "No hay practicantes para mostrar" << endl;
		return;
	}
	cout << "Empleados de la empresa " << nombreEmpresa << endl;
	for (int i = 0; i < size; i++)
	{
		if (arr[i]->getNombreEmpresa() == nombreEmpresa) {
			arr[i]->imprimir();

		}
	}
	cout << "------------------------------------------------" << endl;
}

void ArrPracticante::imprimirUniversidadConMayorNumeroDeEstudiantes(string nombreEmpresa)
{
	if (size <= 0) {
		cout << "No hay practicantes para mostrar" << endl;
		return;
	}
	int uni1, uni2, uni3;
	uni1 = uni2 = uni3 = 0;
	for (int i = 0; i < size; i++)
	{
		// Son practicantes validos
		if (arr[i]->getNombreEmpresa() == nombreEmpresa) {
			if (arr[i]->getNombreUniversidad() == "Uni-1") {
				uni1++;
			}
			else if (arr[i]->getNombreUniversidad() == "Uni-2") {
				uni2++;
			} else  if (arr[i]->getNombreUniversidad() == "Uni-3") {
				uni3++;
			}
		}
	}

	cout << "La univerisidad con mayor numero de estudiantes para esa empresa es: ";
	if (uni1 >= uni2 && uni1 >= uni3) {
		cout << "Uni-1";
	}
	if (uni2 >= uni3 && uni2 >= uni1) {
		cout << "Uni-2";
	}
	if (uni3 >= uni2 && uni3 >= uni1) {
		cout << "Uni-3";
	}

	cout << "------------------------------------------------" << endl;
}
