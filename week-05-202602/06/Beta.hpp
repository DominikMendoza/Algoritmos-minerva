#pragma once
#include "Nave.hpp"

class Beta : public Nave
{
public:
	Beta(int x, int y);
	~Beta();
private:
	void dibujar() override;
};

Beta::Beta(int x, int y) : Nave(x, y)
{
	this->ancho = 10;
	this->alto = 3;
	this->color = 9;
}

Beta::~Beta()
{
}

void Beta::dibujar()
{
	Console::ForegroundColor = ConsoleColor(color);
	Console::SetCursorPosition(x, y);
	cout << "   .--.";
	Console::SetCursorPosition(x, y + 1);
	cout << " _/ ~0_\\_";
	Console::SetCursorPosition(x, y + 2);
	cout << "(________)";
}