#ifndef _DPRINCIPAL_H
#define _DPRINCIPAL_H

#include <QDialog>
#include "ui_dprincipal.h"

class DPrincipal : public QDialog, public Ui::DPrincipal{

Q_OBJECT

public:

	DPrincipal(QWidget *parent = nullptr);
	
	/*
	QStringList listaCuentas;
	QLabel *lbtransferencia;
	DTransferencia *dtrans;
	QPushButton *btnLanzar, *btnActualizar;
	
public slots: 

	void slotAbrirDialogo();
	void slotActualizarDialogo();
	void slotListoTransDato(float,QString);
	void slotListoTrans();
	void slotRecTrans();
*/


};

#endif 
