#ifndef _WIDGETBORDES_H
#define _WIDGETBORDES_H

#include <QWidget>
#include <QTimer>
#include <QPushButton>
#include <QLabel>
#include "bola.h"
class WidgetBordes : public QWidget{

Q_OBJECT

public:

	WidgetBordes(Bola *bola,QWidget *parent = nullptr);
	Bola *bolasel;
	
	QTimer *temporizador;
	QPushButton *btnarriba;
	QPushButton *btnabajo;
	QPushButton *btnderecha; 
	QPushButton *btnizquierda; 

	QLabel *lbarriba;
	QLabel *lbabajo;
	QLabel *lbderecha;
	QLabel *lbizquierda; 

public slots: 

	void slotEjemplo();
	void slotResetContador();
	void slotTemporizador();
};

#endif 
