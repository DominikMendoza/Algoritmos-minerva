#pragma once
#include "ArrCarro.hpp"

class Carrera
{
private:
	ArrCarro* carros;
	int metaPos;
public:
	Carrera(int metaPos);
	~Carrera();
	void dibujarMeta();
	void iniciarCarrera();
};

Carrera::Carrera(int metaPos)
{
	carros = new ArrCarro();
	this->metaPos = metaPos;
	for (int i = 1; i <= 5; i++)
	{
		carros->agregar(i * 7 - 4);
	}
}

Carrera::~Carrera()
{
}

void Carrera::dibujarMeta()
{
	for (int i = 0; i < HEIGHT; i++)
	{
		Console::ForegroundColor = ConsoleColor::Yellow;
		Console::SetCursorPosition(metaPos, i);
		cout << char(219);
	}
}

void Carrera::iniciarCarrera()
{
	while (true)
	{
		carros->animarTodos();
		dibujarMeta();
		_sleep(120);
	}
}
