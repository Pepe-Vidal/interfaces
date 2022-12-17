#ifndef _DCALCULADORA_H
#define _DCALCULADORA_H

#include <QDialog>
#include "ui_calculadora.h"

class DCalculadora : public QDialog, public Ui::DCalculadora{

Q_OBJECT

public:

	DCalculadora(QWidget *parent = nullptr);

	
public slots: 

	void slotEjemplo();

};

#endif 
