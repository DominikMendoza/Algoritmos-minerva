#include "ArrAvion.hpp"
using namespace std;

int main()
{
	srand(time(nullptr));
	Console::SetWindowSize(WIDTH, HEIGHT);
	Console::CursorVisible = false;
	int const anchoavion = 10;
	int n;
	do
	{
		cout << "Ingrese numero de aviones [2, 5]: ";
		cin >> n;
		system("cls");
		cout << "Numero invalido, solo valores entre 2 y 5 (inclusive)\n";
	} while (n < 2 || n > 5);
	
	system("cls");

	ArrAvion* arr = new ArrAvion();
	for (int i = 0; i < n; i++)
	{
		int coordX = anchoavion * i + 5 * i;
		arr->agregar(new Avion(coordX, 0));
	}

	while (true)
	{
		arr->animarTodos();
		_sleep(90);
	}

	delete arr;
	return 0;
}