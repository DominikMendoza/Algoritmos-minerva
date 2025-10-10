#pragma once
#include "ObjetoMovil.hpp"

class AveDodo : public ObjetoMovil
{
private:
public:
	AveDodo(int x, int y, int dy);
	~AveDodo();
	void mover() override;
	void dibujar() override;

};

AveDodo::AveDodo(int x, int y, int dy)
	: ObjetoMovil(x, y, 7, 4, 0, dy)
{
}

AveDodo::~AveDodo()
{
}

void AveDodo::mover()
{
	if (y + dy < 0 || y + dy + height > HEIGHT) {
		dy *= -1;
	}

	y += dy;
}

void AveDodo::dibujar()
{
	Console::ForegroundColor = ConsoleColor::Magenta;
	Console::SetCursorPosition(x, y);
	cout << "/ \\ / \\";
	Console::SetCursorPosition(x, y + 1);
	cout << "((ovo))";
	Console::SetCursorPosition(x, y + 2);
	cout << "():::()";
	Console::SetCursorPosition(x, y + 3);
	cout << "  VVV";
	Console::ResetColor();
}
