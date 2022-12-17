#ifndef _DPARARBOLAS_H
#define _DPARARBOLAS_H

#include <QDialog>
#include <QVector>
#include "ui_dpararbolas.h"
#include <QPushButton>
#include "bola.h"
#include "miboton.h"

class DPararBolas : public QDialog, public Ui::DPararBolas{

Q_OBJECT

public:

	DPararBolas(QVector<Bola*>*,QWidget *parent = nullptr);
	QVector<MiBoton*> botones;
	QVector<Bola*> *bolas;
	
public slots: 

	void slotEjemplo();
	void slotBotonBolas();
};

#endif 
