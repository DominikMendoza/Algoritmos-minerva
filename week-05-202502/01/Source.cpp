#include "Smartphone.hpp"
#include "Laptop.hpp"

int main()
{
	Smartphone* cel = new Smartphone(3, true, "S", "25", 2300);
	Laptop* lap = new Laptop(16, 2000, "HP", "X", 2000);



	cel->mostrarDatos();
	lap->mostrarDatos();
	system("pause>0");
	return 0;
}