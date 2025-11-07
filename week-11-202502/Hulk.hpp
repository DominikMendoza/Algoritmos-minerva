#pragma once
#include <iostream>
using namespace std;
using namespace System::Drawing;

class Hulk
{
private:
	int x, y, dx, dy, width, height;
	int idx, idy;
	float zoom;
public:
	Hulk(int width, int height); // W_TOTAL / 4; H_TOTAL / 4
	~Hulk();
	void dibujar(Graphics^ g, Bitmap^ bmp);
	void mover(Graphics^ g, char tecla);
	int getX();
};

Hulk::Hulk(int width, int height)
{
	x = y = 150;
	dx = dy = 5;
	this->width = width;
	this->height = height;
	zoom = 0.7f;
	idx = 0;
	idy = 3;
}

Hulk::~Hulk()
{
}

void Hulk::dibujar(Graphics^ g, Bitmap^ bmp)
{
	// Que parte de la imagen dibujo
	Rectangle sectionPicture = Rectangle(idx * width, idy * height, width, height);
	// Donde lo ubico en el formulario
	Rectangle sectionForm = Rectangle(x, y, width * this->zoom, height * this->zoom);

	g->DrawImage(bmp, sectionForm, sectionPicture, GraphicsUnit::Pixel);
}

void Hulk::mover(Graphics^ g, char tecla)
{
	switch (tecla)
	{
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

	idx++;
	if (idx > 3) {
		idx = 0;
	}
}

int Hulk::getX()
{
	return x;
}