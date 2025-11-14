#pragma once
#include <iostream>
using namespace std;
using namespace System::Drawing;

class Princesas
{
private:
	int x, y, width, height;
	int idx, idy;
	float zoom;
	int sustos;
	bool estaEnMovimiento;
public:
	Princesas(int width, int height); // W_TOTAL / 5; H_TOTAL / 4
	~Princesas();
	void dibujar(Graphics^ g, Bitmap^ bmp);
	void mover();
	void resetearSprite();
	void animar(bool estaEnMovimiento);
	int getSustos();
	void setSustos(int sustos);
};

Princesas::Princesas(int width, int height)
{
	x = y = 0;
	this->width = width;
	this->height = height;
	zoom = 3.0f;
	idx = 0;
	idy = 0;
	sustos = 0;
	estaEnMovimiento = false;
}

Princesas::~Princesas()
{
}

void Princesas::dibujar(Graphics^ g, Bitmap^ bmp)
{
	// Que parte de la imagen dibujo
	Rectangle sectionPicture = Rectangle(idx * width, idy * height, width, height);
	// Donde lo ubico en el formulario
	Rectangle sectionForm = Rectangle(x, y, width * this->zoom, height * this->zoom);

	g->DrawImage(bmp, sectionForm, sectionPicture, GraphicsUnit::Pixel);
}

void Princesas::mover()
{
	if (!estaEnMovimiento) return;

	idx++;
	if (idx > 4) {
		idx = 0;
		idy++;
	}
	if (idy > 3) {
		idy = 0;
		sustos++;
	}
}

void Princesas::resetearSprite()
{
	idx = idy = 0;
}

void Princesas::animar(bool estaEnMovimiento)
{
	this->estaEnMovimiento = estaEnMovimiento;
}

int Princesas::getSustos()
{
	return this->sustos;
}

void Princesas::setSustos(int sustos)
{
	this->sustos = sustos;
}
