#pragma once
#include "Objeto.hpp"

class ParticulaMarciana : public Objeto
{
private:
public:
	ParticulaMarciana(int x, int y);
	~ParticulaMarciana();
	void dibujar() override;
};

ParticulaMarciana::ParticulaMarciana(int x, int y) : Objeto(x, y, 1, 1)
{
}

ParticulaMarciana::~ParticulaMarciana()
{
}

void ParticulaMarciana::dibujar()
{
	Console::ForegroundColor = ConsoleColor::Blue;
	Console::SetCursorPosition(x, y);
	cout << char(111);
	Console::ResetColor();
}
