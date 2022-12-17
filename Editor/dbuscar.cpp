#include "dbuscar.h"
#include <QDialog>

DBuscar::DBuscar(QWidget *parent): QDialog(parent){

	setupUi(this);
	
	connect(btBuscar, SIGNAL(clicked()),
		   this, SLOT(slotBotonBuscar()));

}

void DBuscar::slotBotonBuscar(){

	QString palabra = leBuscar->text();
	
	emit senyalBotonBuscarAlante(palabra);
	
}
