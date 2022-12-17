#ifndef _DCONFIGTODASBOLAS_H
#define _DCONFIGTODASBOLAS_H

#include <QDialog>
#include <QVector>
#include <QVBoxLayout>
#include "bola.h"
#include "widgetconfbola.h"
#include "ui_dconfigtodasbolas.h"

class DConfigTodasBolas : public QDialog, public Ui::DConfigTodasBolas{

Q_OBJECT

public:

	DConfigTodasBolas(QVector<Bola*> bolasPasadas,QWidget *parent = nullptr);

	WidgetConfBola *wconfigBolas;
	int i;
	QVector<Bola*> bolas;
	QVBoxLayout *layout;
	
	void cambiarWidget();
	
public slots: 

	void slotEjemplo();
	void slotAnterior();
	void slotSiguiente();

};

#endif 
