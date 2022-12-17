#ifndef _DPRINCIPAL_H
#define _DPRINCIPAL_H

#include <QDialog>
#include "ui_calculadora.h"

class DCalculadora : public QDialog, public Ui::DCalculadora{

Q_OBJECT

public:

	DCalculadora(QWidget *parent = nullptr);
	
	/*
	QStringList listaCuentas;
	QLabel *lbtransferencia;
	DTransferencia *dtrans;
	QPushButton *btnLanzar, *btnActualizar;
	*/
	
public slots: 

	void slotEscribirCero();
	void slotbotonC();
/*
	void slotAbrirDialogo();
	void slotActualizarDialogo();
	void slotListoTransDato(float,QString);
	void slotListoTrans();
	void slotRecTrans();
*/


};

#endif 
