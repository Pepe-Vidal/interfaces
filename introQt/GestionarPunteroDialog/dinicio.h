#ifndef _DINICIO_H
#define _DINICIO_H

#include <QDialog>
#include <QPushButton>
#include "dtransferencia.h"


class DInicio : public QDialog{

Q_OBJECT

public:

	DInicio(QWidget *parent = nullptr);
	DTransferencia *dtrans;
	QPushButton *btnLanzar;
	
public slots: 

	void slotAbrirDialogo();


};

#endif 
