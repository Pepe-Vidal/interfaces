#include <QGridLayout>
#include <QPushButton>
#include <QDebug>
#include <QString>
#include <QLabel>
#include "widgetbordes.h"

WidgetBordes::WidgetBordes(Bola *bola, QWidget *parent) : QWidget(parent)
{

	temporizador = new QTimer();
	temporizador->setInterval(16);
	temporizador->setSingleShot(false);
	temporizador->start();

	connect(temporizador, SIGNAL(timeout()),
		   this, SLOT(slotTemporizador()));

	bolasel = bola;
	QGridLayout *layout = new QGridLayout();

	lbarriba = new QLabel("0");
	lbabajo = new QLabel("0");
	lbderecha = new QLabel("0");
	lbizquierda = new QLabel("0");

	btnarriba = new QPushButton("RESET");
	btnabajo = new QPushButton("RESET");
	btnderecha = new QPushButton("RESET");
	btnizquierda = new QPushButton("RESET");

	connect(btnarriba, SIGNAL(clicked()),
		   this, SLOT(slotResetContador()));

	connect(btnabajo, SIGNAL(clicked()),
		   this, SLOT(slotResetContador()));

	connect(btnderecha, SIGNAL(clicked()),
		   this, SLOT(slotResetContador()));

	connect(btnizquierda, SIGNAL(clicked()),
		   this, SLOT(slotResetContador()));

	layout->addWidget(lbarriba, 0, 2);
	layout->addWidget(btnarriba, 1, 2);

	layout->addWidget(lbizquierda, 2, 0);
	layout->addWidget(btnizquierda, 2, 1);

	layout->addWidget(lbderecha, 2, 4);
	layout->addWidget(btnderecha, 2, 5);

	layout->addWidget(lbabajo, 3, 2);
	layout->addWidget(btnabajo, 4, 2);

	setLayout(layout);
}
void WidgetBordes::slotResetContador()
{

	QObject *oEmisor = sender();
	QPushButton *botonCulpable = qobject_cast<QPushButton *>(oEmisor);

	if (btnabajo == botonCulpable)
	{
		lbabajo->setText("0");
		bolasel->rebotes[Bola::ABAJO] = 0;
	}
	if (btnarriba == botonCulpable)
	{
		lbarriba->setText("0");
		bolasel->rebotes[Bola::ARRIBA] = 0;
	}
	if (btnderecha == botonCulpable)
	{
		lbderecha->setText("0");
		bolasel->rebotes[Bola::DERECHA] = 0;
	}
	if (btnizquierda == botonCulpable)
	{
		lbizquierda->setText("0");
		bolasel->rebotes[Bola::IZQUIERDA] = 0;
	}

	qDebug() << "Hoal";
}
void WidgetBordes::slotTemporizador()
{

	QString info("0");

	info = QString::number(bolasel->rebotes[Bola::ABAJO]);

	lbabajo->setText(info);

	info = QString::number(bolasel->rebotes[Bola::ARRIBA]);

	lbarriba->setText(info);

	info = QString::number(bolasel->rebotes[Bola::DERECHA]);

	lbderecha->setText(info);

	info = QString::number(bolasel->rebotes[Bola::IZQUIERDA]);

	lbizquierda->setText(info);

	update();
}
void WidgetBordes::slotEjemplo()
{
}
