#ifndef BOLA_H
#define BOLA_H

#include <QRectF>

class Bola : public QRectF {

public:
	float posX;
	float posY;
	float velX;
	float velY;

	Bola();
	Bola(qreal x,qreal y,qreal width,qreal height);
	

	
};
#endif
