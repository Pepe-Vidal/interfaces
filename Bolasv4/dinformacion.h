#ifndef _DINFORMACION_H
#define _DINFORMACION_H

#include <QDialog>
#include <QLabel>

class DInformacion : public QDialog{

Q_OBJECT

public:

	DInformacion(int,int,int,QWidget *parent = nullptr);
	
	int altura, anchura, bolas;
	QLabel *lbResolucion;
	QLabel *lbBolas;
	
	

	
public slots: 

	void slotEjemplo();

};

#endif 
