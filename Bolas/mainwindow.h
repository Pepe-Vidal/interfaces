#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QTimer>
#include <QMenu>
#include <QAction>
#include <QVector>
#include <QKeyEvent>
#include "dconfvelocidades.h"
#include "dinformacion.h"
#include "dpararbolas.h"
#include "dconfigbola.h"
#include "dconfigtodasbolas.h"
#include "dconfvisualbolas.h"
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
	
	DConfigBola * dconfigbola;
	DInformacion * dinformacion;
	DPararBolas * dpararbolas;
	DConfigTodasBolas * dconfigtodasbolas;
	DConfVisualBolas * dconfigvisualbolas;
	DConfVelocidades * dconfvelocidades;
	
	QAction * accionInformacion;
	QAction * accionPararBolas;
	QAction * accionConfigBolas;
	QAction * accionVonfigVisualBolas;
	QAction * accionConfVelocidades;

	QMenu *menuConfigBolas;
	
	void paintEvent ( QPaintEvent * event );
	void keyPressEvent(QKeyEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void crearBolas();
	void crearMenu();
	void crearAccion();
	
public slots:
	void slotTemporizador();
	void slotInformacion();
	void slotPararBolas();
	void slotConfigBola();
	void slotConfigTodasBolas();
	void slotConfVisualBolas();
	void slotConfVelocidades();
};
#endif

