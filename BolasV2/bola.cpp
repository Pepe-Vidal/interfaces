#include "bola.h"
#include <QDebug>
Bola::Bola(){ 


}
Bola::Bola(qreal x,qreal y,qreal width,qreal height): QRectF( x, y, width, height){ 

	qDebug() <<"hola";

	posX=x;
	posY=y;
	velX=2;
	velY=2;

}