#include "dexamen.h"
#include <QFileInfo>
#include <QMessageBox>
#include <QDebug>

DExamen::DExamen(QStringList *lista,QWidget *parent): QDialog(parent){

	setupUi(this);
	
	cargarFile(lista);
	
	connect(btCargar, SIGNAL(clicked()),
		this, SLOT(slotCargar()));

	connect(cbFichero, SIGNAL(currentIndexChanged(int)),
		this, SLOT(slotPrimeraLinea(int)));
		

}
void DExamen::slotPrimeraLinea(int i){

	QFile fichero(cbFichero->itemData(i).toString());

	fichero.open(QIODevice::ReadOnly);
	
	QTextStream stream(&fichero);

	lPrimeraLinea->setText(stream.readLine());

}

void DExamen::cargarFile(QStringList *lista){

cbFichero->clear();
	for(int i=0; i< lista->size() ; i++){
	
	
	QString ruta = lista->at(i);
	
	QString rutaCorta = QFileInfo(ruta).fileName();
	
	QVariant vaRuta(ruta);
	cbFichero->addItem(rutaCorta,vaRuta);
	
	}

}

void DExamen::slotCargar(){


	QString ruta = cbFichero->currentData().toString();

	emit senyalCargarFile(ruta);
	
	accept();
	
}
