#ifndef _DINFO_H
#define _DINFO_H

#include <QDialog>
#include <QTextDocument>
#include "ui_dinfo.h"

class DInfo : public QDialog, public Ui::DInfo{

Q_OBJECT

public:

	DInfo(QTextDocument *doc,QWidget *parent = nullptr);

	QTextDocument *documento;

	void mostrarNumeroLineas();
	void showEvent(QShowEvent *event);
	void focusInEvent(QFocusEvent *event);
	
public slots: 

	void slotTextoModificado();

};

#endif 
