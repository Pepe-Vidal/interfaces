#include "dcalculadora.h"

DCalculadora::DCalculadora(QWidget *parent): QDialog(parent){

	setupUi(this);
	
	connect(bCero, SIGNAL(clicked()),
		this, SLOT(slotEscribirCero()));
		
	connect(bUno, SIGNAL(clicked()),
		this, SLOT(slotEscribirCero()));
		
	connect(bDos, SIGNAL(clicked()),
		this, SLOT(slotEscribirCero()));
		
	connect(bTres, SIGNAL(clicked()),
		this, SLOT(slotEscribirCero()));
		
		connect(bCuatro, SIGNAL(clicked()),
		this, SLOT(slotEscribirCero()));
		
		connect(bCinco, SIGNAL(clicked()),
		this, SLOT(slotEscribirCero()));
		
		connect(bSeis, SIGNAL(clicked()),
		this, SLOT(slotEscribirCero()));
		
		connect(bSiete, SIGNAL(clicked()),
		this, SLOT(slotEscribirCero()));
		
		connect(bOcho, SIGNAL(clicked()),
		this, SLOT(slotEscribirCero()));
		
		connect(bNueve, SIGNAL(clicked()),
		this, SLOT(slotEscribirCero()));

	connect(bC, SIGNAL(clicked()),
		this, SLOT(slotbotonC()));
}

void DCalculadora::slotEscribirCero(){


	QObject * oEmisor = sender();
	QPushButton *botonCulpable = qobject_cast<QPushButton*>(oEmisor);

	if(lcdResultado->intValue() == 0){
		QString res = botonCulpable->text();
		lcdResultado->display(res);
	}else{
		QString res = QString::number(lcdResultado->intValue())+botonCulpable->text();
		lcdResultado->display(res);
	}
	
	
}
void DCalculadora::slotbotonC(){

	lcdResultado->display("");
	
}
