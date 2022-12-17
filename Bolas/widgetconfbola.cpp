#include <QDebug>
#include <QColorDialog>
#include <QFileDialog>
#include <QColor>
#include "widgetconfbola.h"

WidgetConfBola::WidgetConfBola(Bola *bola,QWidget *parent): QWidget(parent){
	setupUi(this);
	
	bolaSel = bola;
	ruta="";
	connect(leNombre, SIGNAL(returnPressed()),
		   this, SLOT(slotNombreConfirmado()));
		   
	connect(rbCirculo, SIGNAL(released()),
		   this, SLOT(slotBolaCirculo()));
		   
	connect(rbPatron, SIGNAL(released()),
		   this, SLOT(slotBolaPatron()));
		   
	connect(rbImagen, SIGNAL(released()),
		   this, SLOT(slotBolaImagen()));
		   
		   
	connect(btnColor, SIGNAL(clicked()),
			this, SLOT(slotColorBola()));
			
	connect(btnImagen, SIGNAL(clicked()),
			this, SLOT(slotSelImagenBola()));
			
			
	connect(rbCirculo, SIGNAL(released()),
		   this, SIGNAL(signalAlgoCambia()));

	connect(rbPatron, SIGNAL(released()),
		   this, SIGNAL(signalAlgoCambia()));
		   
	connect(rbImagen, SIGNAL(released()),
		   this, SIGNAL(signalAlgoCambia()));
	
}

void WidgetConfBola::slotSelImagenBola(){

	ruta = QFileDialog::getOpenFileName(this, QString("Selecciona la Imagen"), ".", QString("Imagenes (*.png *.jpg )"));
}



void WidgetConfBola::slotColorBola(){
	
	QColorDialog *d = new QColorDialog();
	
	d->show();
	
	connect(d, SIGNAL(colorSelected(QColor)),
		   this, SLOT(slotCambiarColorBola(QColor)));
	
}
void WidgetConfBola::slotCambiarColorBola(const QColor &color){

	bolaSel->color = color;

}

void WidgetConfBola::slotBolaImagen(){

	if(ruta==""){
		ruta = QFileDialog::getOpenFileName(this, QString("Selecciona la Imagen"), ".", QString("Imagenes (*.png *.jpg )"));
	}
	QImage img = QImage(ruta);
	bolaSel->imagen = img.scaled(bolaSel->diametro,bolaSel->diametro);
	bolaSel->resalte = Bola::BolaImagen;
	
	

}
void WidgetConfBola::slotBolaCirculo(){

	bolaSel->resalte = Bola::BolaCirculo;
	
	

}
void WidgetConfBola::slotBolaPatron(){

	bolaSel->resalte = Bola::BolaPatron;
	

}

void WidgetConfBola::slotNombreConfirmado(){

	qDebug() << "HOlala"; 

	bolaSel->nombre = leNombre->text();
	
	

}

void WidgetConfBola::slotEjemplo(){

	
	
}
