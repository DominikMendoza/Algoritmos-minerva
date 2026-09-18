#include "ArrCarro.hpp"

int main()
{
	srand(time(nullptr));
	Console::CursorVisible = false;
	Console::SetWindowSize(WIDTH, HEIGHT);

	ArrCarro* arr = new ArrCarro();
	arr->agregar(new Carro(0, 5, 9));
	arr->agregar(new Carro(0, 15, 12));
	arr->agregar(new Carro(0, 25, 14));
	while (true)
	{
		arr->animarTodos();
		_sleep(120);
	}
	
	system("pause>0");
	return 0;
}