#ifndef _WIDGETCONFBOLA_H
#define _WIDGETCONFBOLA_H

#include <QWidget>
#include <QKeyEvent>
#include "ui_widgetconfbola.h"
#include "bola.h"

class WidgetConfBola : public QWidget, public Ui::WidgetConfBola{

Q_OBJECT

public:

	WidgetConfBola(Bola *bola,QWidget *parent = nullptr);
	Bola *bolaSel;
	QString ruta;
	
	void slotActualizarBola(Bola *bola);
	
public slots: 

	void slotEjemplo();
	void slotNombreConfirmado();
	void slotBolaCirculo();
	void slotBolaPatron();
	void slotBolaImagen();
	void slotSelImagenBola();
	void slotColorBola();
	
	void slotCambiarColorBola(const QColor &color);
	
signals:

	void signalAlgoCambia();
};

#endif 
