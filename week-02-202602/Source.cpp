#include "Cuenta.hpp"
#include "Estudiante.hpp"
#include "Persona.hpp"

void ejercicio_1() {
	Estudiante* est = new Estudiante();
	double promedioDeNotas = est->obtenerPromedio();
	cout << "El promedio de notas: " << promedioDeNotas << "\n";

	if (promedioDeNotas >= 13) {
		cout << "Aprobado!";
	}
	else {
		cout << "Desaprobado :c";
	}
	cout << endl;
}

void mensajeSegunIMC(int IMC) {
	switch (IMC)
	{
	case -1: cout << "esta por debajo de su peso ideal\n"; break;
	case 0: cout << "esta en su peso ideal\n"; break;
	case 1: cout << "esta con sobrepeso\n"; break;
	}
}

void presentacionPersona(int numero) {
	cout << "Persona " << numero << ": ";
}

void ejercicio_4() {
	string nombre;
	int edad;
	char sexo;
	float peso, altura;
	cout << "Ingrese nombre: "; cin >> nombre;
	cout << "Ingrese edad: "; cin >> edad;
	cout << "Ingrese sexo: "; cin >> sexo;
	cout << "Ingrese peso: "; cin >> peso;
	cout << "Ingrese altura: "; cin >> altura;

	Persona* per1 = new Persona(nombre, edad, sexo, peso, altura);
	Persona* per2 = new Persona(nombre, edad, sexo);
	Persona* per3 = new Persona();

	// Mostrar info de IMC
	cout << "\n----Informacion de IMC----\n";
	presentacionPersona(1);
	mensajeSegunIMC(per1->IMC());
	presentacionPersona(2);
	mensajeSegunIMC(per2->IMC());
	presentacionPersona(3);
	mensajeSegunIMC(per3->IMC());

	// Informacion sobre mayoria de edad
	cout << "\n----Informacion sobre mayoria de edad----\n";
	presentacionPersona(1);
	cout << (per1->esMayorDeEdad() ? "es mayor de edad" : "es menor de edad") << "\n";
	presentacionPersona(2);
	cout << (per2->esMayorDeEdad() ? "es mayor de edad" : "es menor de edad") << "\n";
	presentacionPersona(3);
	cout << (per3->esMayorDeEdad() ? "es mayor de edad" : "es menor de edad") << "\n";

	// Mostrar info general de cada objeto
	cout << "\n----Informacion general de las personas----\n";
	presentacionPersona(1);
	cout << per1->toString();
	presentacionPersona(2);
	cout << per2->toString();
	presentacionPersona(3);
	cout << per3->toString();

}

void ejercicio_5() {
	string nombre;
	cout << "Ingrese nombre del titular: ";
	cin >> nombre;

	Cuenta* cuenta = new Cuenta(nombre);

	cuenta->ingresar(8.9);
	cuenta->retirar(11);
	cuenta->ingresar(-4);
	cuenta->ingresar(9);
	cuenta->retirar(5);

	cuenta->mostrarSaldo();
}
int main() {
	srand(time(nullptr));
	ejercicio_4();
	return 0;
}