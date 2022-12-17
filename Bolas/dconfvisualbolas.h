#ifndef _DCONFVISUALBOLAS_H
#define _DCONFVISUALBOLAS_H

#include <QDialog>
#include <QVector>
#include <QVBoxLayout>
#include "bola.h"
#include "widgetconfbola.h"
#include "ui_dconfvisualbolas.h"

class DConfVisualBolas : public QDialog, public Ui::DConfVisualBolas{

Q_OBJECT

public:

	DConfVisualBolas(QVector<Bola*> *bolasPasadas,QWidget *parent = nullptr);

	
public slots: 

	void slotEjemplo();
	void slotVerificar();
	void slotTodasBolas();

};

#endif 
