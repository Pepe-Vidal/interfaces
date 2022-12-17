#include <QVBoxLayout>
#include <QString>
#include <QDebug>
#include <math.h>
#include <QPainter>
#include "dInfoBola.h"

DInfoBola::DInfoBola(QWidget *parent) : QDialog(parent)
{

	lbNombre = new QLabel("Nombre");
	lbVida = new QLabel("Vida");
	lbPosicion = new QLabel("Posicion");
	lbDiametro = new QLabel("Diametro");
	lbVelocidad = new QLabel("Diametro");

	txtNombre = new QLineEdit();

	spnVelocidadX = new QDoubleSpinBox();
	spnVelocidadY = new QDoubleSpinBox();

	horizontalSpacer = new QSpacerItem(80, 80, QSizePolicy::Expanding, QSizePolicy::Minimum);

	layoutInfo = new QVBoxLayout;

	layoutVida = new QHBoxLayout;
	layoutNombre = new QHBoxLayout;
	layoutPosicion = new QHBoxLayout;
	layoutDiametro = new QHBoxLayout;
	layoutVelocidad = new QHBoxLayout;

	layout = new QHBoxLayout;

	layoutInfo->addLayout(layoutNombre);
	layoutInfo->addLayout(layoutVida);
	layoutInfo->addLayout(layoutPosicion);
	layoutInfo->addLayout(layoutDiametro);
	layoutInfo->addLayout(layoutVelocidad);

	layout->addLayout(layoutInfo);
	layout->addItem(horizontalSpacer);

	bolaSel = NULL;

	/*
		QString bolas("Bolas");
		bolas = "Numero de bolas " + QString::number(numBolas);
	lbBolas->setText(bolas);
	lbResolucion->setText(resolucion);
	*/
}
void DInfoBola::actualizarLayout()
{

	if (bolaSel != NULL)
	{

		QString nombre("Mensaje");
		nombre = "Nombre: ";
		lbNombre->setText(nombre);
		txtNombre->setText(bolaSel->nombre);

		connect(txtNombre, SIGNAL(textEdited(QString)),
			   this, SLOT(slotCambiarNombre(QString)));

		QString vida("Mensaje");
		vida = "Vida: " + QString::number(bolaSel->vida);
		lbVida->setText(vida);

		QString pos("Mensaje");
		pos = "Posicion: X " + QString::number(bolaSel->posX) + " Y " + QString::number(bolaSel->posY);
		lbPosicion->setText(pos);

		QString diametro("Mensaje");
		diametro = "Diametro: " + QString::number(bolaSel->diametro);
		lbDiametro->setText(diametro);

		QString velocidad("Mensaje");
		velocidad = "Velocidad: X , Y";
		lbVelocidad->setText(velocidad);
		spnVelocidadX->setValue(fabs(bolaSel->velX));
		spnVelocidadY->setValue(fabs(bolaSel->velY));

		connect(spnVelocidadX, SIGNAL(valueChanged(double)),
			   this, SLOT(slotCambiarVelocidadX(double)));

		connect(spnVelocidadY, SIGNAL(valueChanged(double)),
			   this, SLOT(slotCambiarVelocidadY(double)));

		layoutNombre->addWidget(lbNombre);
		layoutNombre->addWidget(txtNombre);

		layoutVida->addWidget(lbVida);

		layoutPosicion->addWidget(lbPosicion);

		layoutDiametro->addWidget(lbDiametro);

		layoutVelocidad->addWidget(lbVelocidad);
		layoutVelocidad->addWidget(spnVelocidadX);
		layoutVelocidad->addWidget(spnVelocidadY);

		setLayout(layout);
	}
}

void DInfoBola::actualizarBola(Bola *bola)
{

	bolaSel = bola;

	if (bolaSel != NULL)
	{
		qDebug() << "hohohoh31";
		actualizarLayout();
		update();
	}
}
void DInfoBola::paintEvent(QPaintEvent *event)
{
	QPainter pintor(this);

	if (bolaSel != NULL)
	{

		QBrush brush(bolaSel->color);
		pintor.setBrush(brush);

		pintor.drawEllipse(width() - 70, 20, bolaSel->diametro, bolaSel->diametro);
	}
}

void DInfoBola::slotCambiarVelocidadX(double newVelX)
{
	if (bolaSel != NULL)
	{
		if (bolaSel->velX < 0)
		{

			spnVelocidadX->setPrefix("-");
			bolaSel->velX = -newVelX;
		}
		else
		{
			spnVelocidadX->setPrefix("+");
			bolaSel->velX = newVelX;
		}
	}
}
void DInfoBola::slotCambiarVelocidadY(double newVelY)
{

	if (bolaSel != NULL)
	{

		if (bolaSel->velY < 0)
		{

			spnVelocidadY->setPrefix("-");
			bolaSel->velY = -newVelY;
		}
		else
		{
			spnVelocidadY->setPrefix("+");
			bolaSel->velY = newVelY;
		}
	}
}
void DInfoBola::slotCambiarNombre(QString newNombre)
{
	if (bolaSel != NULL)
	{
		bolaSel->nombre = newNombre;
	}
}

void DInfoBola::slotEjemplo()
{
}