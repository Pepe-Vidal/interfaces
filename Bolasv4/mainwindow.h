#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QTimer>
#include <QMenu>
#include <QAction>
#include <QVector>
#include <QKeyEvent>
#include "dinformacion.h"
#include "dpararbolas.h"
#include "drebotes.h"
#include "bola.h"

class MainWindow : public QMainWindow {
Q_OBJECT

public:

	float velMax;
	QTimer *temporizador;
	QVector<Bola*> bolas;
	MainWindow(QWidget* parent = 0);
	QStringList listaNombres;
	Bola *jugador;
	DInformacion * dinformacion;
	DPararBolas * dpararbolas;
	DRebotes * drebotebolas;
	QAction * accionInformacion;
	QAction * accionPararBolas;
	QAction * accionReboteBolas;
	
	void paintEvent ( QPaintEvent * event );
	void keyPressEvent(QKeyEvent *event);
	void crearBolas();
	void crearMenu();
	void crearAccion();
	
public slots:
	void slotTemporizador();
	void slotInformacion();
	void slotPararBolas();
	void slotReboteBolasBolas();
};
#endif

