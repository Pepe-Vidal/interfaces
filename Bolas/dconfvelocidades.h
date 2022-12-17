#ifndef _DCONFVELOCIDADES_H
#define _DCONFVELOCIDADES_H

#include <QDialog>
#include <QVector>
#include <QVBoxLayout>
#include "bola.h"
#include "ui_dconfvelocidades.h"

class DConfVelocidades : public QDialog, public Ui::DConfVelocidades{

Q_OBJECT

public:

	DConfVelocidades(QVector<Bola*> *bolasPasadas,QWidget *parent = nullptr);

	
public slots: 

	void slotEjemplo();
	void slotPararTodas();

};

#endif 
