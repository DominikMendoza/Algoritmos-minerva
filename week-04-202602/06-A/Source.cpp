#include "ArrDiagnostico.hpp"

short menu() {
	short opc;
	do
	{
		system("cls");
		cout << "1. Agregar animal\n";
		cout << "2. Agregar personal\n";
		cout << "3. Realizar diagnostico\n";
		cout << "4. Mostrar reporte de diagnosticos\n";
		cout << "5. Salir\n";
		cout << "Ingrese opcion: "; cin >> opc;
	} while (opc < 1 || opc > 5);
	
	return opc;
}
int main()
{
	ArrDiagnostico* arr = new ArrDiagnostico();
	Personal* personal = nullptr;
	Animal* animal = nullptr;

	short opc;
	do
	{
		opc = menu();
		switch (opc) {
		case 1: animal = new Animal(); break;
		case 2: personal = new Personal(); break;
		case 3: {
			if (animal == nullptr || personal == nullptr) {
				cout << "Falta ingresar un animal o el personal!\n";
			}
			else {
				arr->agregar(new Diagnostico(personal, animal));
				personal = nullptr;
				animal = nullptr;
			}
			break;
		}
		case 4: arr->imprimirTodos(); break;
		}
		system("pause");
	} while (opc != 5);

	system("pause");
	return 0;
}