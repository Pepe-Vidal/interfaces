#ifndef _DREBOTES_H
#define _DREBOTES_H

#include <QDialog>
#include "ui_drebotes.h"
#include "bola.h"

class DRebotes : public QDialog, public Ui::DRebotes{

Q_OBJECT

public:

	DRebotes(Bola *bola,QWidget *parent = nullptr);

	
public slots: 

	void slotEjemplo();

};

#endif 
