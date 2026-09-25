#pragma once
#include <conio.h>
#include "Alfa.hpp"
#include "ArrNave.hpp"
#include "Beta.hpp"
#include "Gamma.hpp"

class Controller
{
private:
	ArrNave* arr;
	int alfaCount, betaCount;
public:
	Controller();
	~Controller();
	void evaluarNaves();
	void iniciarJuego();
	void jugar();
	void culminarJuego();
	void mostrarNaves();
};

Controller::Controller()
{
	arr = new ArrNave();
	alfaCount = betaCount = 0;
}

Controller::~Controller()
{
}

void Controller::evaluarNaves()
{
	if (_kbhit()) {
		char tecla = _getch();
		tecla = toupper(tecla);
		if (tecla == 'A') {
			arr->agregar(new Alfa(0, 0));
			alfaCount++;
		}
	}

	if (alfaCount == 2) {
		arr->agregar(new Beta(WIDTH / 2, 0));
		betaCount++;
		alfaCount = 0;
	}

	if (betaCount == 2) {
		arr->agregar(new Gamma(WIDTH - 21, 0));
		betaCount = 0;
	}
}

void Controller::iniciarJuego()
{
	Console::ForegroundColor = ConsoleColor::Green;
	Console::SetCursorPosition((WIDTH - 38)/ 2, HEIGHT / 2);
	cout << "Presione 'A' para agregar una nave...";
	_getch();
	Console::ResetColor();
	Console::Clear();
}

void Controller::jugar()
{
	iniciarJuego();
	do {
		evaluarNaves();
		arr->animarTodos();
		mostrarNaves();
		_sleep(120);
	} while (arr->getSize() < 20);
	culminarJuego();
}

void Controller::culminarJuego()
{
	Console::Clear();
	Console::ForegroundColor = ConsoleColor::Red;
	Console::SetCursorPosition((WIDTH - 24)/ 2, HEIGHT / 2);
	cout << "Hemos sido invadidos...";
}

void Controller::mostrarNaves()
{
	Console::ForegroundColor = ConsoleColor::White;
	Console::SetCursorPosition(WIDTH - 10, 0);
	cout << "         ";
	Console::SetCursorPosition(WIDTH - 10, 0);
	cout << "Naves: " << arr->getSize();
}
