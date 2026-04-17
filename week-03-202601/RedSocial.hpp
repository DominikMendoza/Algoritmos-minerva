#pragma once
#include "ArrContacto.hpp"

class RedSocial
{
private:
	ArrContacto* contactos;
public:
	RedSocial();
	~RedSocial();
	void registrarContacto();
	void modificarDatosContacto();
	void eliminarContacto();
	void reporteCumplenAniosEnMayo();
	void reporteSonVarones();
	void reporteFacebookYWhatsApp();
	void listarTodosLosContactos();
};

RedSocial::RedSocial()
{
	contactos = new ArrContacto();
}

RedSocial::~RedSocial()
{
	delete contactos;
}

void RedSocial::registrarContacto()
{
	cout << "Registrando nuevo contacto...\n";
	Contacto* c = new Contacto();
	c->leerDatos();
	contactos->agregar(c);
	cout << "Contacto registrado exitosamente... :D\n\n";
}

void RedSocial::modificarDatosContacto()
{
	int pos;
	cout << "Ingrese posicion de contacto a modificar: ";
	cin >> pos;
	
	contactos->modificar(pos);
}

void RedSocial::eliminarContacto()
{
	int pos;
	cout << "Ingrese posicion de contacto a eliminar: ";
	cin >> pos;

	contactos->eliminar(pos);
}

void RedSocial::reporteCumplenAniosEnMayo()
{
	int cnt = 0;
	for (int i = 0; i < contactos->getSize(); i++)
	{
		// El mes mayo es el mes 5
		if (contactos->get(i)->getMesDeCumpleanos() == 5) {
			cnt++;
		}
	}
	cout << "El numero de contactos que cumplen anios en mayo es: " << cnt << "\n\n";
}

void RedSocial::reporteSonVarones()
{
	int cnt = 0;
	for (int i = 0; i < contactos->getSize(); i++)
	{
		if (contactos->get(i)->getSexo() == 'V') {
			cnt++;
		}
	}
	cout << "El numero de contactos varones es : " << cnt << "\n\n";
}

void RedSocial::reporteFacebookYWhatsApp()
{
	int cnt = 0;
	for (int i = 0; i < contactos->getSize(); i++)
	{
		if (contactos->get(i)->getRedSocial() == "Facebook" ||
			contactos->get(i)->getRedSocial() == "WhatsApp") {
			cnt++;
		}
	}
	cout << "El numero de contactos que usan Facebook o WhatsApp es : " << cnt << "\n\n";
}

void RedSocial::listarTodosLosContactos()
{
	contactos->imprimirTodos();
}
