#include <QHBoxLayout>
#include "dinicio.h"
#include "dtransferencia.h"

DInicio::DInicio(QWidget *parent): QDialog(parent)
{

	btnLanzar = new QPushButton("Aceptar");

	QHBoxLayout *layout = new QHBoxLayout;
	layout->addWidget(btnLanzar);
	setLayout(layout);
	
	dtrans = NULL;
	
	connect(btnLanzar, SIGNAL(clicked()),
		this, SLOT(slotAbrirDialogo()));

}

void DInicio::slotAbrirDialogo(){

	if(dtrans == NULL)
		dtrans = new DTransferencia();
		
	dtrans->show();
	
	
}


