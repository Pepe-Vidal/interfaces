#include <QVBoxLayout>
#include <QStringList>
#include <QDebug>
#include "dinicio.h"
#include "dtransferencia.h"

DInicio::DInicio(QWidget *parent): QDialog(parent)
{

	btnLanzar = new QPushButton("Aceptar");
	btnActualizar = new QPushButton("Actualizar");


	QVBoxLayout *layout = new QVBoxLayout;
	
	lbtransferencia = new QLabel("Listo para la transferencia");
	
	QStringList l1 = {"999999","555555","888888","444444","222222"};

	listaCuentas = l1;
	
	layout->addWidget(btnLanzar);
	layout->addWidget(btnActualizar);
	layout->addWidget(lbtransferencia);
	setLayout(layout);
	
	dtrans = NULL;
	
	connect(btnLanzar, SIGNAL(clicked()),
		this, SLOT(slotAbrirDialogo()));
		
	connect(btnActualizar, SIGNAL(clicked()),
		this, SLOT(slotActualizarDialogo()));

	
}
void DInicio::slotActualizarDialogo(){

	if(dtrans != NULL){
		//qDebug() << "Siiii" << 40;
		QStringList nuevalista = {"456321","765438","093452","126785","235487"};
		dtrans->setCuentas(nuevalista);
		
		dtrans->liswDestino->clear();
		dtrans->liswDestino->addItems(nuevalista);
	}
	
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

