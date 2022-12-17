#include <QVBoxLayout>
#include <QStringList>
#include "dinicio.h"
#include "dtransferencia.h"

DInicio::DInicio(QWidget *parent): QDialog(parent)
{

	btnLanzar = new QPushButton("Aceptar");

	QVBoxLayout *layout = new QVBoxLayout;
	
	lbtransferencia = new QLabel("Listo para la transferencia");
	
	QStringList l = {"999999","555555","888888","444444","222222"};
	listaCuentas = l;
	
	layout->addWidget(btnLanzar);
	layout->addWidget(lbtransferencia);
	setLayout(layout);
	
	dtrans = NULL;
	
	connect(btnLanzar, SIGNAL(clicked()),
		this, SLOT(slotAbrirDialogo()));

	
}

void DInicio::slotAbrirDialogo(){

	if(dtrans == NULL){
		dtrans = new DTransferencia(listaCuentas);
		
	connect(dtrans, SIGNAL(accepted()),
		this, SLOT(slotListoTrans()));
		
	connect(dtrans, SIGNAL(rejected()),
		this, SLOT(slotRecTrans()));
		
		}
		
	dtrans->show();
	
}
void DInicio::slotListoTrans(){


	lbtransferencia->setText("Transferencia aceptada");

}
void DInicio::slotRecTrans(){


	lbtransferencia->setText("Transferencia denegada");
	
}

