#pragma once
#include "Objeto.hpp"

class VidaVegetal : public Objeto
{
private:
public:
	VidaVegetal(int x, int y);
	~VidaVegetal();
	void dibujar() override;
};

VidaVegetal::VidaVegetal(int x, int y) : Objeto(x, y, 5, 2)
{
}

VidaVegetal::~VidaVegetal()
{
}

void VidaVegetal::dibujar()
{
	Console::ForegroundColor = ConsoleColor::Green;
	Console::SetCursorPosition(x, y);
	cout << " (W)";
	Console::SetCursorPosition(x, y + 1);
	cout << "_\\|/_";
	Console::ResetColor();
}
