#pragma once
#include "Nave.hpp"

class Alfa : public Nave
{
public:
	Alfa(int x, int y);
	~Alfa();
private:
	void dibujar() override;
};

Alfa::Alfa(int x, int y) : Nave(x, y)
{
	this->ancho = 13;
	this->alto = 5;
	this->color = 14;
}

Alfa::~Alfa()
{
}

void Alfa::dibujar()
{
	Console::ForegroundColor = ConsoleColor(color);
	Console::SetCursorPosition(x, y);
	cout << "    _.-._";
	Console::SetCursorPosition(x, y + 1);
	cout << "    .' '.";
	Console::SetCursorPosition(x, y + 2);
	cout << "_.-~=====~-._";
	Console::SetCursorPosition(x, y + 3);
	cout << "(___________)";
	Console::SetCursorPosition(x, y + 4);
	cout << "   \\_____/";
}