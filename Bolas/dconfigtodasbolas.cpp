#include <QDebug>
#include "dconfigtodasbolas.h"

DConfigTodasBolas::DConfigTodasBolas(QVector<Bola*> bolasPasadas,QWidget *parent): QDialog(parent){

	setupUi(this);
	
	setWindowTitle("Configuración Bolas-Examen Jose Vidal Castells");
	bolas = bolasPasadas;
	i=0;
	
	wconfigBolas = new WidgetConfBola(bolasPasadas.at(i));
	layout = new QVBoxLayout();

	layout->addWidget(wconfigBolas);

	frame->setLayout(layout);
	
	lbNombre->setText(bolas.at(i)->nombre);
	
	connect(btnAnterior, SIGNAL(clicked()),
			this, SLOT(slotAnterior()));
			
	connect(btnSiguiente, SIGNAL(clicked()),
			this, SLOT(slotSiguiente()));

}

void DConfigTodasBolas::cambiarWidget(){

	if ( wconfigBolas != NULL ){
   	 	frame->layout()->removeWidget(wconfigBolas);
   	 	delete wconfigBolas;
    }
    
    wconfigBolas = new WidgetConfBola(bolas.at(i));
	layout->addWidget(wconfigBolas);
	
    lbNombre->setText(bolas.at(i)->nombre);
    
	//update();
}

void DConfigTodasBolas::slotAnterior(){

	if(i > 0){
	i--;
	cambiarWidget();
	}
	
}

void DConfigTodasBolas::slotSiguiente(){

	if(i < bolas.size()-1){
		qDebug() << i << bolas.size();
		i++;
		cambiarWidget();
	}
	
}
void DConfigTodasBolas::slotEjemplo(){

	
	
}
