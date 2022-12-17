#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

#include "dencuesta.h"

DEncuesta::DEncuesta(QWidget *parent): QDialog(parent)
{

	resize(200,200);

	//Declarar los widgets
	QPushButton *btnSi = new QPushButton("Si");
	QPushButton *btnNo = new QPushButton("No");
	label1 = new QLabel("¿Te gusta este modulo?");
	label2 = new QLabel("Hola");
	slider = new QSlider(Qt::Horizontal);
	
	slider->setRange(0, 10);
	
	//Declarar los layout
	QVBoxLayout *layoutSecundario1 = new QVBoxLayout;
	QHBoxLayout *layoutSecundario2 = new QHBoxLayout;
	QVBoxLayout *layoutPrincipal = new QVBoxLayout;
		
                     
	connect(btnSi, SIGNAL(clicked()),
		this, SLOT(accept()));
	
	connect(btnNo, SIGNAL(clicked()),
		this, SLOT(slotMierda()));
		
	connect(slider, SIGNAL(valueChanged(int)),
		this, SLOT(slotSliderResultado(int)));
	
	//Añadir widgets a layout
	layoutSecundario1->addWidget(label1);
	layoutSecundario1->addWidget(label2);
	layoutSecundario1->addWidget(slider);
	
	layoutSecundario2->addWidget(btnSi);
	layoutSecundario2->addWidget(btnNo);
	
	//Añadir layout a layoutPrincipal
	layoutPrincipal->addLayout(layoutSecundario1);
	layoutPrincipal->addLayout(layoutSecundario2);
	
	//Añador LayoutPrincipal al QDialog
	setLayout(layoutPrincipal);
	
	

}

void DEncuesta::slotMierda(){

	label1->setText("Esto es una mierda");

}
void DEncuesta::slotSliderResultado(int num){

	label2->setText("Esto es una mierda");

}

