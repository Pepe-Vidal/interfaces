#include "widgetconfvelocidad.h"

WidgetConfVelocidad::WidgetConfVelocidad(Bola *bola,QWidget *parent): QWidget(parent){

	setupUi(this);
	bolaSel = bola;
	cbColisionar->setChecked(true);

slHorizontal->setRange(-50, 50);
slVertical->setRange(-50, 50);

slHorizontal->setValue(bola->velX*50/3);
slVertical->setValue(bola->velY*50/3);

		
	connect(slHorizontal, SIGNAL(valueChanged(int)),
			this, SLOT(slotVelX(int)));
			
	connect(slVertical, SIGNAL(valueChanged(int)),
			this, SLOT(slotVelY(int)));

}
void WidgetConfVelocidad::slotVelY(int v){

	bolaSel->velY = v*3/50;

}
void WidgetConfVelocidad::slotVelX(int v){

	bolaSel->velX = v*3/50;

}
void WidgetConfVelocidad::slotEjemplo(){


}
