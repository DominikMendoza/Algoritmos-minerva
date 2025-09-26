#include "ArrInsecto.hpp"
#include "Mariposa.hpp"
#include "Escarabajo.hpp"

int main()
{
	Insecto* es = new Escarabajo("F", false, "Escarabajus", 6, "Verde");
	Insecto* mp = new Mariposa(15.4, "Flores", "Maripousussusus", 6, "Amarillo");

	ArrInsecto* arr = new ArrInsecto();

	for (int i = 0; i < rand() % 3 + 1; i++)
	{
		arr->agregar(new Escarabajo("F", (i % 2 == 0), "Escarabajus", i, "Verde"));
	}
	for (int i = 0; i < rand() % 3 + 2; i++)
	{
		arr->agregar(new Mariposa(8.53 + i, "Flores", "Maripousussusus", i, "Amarillo"));
	}

	arr->mostrarInfoDeTodos();
	system("pause>0");
	return 0;
}