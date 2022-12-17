#ifndef BOLA_H
#define BOLA_H
#include <QColor>
#include <QPainter>
#include <QString>
#include <QImage>
class Bola
{

public:
	enum BolaResalte
	{
		BolaCirculo,
		BolaPatron,
		BolaImagen
	};

     QImage imagen;
	const static int VIDAMAX = 100;
	BolaResalte resalte;
	int vida;
	float posX;
	float posY;
	float velX;
	float velY;
	float diametro;
	QColor color;

	Bola();
	Bola(float, float, float, float);
	QString nombre;

	void pintar(QPainter &);
	void mover(int, int);
	void para();
	float distancia(Bola *);
	bool chocar(Bola *);
	bool isSeleccionada(int,int);
};
#endif
