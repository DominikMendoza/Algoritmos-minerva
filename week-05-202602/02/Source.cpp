#include "Escarabajo.hpp"
#include "Mariposa.hpp"

int main() {
	/*Escarabajo* esc = new Escarabajo();
	Mariposa* mariposa = new Mariposa();*/

	Insecto* esc = new Escarabajo();
	Insecto* mariposa = new Mariposa();
	Insecto* base = new Insecto();
	esc->imprimir();
	mariposa->imprimir();
	base->imprimir();
	system("pause>0");
	return 0;
}