#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QTimer>
#include <QMenu>
#include <QAction>
#include <QVector>
#include <QKeyEvent>
#include <QMouseEvent>
#include "dinformacion.h"
#include "dInfoBola.h"
#include "bola.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	float velMax;
	QTimer *temporizador;
	QVector<Bola *> bolas;
	MainWindow(QWidget *parent = 0);
	QStringList listaNombres;
	Bola *jugador;
	Bola *bolaInfo;
	DInformacion *dinformacion;
	DInfoBola *dinfobola;
	QAction *accionInformacion;

	void paintEvent(QPaintEvent *event);
	void keyPressEvent(QKeyEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void crearBolas();
	void crearMenu();
	void informacionBola(Bola *);
	void crearAccion();

public slots:
	void slotTemporizador();
	void slotInformacion();
};
#endif
