#include "dconfvelocidades.h"
#include "widgetconfvelocidad.h"

DConfVelocidades::DConfVelocidades(QVector<Bola*> *bolasPasadas,QWidget *parent): QDialog(parent){

	setupUi(this);
	tabBolas->clear();

	
	for(int i = 0; i < bolasPasadas->size(); i++){
	
	WidgetConfVelocidad *w = new  WidgetConfVelocidad(bolasPasadas->at(i));
	
	tabBolas->addTab(w, bolasPasadas->at(i)->nombre);

	}
	

	connect(btnActivarColision, SIGNAL(clicked()),
			this, SLOT(slotEjemplo()));
	
	connect(btnPararTodas, SIGNAL(clicked()),
			this, SLOT(slotPararTodas()));

}

void DConfVelocidades::slotPararTodas(){

for(int i = 0; i < tabBolas->count(); i++){
	
		WidgetConfVelocidad *w = qobject_cast<WidgetConfVelocidad *>(tabBolas->widget(i));
		
		//w->bolaSel->para();
		w->slHorizontal->setSliderPosition(0);
		w->slVertical->setSliderPosition(0);
		w->slHorizontal->setValue(0);
		w->slVertical->setValue(0);
	}



}
void DConfVelocidades::slotEjemplo(){


	for(int i = 0; i < tabBolas->count(); i++){
	
		WidgetConfVelocidad *w = qobject_cast<WidgetConfVelocidad *>(tabBolas->widget(i));
		
		w->cbColisionar->setChecked(true);

	}
	
}


