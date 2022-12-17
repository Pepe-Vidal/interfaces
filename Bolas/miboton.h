#ifndef _MIBOTON_H
#define _MIBOTON_H


#include <QPushButton>
#include "bola.h"

class MiBoton : public QPushButton{

Q_OBJECT

public:

	MiBoton(QWidget *parent = nullptr);
	MiBoton(const QString &text, QWidget *parent = nullptr);
	
	Bola *bola;

	
};

#endif 
