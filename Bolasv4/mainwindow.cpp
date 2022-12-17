#include <QPainter>
#include <QBrush>
#include <QColor>
#include <QDebug>
#include <math.h>
#include <QMenu>
#include <QMenuBar>
#include <stdlib.h>
#include "mainwindow.h"

#define NUMBOLAS 5

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{

	QStringList lista = {"Paco", "pepe", "carlos", "Hugo", "antonio"};

	listaNombres = lista;

	velMax = 7;

	resize(800, 600);
	dinformacion = NULL;
	dpararbolas = NULL;
	drebotebolas = NULL;

	crearAccion();
	crearMenu();
	crearBolas();

	temporizador = new QTimer();
	temporizador->setInterval(16);
	temporizador->setSingleShot(false);
	temporizador->start();

	connect(temporizador, SIGNAL(timeout()),
		   this, SLOT(slotTemporizador()));
}

void MainWindow::crearAccion()
{

	accionInformacion = new QAction("Informacion");

	connect(accionInformacion, SIGNAL(triggered()),
		   this, SLOT(slotInformacion()));

	accionPararBolas = new QAction("Prar Bolas");
	connect(accionPararBolas, SIGNAL(triggered()),
		   this, SLOT(slotPararBolas()));

	accionReboteBolas = new QAction("Bolas Rebotes");
	connect(accionReboteBolas, SIGNAL(triggered()),
		   this, SLOT(slotReboteBolasBolas()));
}
void MainWindow::crearMenu()
{

	QMenu *menuArchivo = menuBar()->addMenu("Archivo");

	menuArchivo->addAction(accionInformacion);
	menuArchivo->addAction(accionPararBolas);
	menuArchivo->addAction(accionReboteBolas);
}
void MainWindow::crearBolas()
{

	for (int i = 0; i < NUMBOLAS; i++)
	{

		float posX = random() % width();
		float posY = random() % height();

		float velX = (float)(rand() % 100) / 50 - 1;
		float velY = (float)(rand() % 100) / 50 - 1;

		Bola *nueva = new Bola(posX, posY, velX, velY);

		nueva->nombre = listaNombres.at(i % listaNombres.size());
		bolas.append(nueva);
	}

	jugador = new Bola(100, 100, 0, 0);
	jugador->nombre = "PEPE";
	jugador->color = QColor(255, 255, 255);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{

	int tecla = event->key();

	if (tecla == Qt::Key_Left)
	{

		jugador->velX -= 0.1;
	}
	if (tecla == Qt::Key_Right)
	{

		jugador->velX += 0.1;
	}
	if (tecla == Qt::Key_Up)
	{

		jugador->velY -= 0.1;
	}
	if (tecla == Qt::Key_Down)
	{

		jugador->velY += 0.1;
	}
}

void MainWindow::paintEvent(QPaintEvent *event)
{
	QPainter pintor(this);

	for (int i = 0; i < bolas.size(); i++)
	{

		bolas.at(i)->pintar(pintor);
	}
	jugador->pintar(pintor);
}

void MainWindow::slotTemporizador()
{

	int anchura = width();
	int altura = height();

	for (int i = 0; i < bolas.size(); i++)
	{
		for (int j = 0; j < bolas.size(); j++)
		{

			if (i != j)
			{
				if (bolas.at(i)->chocar(bolas.at(j)))
				{

					qDebug() << "hola" << i << j;

					if (bolas.at(i)->vida - 15 <= 0)
					{
						bolas.at(i)->vida = 0;
					}
					else
					{
						bolas.at(i)->vida -= 15;
					}

					if (bolas.at(j)->vida - 15 <= 0)
					{
						bolas.at(j)->vida = 0;
					}
					else
					{
						bolas.at(j)->vida -= 15;
					}
				}
			}
		}

		if (jugador->chocar(bolas.at(i)))
		{

			if (jugador->vida - 15 <= 0)
			{
				jugador->vida = 0;
			}
			else
			{
				jugador->vida -= 15;
			}
			if (bolas.at(i)->vida - 15 <= 0)
			{
				bolas.at(i)->vida = 0;
			}
			else
			{
				bolas.at(i)->vida -= 15;
			}
		}
	}

	for (int i = 0; i < bolas.size(); i++)
	{

		bolas.at(i)->mover(width(), height());
	}

	jugador->mover(width(), height());

	update();
}

void MainWindow::slotPararBolas()
{

	if (dpararbolas == NULL)
	{
		dpararbolas = new DPararBolas(&bolas);
	}

	dpararbolas->show();
}

void MainWindow::slotReboteBolasBolas()
{

	if (drebotebolas == NULL)
	{
		drebotebolas = new DRebotes(jugador);
	}

	drebotebolas->show();
}

void MainWindow::slotInformacion()
{

	if (dinformacion == NULL)
	{
		dinformacion = new DInformacion(width(), height(), bolas.size());
	}

	dinformacion->show();
}
