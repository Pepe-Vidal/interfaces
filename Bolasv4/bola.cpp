#include "bola.h"

#include <math.h>
#include <stdlib.h>

Bola::Bola()
{
	diametro = 40;
	vida = VIDAMAX;

	resalte = BolaCirculo;

	rebotes.resize(IZQUIERDA+1);
	for(int  i = 0 ; i< rebotes.size();i++)
   		rebotes[i] = 0;
}

Bola::Bola(float px, float py, float vx, float vy) : posX(px), posY(py), velX(vx), velY(vy), vida(VIDAMAX)
{

	diametro = 40;

	resalte = BolaCirculo;

	rebotes.resize(IZQUIERDA+1);
	for(int  i = 0 ; i< rebotes.size();i++)
   		rebotes[i] = 0;

	int r = random() % 256;
	int g = random() % 256;
	int b = random() % 256;

	color = QColor(r, g, b);
}

void Bola::mover(int anchura, int altura)
{

	if (posX >= anchura - diametro)
	{
		velX = -fabs(velX);
		rebotes[DERECHA]++;
	}
	if (posX <= 0)
	{
		velX = fabs(velX);
		rebotes[IZQUIERDA]++;
	}
	if (posY >= altura - diametro)
	{
		velY = -fabs(velY);
		rebotes[ABAJO]++;
	}
	if (posY <= 0 + 23)
	{
		velY = fabs(velY);
		rebotes[ARRIBA]++;
	}

	posX = posX + velX;
	posY = posY + velY;
}

void Bola::pintar(QPainter &pintor)
{

	QBrush brush(color);
	pintor.setBrush(brush);

	switch (resalte)
	{
	case BolaPatron:
		pintor.setBrush(Qt::CrossPattern);
	case BolaCirculo:
		pintor.drawEllipse(posX, posY, diametro, diametro);
		break;
	case BolaImagen:
		pintor.drawImage(posX, posY, imagen);
		break;
	}

	for (int l = ARRIBA; l <= IZQUIERDA;l = l+1) {
   	 int pX= posX + diametro/2;
   	 int pY= posY + diametro/2;

   	 if (l == ARRIBA) pY = posY - 10;
   	 if (l == DERECHA) pX = posX + diametro +10;
   	 if (l == ABAJO) pY = posY + diametro +10 ;
   	 if (l == IZQUIERDA) pX = posX - 10;
    
   	 pintor.drawText(pX,pY,QString::number(rebotes.at(l)));
    }


	/*
		pintor.drawEllipse(posX, posY, diametro, diametro);
	*/
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

void Bola::para()
{
	velX = 0;
	velY = 0;
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
