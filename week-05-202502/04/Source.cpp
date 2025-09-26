#include "ArrPracticante.hpp"

int main()
{
	srand(time(nullptr));
	ArrPracticante* arr = new ArrPracticante();

	for (int i = 0; i < 6; i++)
	{
		arr->agregar(new Practicante());
	}

	arr->imprimirTodos();

	string empresa;
	cout << "Ingrese nombre de la empresa: ";
	cin >> empresa;
	arr->imprimirUniversidadConMayorNumeroDeEstudiantes(empresa);
	system("pause>0");
	return 0;
}