#include "dpararbolas.h"
#include <QDialog>
#include <QGridLayout>
#include <QPushButton>
#include "miboton.h"
#include <QDebug>
#include <QString>

DPararBolas::DPararBolas(QVector<Bola*>* bolasR,QWidget *parent): QDialog(parent)
{

	setupUi(this);
	bolas = bolasR;
	
	QGridLayout *layout = new QGridLayout();
	
	for(int i=0 ; i<bolas->size(); i++ ){
	
		QString nombre("Boton");
		nombre = nombre + QString::number(i);
	
		MiBoton *btn = new MiBoton(bolas->at(i)->nombre);
		btn->bola = bolas->at(i);
		botones.append(btn);
		
		connect(btn, SIGNAL(clicked()),
			this, SLOT(slotBotonBolas()));
		
	}
	

	for(int i=0 ; i<botones.size(); i++ ){
	
		layout->addWidget(botones.at(i),i/3,i%3);
		

	}
	
	
	frameBotones->setLayout(layout);

}

void DPararBolas::slotBotonBolas(){

	QObject * oEmisor = sender();
	MiBoton *botonCulpable = qobject_cast<MiBoton*>(oEmisor);
	
	QString res = botonCulpable->text();
	qDebug() << res;
	
	botonCulpable->bola->para();
	
	/*
	for(int i = 0 ; i < botones.size(); i++ ){
	
		if(botones.at(i) == botonCulpable){
	
			bolas->at(i)->velY = 0;
			bolas->at(i)->velX = 0;
		
		}
	}
	*/

}
void DPararBolas::slotEjemplo(){

	
	
}
