#ifndef _WIDGETCONFVELOCIDAD_H
#define _WIDGETCONFVELOCIDAD_H

#include <QWidget>
#include "ui_widgetconfvelocidad.h"
#include "bola.h"

class WidgetConfVelocidad : public QWidget, public Ui::WidgetConfVelocidad{

Q_OBJECT

public:

	WidgetConfVelocidad(Bola *bola,QWidget *parent = nullptr);
	Bola *bolaSel;
	
public slots: 

	void slotEjemplo();
	void slotVelX(int);
	void slotVelY(int);

};

#endif 
