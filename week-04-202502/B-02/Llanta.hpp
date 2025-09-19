#pragma once
#include <iostream>
using namespace std;
using namespace System;

class Llanta
{
private:
public:
	Llanta();
	~Llanta();
	void dibujar(int x, int y);
};

Llanta::Llanta()
{
}

Llanta::~Llanta()
{
}

void Llanta::dibujar(int x, int y)
{
	Console::SetCursorPosition(x, y);
	cout << char(220);
}
