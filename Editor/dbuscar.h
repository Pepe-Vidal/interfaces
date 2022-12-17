#ifndef _DBUSCAR_H
#define _DBUSCAR_H

#include <QDialog>
#include "ui_dbuscar.h"

class DBuscar : public QDialog, public Ui::DBuscar{

Q_OBJECT

public:

	DBuscar(QWidget *parent = nullptr);

	
public slots: 

	void slotBotonBuscar();
	
signals:

	void senyalBotonBuscarAlante(QString);

};

#endif 
