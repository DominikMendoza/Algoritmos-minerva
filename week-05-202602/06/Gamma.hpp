#pragma once
#include "Nave.hpp"

class Gamma : public Nave
{
public:
	Gamma(int x, int y);
	~Gamma();
private:
	void dibujar() override;
};

Gamma::Gamma(int x, int y) : Nave(x, y)
{
	this->ancho = 21;
	this->alto = 7;
	this->color = 13;
}

Gamma::~Gamma()
{
}

void Gamma::dibujar()
{
	Console::ForegroundColor = ConsoleColor(color);
	Console::SetCursorPosition(x, y);
	cout << "      .";
	Console::SetCursorPosition(x, y + 1);
	cout << "    _\"^\"_";
	Console::SetCursorPosition(x, y + 2);
	cout << "  _/ ... \\_";
	Console::SetCursorPosition(x, y + 3);
	cout << ",\"-. 000 .\"-,";
	Console::SetCursorPosition(x, y + 4);
	cout << "`.,_______,.'";
	Console::SetCursorPosition(x, y + 5);
	cout << "   /     \\";
	Console::SetCursorPosition(x, y + 6);
	cout << " _\"_     _\"_";
}