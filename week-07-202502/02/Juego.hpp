#pragma once
#include <conio.h>
#include "ArrObjeto.hpp"
#include "AveDodo.hpp"
#include "NaveTerricola.hpp"
#include "ParticulaMarciana.hpp"
#include "VidaVegetal.hpp"

class Juego
{
private:
	NaveTerricola* nt;
	ArrObjeto* aves;
	ArrObjeto* vidasVegetales;
	ArrObjeto* particulas;

	int o2Recolectado;
	int vidaVegetalRecolectada;
	int vidaAnimalRecolectada;
	
	void recolectarMuestrasYAumentarContador(ArrObjeto* arr, int& contador);
public:
	Juego();
	~Juego();

	void jugar();
	void verificarColisiones();
	void mostrarContadores();
};

void Juego::recolectarMuestrasYAumentarContador(ArrObjeto* arr, int& contador)
{
	for (int i = 0; i < arr->getSize(); i++)
	{
		if (!arr->get(i)->fueColisionado() && arr->get(i)->estaColisionando(nt)) {
			arr->get(i)->marcarComoColisionado();
			contador++;
		}
	}
}

Juego::Juego()
{
	nt = new NaveTerricola();
	aves = new ArrObjeto();
	vidasVegetales = new ArrObjeto();
	particulas = new ArrObjeto();
	o2Recolectado = 0;
	vidaVegetalRecolectada = 0;
	vidaAnimalRecolectada = 0;

	for (int i = 0; i < 2; i++)
	{
		aves->agregar(new AveDodo(i * 25, i * 10, 1));
	}
	for (int i = 0; i < 2; i++)
	{
		vidasVegetales->agregar(new VidaVegetal(rand() % (WIDTH - 10), rand() % (HEIGHT - 10)));
	}
	for (int i = 0; i < 6; i++)
	{
		particulas->agregar(new ParticulaMarciana(rand() % (WIDTH - 10), rand() % (HEIGHT - 10)));
	}
}

Juego::~Juego()
{
}

void Juego::jugar()
{
	while (true)
	{
		nt->borrar();
		if (_kbhit()) {
			char tecla = toupper(_getch());
			nt->mover(tecla);
		}

		verificarColisiones();
		

		nt->dibujar();
		aves->animarTodos();
		vidasVegetales->animarTodos();
		particulas->animarTodos();

		mostrarContadores();
		_sleep(90);
	}
}

void Juego::verificarColisiones()
{
	for (int i = 0; i < particulas->getSize(); i++)
	{
		if (particulas->get(i)->estaColisionando(nt)) {
			particulas->eliminar(i);
			i--;
			o2Recolectado++;
		}
	}

	recolectarMuestrasYAumentarContador(vidasVegetales, vidaVegetalRecolectada);
	recolectarMuestrasYAumentarContador(aves, vidaAnimalRecolectada);
}

void Juego::mostrarContadores()
{
	Console::SetCursorPosition(WIDTH / 2 - 10, 3);
	cout << "Particulas marcianas O2: " << o2Recolectado << "/6";
	Console::SetCursorPosition(WIDTH / 2 - 10, 2);
	cout << "Vida vegetal recolectada: " << vidaVegetalRecolectada << "/2";
	Console::SetCursorPosition(WIDTH / 2 - 10, 1);
	cout << "Vida animal recolectada: " << vidaAnimalRecolectada << "/2";
}
