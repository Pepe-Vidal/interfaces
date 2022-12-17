#include "bola.h"

#include <math.h>
#include <QDebug>
#include <stdlib.h>

Bola::Bola()
{
	diametro = 40;
	vida = VIDAMAX;
}

Bola::Bola(float px, float py, float vx, float vy) : posX(px), posY(py), velX(vx), velY(vy), vida(VIDAMAX)
{

	diametro = 40;

	int r = random() % 256;
	int g = random() % 256;
	int b = random() % 256;

	color = QColor(r, g, b);
}

void Bola::mover(int anchura, int altura)
{

	if (posX >= anchura - diametro)
	{
		velX = -fabs(velX - 0.01);
	}
	if (posX <= 0)
	{
		velX = fabs(velX - 0.01);
	}
	if (posY >= altura - diametro)
	{
		velY = -fabs(velY - 0.01);
	}
	if (posY <= 0 + 23)
	{
		velY = fabs(velY - 0.01);
	}

	posX = posX + velX;
	posY = posY + velY;
}

void Bola::pintar(QPainter &pintor)
{

	QBrush brush(color);
	pintor.setBrush(brush);

	pintor.drawEllipse(posX, posY, diametro, diametro);
	pintor.drawText(posX, posY + diametro * 1.3, nombre);

	int ancho = diametro;
	float anchoVerde = (((float)vida) / VIDAMAX) * (float)ancho;
	float anchoRojo = (ancho - (float)anchoVerde);
	pintor.setBrush(Qt::green);
	pintor.drawRect(posX, posY, anchoVerde, 3);
	pintor.setBrush(Qt::red);
	pintor.drawRect(posX + anchoVerde, posY, anchoRojo, 3);
}

float Bola::distancia(Bola *otra)
{

	float dist;

	dist = sqrtf(powf(posX - otra->posX, 2) + powf(posY - otra->posY, 2));

	return dist;
}

bool Bola::chocar(Bola *otra)
{

	if (distancia(otra) > diametro)
	{
		return false;
	}

	bool colision = false;

	Bola *arriba, *abajo, *derecha, *izquierda;

	if (posY < otra->posY)
	{
		arriba = this;
		abajo = otra;
	}
	else
	{
		abajo = this;
		arriba = otra;
	}

	if (arriba->velY > abajo->velY)
	{

		float auxY = arriba->velY;
		arriba->velY = abajo->velY;
		abajo->velY = auxY;

		colision = true;
	}

	// Colision costado

	if (posX > otra->posX)
	{
		derecha = this;
		izquierda = otra;
	}
	else
	{
		izquierda = this;
		derecha = otra;
	}

	if (derecha->velX < izquierda->velX)
	{

		float auxX = derecha->velX;
		derecha->velX = izquierda->velX;
		izquierda->velX = auxX;

		colision = true;
	}

	return colision;
}

bool Bola::isSeleccionada(int x, int y)
{

	if (x > posX && x < posX + 40 && y > posY && y < posY + 40)
	{
		qDebug() << nombre << " Seleccionada " << x << y;
		qDebug() << nombre << " PosX " << posX << "PosY" << posY;
		return true;
	}

	return false;
}
