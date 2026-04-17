#include "RedSocial.hpp"

int menu() {
	short opc;
	do
	{
		system("cls");
		cout << "1. Registrar contacto\n";
		cout << "2. Modificar datos de contacto\n";
		cout << "3. Eliminar contacto\n";
		cout << "4. Listar todos los contactos\n";
		cout << "5. Reporte de contactos que cumplen anios en Mayo\n";
		cout << "6. Reporte de contactos que son Varones\n";
		cout << "7. Reporte de contactos que usar como RS Facebook o WhatsApp\n";
		cout << "8. Salir";
		cout << "\nIngrese opcion...: "; cin >> opc;
		system("cls");
	} while (opc < 0 || opc > 8);
	return opc;
}
int main()
{
	srand(time(nullptr));
	
	RedSocial* rs = new RedSocial();
	short opc;
	do
	{
		opc = menu();
		switch (opc)
		{
		case 1: rs->registrarContacto(); break;
		case 2: rs->modificarDatosContacto(); break;
		case 3: rs->eliminarContacto(); break;
		case 4: rs->listarTodosLosContactos(); break;
		case 5: rs->reporteCumplenAniosEnMayo(); break;
		case 6: rs->reporteSonVarones(); break;
		case 7: rs->reporteFacebookYWhatsApp(); break;
		}
		system("pause");
	} while (opc != 8);

	delete rs;

	return 0;
}