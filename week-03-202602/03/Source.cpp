#include "ArrEclipse.hpp"

int menu() {
	int opcion = 0;

	do {
		system("cls");
		cout << "=========================================\n";
		cout << "          GESTION DE ECLIPSES            \n";
		cout << "=========================================\n";
		cout << "1. Agregar nuevo eclipse (por defecto)\n";
		cout << "2. Agregar eclipse custom\n";
		cout << "3. Modificar datos de un eclipse\n";
		cout << "4. Eliminar un eclipse\n";
		cout << "5. Imprimir todos los eclipses\n";
		cout << "6. Reporte: Eclipses visibles en Europa\n";
		cout << "7. Reporte: Eclipses con sismos\n";
		cout << "8. Reporte: Eclipses nocturnos\n";
		cout << "9. Salir\n";
		cout << "-----------------------------------------\n";
		cout << "Seleccione una opcion (1-9): ";

		cin >> opcion;
	} while (opcion < 1 || opcion > 9);
	return opcion;
}

int main()
{
	srand(time(nullptr));

	ArrEclipse* gestionEclipses = new ArrEclipse();
	int opcion = 0;
	int pos;

	do {
		opcion = menu();

		switch (opcion) {
		case 1: {
			system("cls");
			Eclipse* nuevo = new Eclipse();
			gestionEclipses->agregar(nuevo);
			cout << "\nEclipse por defecto registrado exitosamente.\n";
			system("pause");
			break;
		}
		case 2: {
			system("cls");
			cout << "--- REGISTRAR NUEVO ECLIPSE ---\n";
			Eclipse* nuevo = new Eclipse();
			nuevo->leerDatos();
			gestionEclipses->agregar(nuevo);
			cout << "\nEclipse registrado exitosamente.\n";
			system("pause");
			break;
		}
		case 3: {
			system("cls");
			cout << "--- MODIFICAR ECLIPSE ---\n";
			cout << "Ingrese la posicion del eclipse (ej: 0, 1, 2...): ";
			cin >> pos;
			gestionEclipses->modificarDatos(pos);
			system("pause");
			break;
		}
		case 4: {
			system("cls");
			cout << "--- ELIMINAR ECLIPSE ---\n";
			cout << "Ingrese la posicion del eclipse a eliminar: ";
			cin >> pos;
			gestionEclipses->eliminarElemento(pos);
			system("pause");
			break;
		}
		case 5: {
			system("cls");
			cout << "--- LISTA COMPLETA DE ECLIPSES ---\n";
			gestionEclipses->imprimirTodos();
			system("pause");
			break;
		}
		case 6: {
			system("cls");
			gestionEclipses->reporteDeEclipsesVisiblesEnEuropa();
			system("pause");
			break;
		}
		case 7: {
			system("cls");
			gestionEclipses->reporteDeEclipsesSismos();
			system("pause");
			break;
		}
		case 8: {
			system("cls");
			gestionEclipses->reporteDeEclipsesNocturnos();
			system("pause");
			break;
		}
		}

	} while (opcion != 9);

	delete gestionEclipses;
	return 0;
}