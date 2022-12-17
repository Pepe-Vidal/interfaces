#ifndef _DEXAMEN_H
#define _DEXAMEN_H

#include <QDialog>
#include <QString>
#include <QStringList>
#include "ui_dexamen.h"

class DExamen : public QDialog, public Ui::DExamen{

Q_OBJECT

public:

	DExamen(QStringList*, QWidget *parent = nullptr);

	void cargarFile(QStringList*);

public slots: 

	void slotCargar();
	void slotPrimeraLinea(int);


signals:

	void senyalCargarFile(QString);
};

#endif 
