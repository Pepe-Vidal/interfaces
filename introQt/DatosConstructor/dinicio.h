#ifndef _DINICIO_H
#define _DINICIO_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QStringList>
#include "dtransferencia.h"


class DInicio : public QDialog{

Q_OBJECT

public:

	DInicio(QWidget *parent = nullptr);
	QStringList listaCuentas;
	QLabel *lbtransferencia;
	DTransferencia *dtrans;
	QPushButton *btnLanzar;
	
public slots: 

	void slotAbrirDialogo();
	void slotListoTrans();
	void slotRecTrans();



};

#endif 
