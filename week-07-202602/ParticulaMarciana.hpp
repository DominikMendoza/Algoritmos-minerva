#pragma once
#include "Objeto.hpp"

class ParticulaMarciana : public Objeto
{
public:
	ParticulaMarciana(int x, int y);
	~ParticulaMarciana();
	void dibujar() override;
private:
};

ParticulaMarciana::ParticulaMarciana(int x, int y) : Objeto(x, y)
{
	dx = 0; dy = 0;
	ancho = 1;
	alto = 1;
	color = 11;
}

ParticulaMarciana::~ParticulaMarciana()
{
}

void ParticulaMarciana::dibujar()
{
	Console::ForegroundColor = ConsoleColor(color);
	Console::SetCursorPosition(x, y);
	cout << char(111);
	Console::ResetColor();
}
