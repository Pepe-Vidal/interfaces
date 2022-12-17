#ifndef BOLA_H
#define BOLA_H
#include <QColor>
#include <QPainter>
#include <QVector>
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

	static const int ARRIBA = 0;
   	static const int DERECHA = 1;
   	static const int ABAJO = 2;
   	static const int IZQUIERDA = 3;

     QImage imagen;
	const static int VIDAMAX = 100;
	BolaResalte resalte;
	QVector<int> rebotes;
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
};
#endif
