#pragma once
#include <iostream>
using namespace std;
using namespace System::Drawing;

class Objeto
{
protected:
	int x, y, dx, dy, width, height;
	int idx, idy;
	float zoom;
	bool visible;
public:
	Objeto(int x, int y, int width, int height); // W_TOTAL / COLUMNAS; H_TOTAL / FILAS
	~Objeto();
	void setPosicion(int x, int y);
	void dibujar(Graphics^ g, Bitmap^ bmp);
	bool estaColisionandoCon(Objeto* obj);
	void cambiarVisibilidad();
	int getX();
	int getY();
};

Objeto::Objeto(int x, int y, int width, int height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	zoom = 1.0f;
	dx = dy = 0;
	idx = idy = 0;
	visible = true;
}

Objeto::~Objeto()
{
}

void Objeto::setPosicion(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Objeto::dibujar(Graphics^ g, Bitmap^ bmp)
{
	if (!visible) return;
	// Que parte de la imagen dibujo
	Rectangle sectionPicture = Rectangle(idx * width, idy * height, width, height);
	// Donde lo ubico en el formulario
	Rectangle sectionForm = Rectangle(x, y, width * this->zoom, height * this->zoom);

	g->DrawImage(bmp, sectionForm, sectionPicture, GraphicsUnit::Pixel);
}

bool Objeto::estaColisionandoCon(Objeto* obj)
{
	if (!obj->visible || !this->visible)
		return false;
	return
		x < obj->x + obj->width * obj->zoom &&
		obj->x < x + width * zoom &&
		y < obj->y + obj->height * obj->zoom &&
		obj->y < y + height * zoom;
}

void Objeto::cambiarVisibilidad()
{
	this->visible = !this->visible;
}

int Objeto::getX()
{
	return this->x;
}

int Objeto::getY()
{
	return this->y;
}
