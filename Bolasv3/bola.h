#ifndef BOLA_H
#define BOLA_H
#include <QColor>
#include <QPainter>
#include <QString>
class Bola {

public:
	
	const static int VIDAMAX = 100;
	int vida;
	float posX;
	float posY;
	float velX;
	float velY;
	float diametro;
	QColor color;
	
	Bola();
	Bola(float,float,float,float);
	QString nombre;

	void pintar(QPainter&);
	void mover(int,int);
	float distancia(Bola *);
	bool chocar(Bola *);
	bool isSeleccionada(int,int);
	
};
#endif
