#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QTimer>
#include <QVector>
#include <QKeyEvent>
#include "bola.h"

class MainWindow : public QMainWindow {
Q_OBJECT

public:

	float velMax;
	QTimer *temporizador;
	QVector<Bola*> bolas;
	Bola *bola;
	Bola *bola2;
	MainWindow(QWidget* parent = 0);
	
	
	void paintEvent ( QPaintEvent * event );
	//void keyPressEvent(QKeyEvent *event);
	void crearBolas();
	void calcularColisiones(Bola *,int);
	
public slots:
	void slotTemporizador();
	
};
#endif

