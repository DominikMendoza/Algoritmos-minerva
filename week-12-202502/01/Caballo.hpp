#pragma once
#include <iostream>
using namespace std;
using namespace System::Drawing;

class Caballo
{
private:
	int x, y, dx, dy, width, height;
	int idx, idy;
	char color;
	float zoom;
public:
	Caballo(int width, int height); // W_TOTAL / 6; H_TOTAL / 8
	~Caballo();
	void dibujar(Graphics^ g, Bitmap^ bmp);
	void mover(Graphics^ g, char tecla);
	int getX();
	void setColor(char color);
};

Caballo::Caballo(int width, int height)
{
	x = y = 150;
	dx = dy = 5;
	this->width = width;
	this->height = height;
	zoom = 1.25f;
	idx = 0;
	idy = 0;
	color = 'B';
}

Caballo::~Caballo()
{
}

void Caballo::dibujar(Graphics^ g, Bitmap^ bmp)
{
	// Que parte de la imagen dibujo
	Rectangle sectionPicture = Rectangle(idx * width, idy * height, width, height);
	// Donde lo ubico en el formulario
	Rectangle sectionForm = Rectangle(x, y, width * this->zoom, height * this->zoom);

	g->DrawImage(bmp, sectionForm, sectionPicture, GraphicsUnit::Pixel);
}

void Caballo::mover(Graphics^ g, char tecla)
{
	switch (tecla)
	{
		// Los valores de idy van desde 0 hasta 3 para las filas superiores
	case 'W': {
		if (y - dy < 0) return;
		idy = 3; // sprite hacia arriba
		y -= dy;
		break;
	}
	case 'A': {
		if (x - dx < 0) return;
		idy = 1; // sprite hacia la izquierda
		x -= dx;
		break;
	}
	case 'S': {
		if (y + height * zoom + dy > g->VisibleClipBounds.Height) return;
		idy = 0; // sprite hacia abajo
		y += dy;
		break;
	}
	case 'D': {
		if (x + width * zoom + dx > g->VisibleClipBounds.Width) return;
		idy = 2; // sprite hacia la derecha
		x += dx;
		break;
	}
	}

	if (color == 'V' || color == 'Z') {
		// Incremento 4 a la fila, porque busco en el bloque inferior del sprite
		idy += 4;
	}

	int minimo = 0; int maximo = 2;

	if (color == 'A' || color == 'Z') {
		minimo += 3;
		maximo += 3;
	}

	idx++;
	if (idx < minimo) {
		idx = minimo;
	}
	if (idx > maximo) {
		idx = minimo;
	}
}

int Caballo::getX()
{
	return x;
}

void Caballo::setColor(char color)
{
	// Actualizar la fila
	switch (color)
	{
	case 'B':
	case 'A':
		idy = 0; break;
	case 'V':
	case 'Z':
		idy = 4; break;
	}

	// Actualizar la columna
	switch (color)
	{
	case 'B':
	case 'V':
		idx = 0; break;
	case 'A':
	case 'Z':
		idx = 3; break;
	}

	this->color = color;
}
