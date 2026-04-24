#pragma once
#include <iostream>
using namespace System;
using namespace std;

class Ala
{
private:

public:
	Ala();
	~Ala();
	void dibujar(int x, int y);

};

Ala::Ala()
{
}

Ala::~Ala()
{
}

void Ala::dibujar(int x, int y)
{
	Console::SetCursorPosition(x, y);
	cout << "__|__";
}
