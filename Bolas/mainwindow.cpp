#include <QPainter>
#include <QBrush>
#include <QColor>
#include <QDebug>
#include <math.h>
#include <QMenu>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QMenuBar>
#include <QAction>
#include <QVariant>
#include <stdlib.h>
#include "mainwindow.h"

#define NUMBOLAS 5

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{

	//QStringList lista = {"Paco", "pepe", "carlos", "Hugo", "antonio"};
	
	
	QFile fichero("./nombres.txt");
	
	if(!fichero.exists()){
	
		QString ruta = QFileDialog::getOpenFileName(this, QString("Selecciona archivo de nombres"), ".", QString("Fichero de texto (*.txt )"));
		
		fichero.setFileName(ruta);
	
	}
	

	if (!fichero.open(QIODevice::ReadOnly))
	{
		QMessageBox::warning(this, tr("Editor"),
						 tr("Cannot read file %1:\n%2.")
							.arg(fichero.fileName())
							.arg(fichero.errorString()));

	}
	
	
	QTextStream stream(&fichero);
	

	while (!stream.atEnd())
	{
		listaNombres.append(stream.readLine());
	}

	//listaNombres = lista;

	velMax = 7;

	setWindowTitle("Bolas-Examen Jose Vidal Castells");
	resize(800, 600);
	dinformacion = NULL;
	dpararbolas = NULL;
	dconfigbola = NULL;
	dconfigtodasbolas= NULL;
	dconfigvisualbolas=NULL;
	dconfvelocidades = NULL;

	crearBolas();
	crearAccion();
	crearMenu();

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

	accionConfigBolas = new QAction("Configurar");
	connect(accionConfigBolas, SIGNAL(triggered()),
		   this, SLOT(slotConfigTodasBolas()));
		   
	accionVonfigVisualBolas = new QAction("Config Visual");
	connect(accionVonfigVisualBolas, SIGNAL(triggered()),
		   this, SLOT(slotConfVisualBolas()));
		   
	accionConfVelocidades = new QAction("Config Velocidades");
	connect(accionConfVelocidades, SIGNAL(triggered()),
		   this, SLOT(slotConfVelocidades()));


}
void MainWindow::crearMenu()
{

	QMenu *menuArchivo = menuBar()->addMenu("Archivo");
	menuConfigBolas = menuBar()->addMenu("Nombres");
	QMenu *menuConfigTodasBolas = menuBar()->addMenu("Configuracion Bolas");
	
	menuArchivo->addAction(accionInformacion);
	menuArchivo->addAction(accionPararBolas);
	
	menuConfigTodasBolas->addAction(accionConfigBolas);
	
	menuConfigTodasBolas->addAction(accionVonfigVisualBolas);
	menuConfigTodasBolas->addAction(accionConfVelocidades);
	
	for (int i = 0; i < NUMBOLAS; i++)
	{
	
	QVariant pos = QVariant(i);
	QAction * accionconfigbola = new QAction(bolas.at(i)->nombre);
	
	accionconfigbola->setData(pos);
	
	connect(accionconfigbola, SIGNAL(triggered()),
		   this, SLOT(slotConfigBola()));
	
	menuConfigBolas->addAction(accionconfigbola);
	}
	
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
void MainWindow::mousePressEvent(QMouseEvent *event)
{
	int x = event->x();
	int y = event->y();


	for (int i = 0; i < bolas.size(); i++)
	{

		if (bolas.at(i) != NULL)
		{
			if (bolas.at(i)->isSeleccionada(x, y))
			{
				qDebug() << "Bola" << bolas.at(i)->nombre << " Seleccionada " << x << y;
				
			}
		}
	}

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

void MainWindow::slotConfigBola()
{

	QObject *oEmisor = sender();
	QAction *accionCulpable = qobject_cast<QAction *>(oEmisor);
	
	int i = accionCulpable->data().toInt();
	
	if (dconfigbola == NULL)
	{
		
	
		dconfigbola = new DConfigBola(bolas.at(i));
	}

	dconfigbola->show();
}

void MainWindow::slotConfigTodasBolas(){

if (dconfigtodasbolas == NULL)
	{
		dconfigtodasbolas = new DConfigTodasBolas(bolas);
	}

	dconfigtodasbolas->show();
}

void MainWindow::slotPararBolas()
{

	if (dpararbolas == NULL)
	{
		dpararbolas = new DPararBolas(&bolas);
	}

	dpararbolas->show();
}

void MainWindow::slotConfVisualBolas()
{

	if (dconfigvisualbolas == NULL)
	{
		dconfigvisualbolas = new DConfVisualBolas(&bolas);
	}

	dconfigvisualbolas->show();
}
void MainWindow::slotInformacion()
{

	if (dinformacion == NULL)
	{
		dinformacion = new DInformacion(width(), height(), bolas.size());
	}

	dinformacion->show();
}
void MainWindow::slotConfVelocidades()
{

	if (dconfvelocidades == NULL)
	{
		dconfvelocidades = new DConfVelocidades(&bolas);
	}

	dconfvelocidades->show();
}
