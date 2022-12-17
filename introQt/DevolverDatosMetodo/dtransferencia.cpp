#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QStringList>
#include <QLabel>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

#include "dtransferencia.h"

DTransferencia::DTransferencia(QStringList list, QWidget *parent): QDialog(parent)
{


	//Declarar los widgets
	btnAceptar = new QPushButton("Aceptar");
	btnCancelar = new QPushButton("Cancelar");
	
	btnAceptar->setEnabled(0);
	

	cmbDestino = new QComboBox();
	
	cmbDestino->addItems(list);
	
	liswDestino = new QListWidget();
	
	liswDestino->addItems(list);
	
	lbDestino = new QLabel("Cuenta Destino: ");
	lbCant = new QLabel("Cantidad");
	lbComision = new QLabel("Comisión 0 euros.");
	
	//txtDestino = new QLineEdit();
	txtCantidad = new QLineEdit();

	
	//Declarar los layout
	QVBoxLayout *layoutDer = new QVBoxLayout;
	QVBoxLayout *layoutIzq = new QVBoxLayout;
	
	QHBoxLayout *layoutDestino = new QHBoxLayout;
	QHBoxLayout *layoutCantidad = new QHBoxLayout;
	
	QHBoxLayout *layoutPrincipal = new QHBoxLayout;
		
	
	//Añadir widgets a layout
	layoutDestino->addWidget(lbDestino);
	layoutDestino->addWidget(cmbDestino);
	layoutDestino->addWidget(liswDestino);
	
	layoutCantidad->addWidget(lbCant);
	layoutCantidad->addWidget(txtCantidad);
	
	
	layoutDer->addLayout(layoutDestino);
	layoutDer->addLayout(layoutCantidad);
	layoutDer->addWidget(lbComision);
	
	layoutIzq->addWidget(btnAceptar);
	layoutIzq->addWidget(btnCancelar);
	
	layoutPrincipal->addLayout(layoutDer);
	layoutPrincipal->addLayout(layoutIzq);
	
	//Añador LayoutPrincipal al QDialog
	setLayout(layoutPrincipal);
	
	
	//connect(txtDestino, SIGNAL(textChanged(const QString &)),
		//this, SLOT(slotActualizarBoton(const QString &)));
		
	connect(txtCantidad, SIGNAL(textChanged(const QString &)),
		this, SLOT(slotActualizarBoton(const QString &)));
	
	connect(txtCantidad, SIGNAL(textChanged(const QString &)),
		this, SLOT(slotActualizarComision(const QString &)));
		
	connect(btnAceptar, SIGNAL(clicked()),
		this, SLOT(slotAceptar()));
		
	connect(btnCancelar, SIGNAL(clicked()),
		this, SLOT(reject()));

}

void DTransferencia::setCuentas(QStringList lista){

	cmbDestino->clear();
	cmbDestino->addItems(lista);

}



void DTransferencia::slotAceptar(){

	float cantidad = txtCantidad->text().toFloat();
	QString destino = cmbDestino->currentText();

	emit senyalTransferenciaOrdenada(cantidad,destino);
	accept();

}

void DTransferencia::slotActualizarBoton(const QString & cad ){


QString cadCantidad = txtCantidad->text();
QRegularExpression reCantidad("^\\d+$");

QRegularExpressionMatch mCantidad = reCantidad.match(cadCantidad);

bool cantidadOK = mCantidad.hasMatch();

if(cantidadOK){
	btnAceptar->setEnabled(1);
}else{
	btnAceptar->setEnabled(0);
}


}

void DTransferencia::slotActualizarComision(const QString & cad ){


QString cadCantidad = txtCantidad->text();
float cant = cadCantidad.toFloat();

QString res("la comision es ");
res += QString::number(cant*0.01);
res += " euros";

lbComision->setText(res);

}

float DTransferencia::getCantidad(){

float cant = txtCantidad->text().toFloat();
return cant;

}


QString DTransferencia::getCuenta(){

QString destino = cmbDestino->currentText();
return destino;

}
bool DTransferencia::getCuentas(float &cant, QString &cuenta){


cant = txtCantidad->text().toFloat();
cuenta = cmbDestino->currentText();


}


