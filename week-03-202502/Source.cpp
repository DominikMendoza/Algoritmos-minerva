#include "ArrEclipse.hpp"

int menu() {
	int opc;
	do
	{
		cout << "1. Registro de elementos\n";
		cout << "2. Modificar elemento\n";
		cout << "3. Eliminar elemento\n";
		cout << "4. Reporte de eclipses que ocasionaron sismos\n";
		cout << "5. Reporte de eclipses que se produjeron de noche\n";
		cout << "6. Mostrar todos los elementos\n";
		cout << "7. Salir\n";
		cout << "Ingrese su opcion: "; cin >> opc;
		system("cls");
	} while (opc < 1 || opc > 7);
	return opc;
}

int main()
{
	srand(time(nullptr));
	ArrEclipse* arr = new ArrEclipse();
	int opc = menu();
	while (opc != 7) {
		switch (opc)
		{
		case 1: arr->add(new Eclipse()); break;
		case 2: {
			int pos;
			cout << "Ingrese posicion: ";
			cin >> pos;
			arr->modify(pos);
			break;
		}
		case 3: {
			int pos;
			cout << "Ingrese posicion: ";
			cin >> pos;
			arr->removeInPos(pos);
			break;
		}
		case 4: arr->eclipsesQueOcasionaronSismos(); break;
		case 5: arr->eclipsesQueSeProdujeronDeNoche(); break;
		case 6: arr->printAllElements(); break;
		default:
			break;
		}
		system("pause");
		system("cls");
		opc = menu();
	}
	system("pause>0");
	return 0;
}