#pragma once
#include <iostream>
using namespace std;
using namespace System;

class Chasis
{
private:
public:
	Chasis();
	~Chasis();
	void dibujar(int x, int y);
};

Chasis::Chasis()
{
}

Chasis::~Chasis()
{
}

void Chasis::dibujar(int x, int y)
{
	Console::SetCursorPosition(x, y);
	for (int i = 0; i < 5; i++)
	{
		cout << char(220);
	}
}
