#ifndef _DCONFIGBOLA_H
#define _DCONFIGBOLA_H

#include <QDialog>
#include "widgetconfbola.h"
#include "bola.h"

class DConfigBola : public QDialog{

Q_OBJECT

public:

	DConfigBola(Bola *bola,QWidget *parent = nullptr);

	
public slots: 

	void slotEjemplo();

};

#endif 
