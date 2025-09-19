#include "ArrAnimal.hpp"
#include "ArrDiagnostico.hpp"
#include "ArrPersonal.hpp"

int menu() {
	int opc;
	do
	{
		system("cls");
		cout << "1. Insertar personal\n";
		cout << "2. Insertar animal\n";
		cout << "3. Realizar diagnostico\n";
		cout << "4. Reportes\n";
		cout << "5. Salir\n";
		cout << "Ingrese su opcion: ";
		cin >> opc;
	} while (opc < 1 || opc > 6);
	return opc;
}
int main()
{
	srand(time(nullptr));
	ArrAnimal* animales = new ArrAnimal();
	ArrPersonal* personal = new ArrPersonal();
	ArrDiagnostico* diagnosticos = new ArrDiagnostico();

	int opc = menu();
	while (opc != 5)
	{
		switch (opc)
		{
		case 1: personal->agregar(); break;
		case 2: animales->agregar(); break;
		case 3: {
			int posPersonal, posAnimal;
			cout << "Ingrese posicion del personal: "; cin >> posPersonal;
			cout << "Ingrese posicion del animal: "; cin >> posAnimal;
			diagnosticos->agregar(
				animales->getElemento(posAnimal),
				personal->getElemento(posPersonal)
			);
			break;
		}
		case 4: {
			diagnosticos->mostrarTodos();
			animales->mostrarTodos();
			break;
		}
		case 5: {
			system("pause>0");
			return 0;
			break;
		}
		}
		system("pause>0");
		opc = menu();
	}

	system("pause>0");
	return 0;
}