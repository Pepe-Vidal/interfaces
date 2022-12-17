#include <QVBoxLayout>
#include <QString>
#include "dinformacion.h"

DInformacion::DInformacion(int anchura,int altura ,int numBolas,QWidget *parent): QDialog(parent)
{

	lbResolucion = new QLabel("Resolucion");
	lbBolas = new QLabel("Bolas");
	
	QString bolas("Bolas");
	bolas = "Numero de bolas " + QString::number(numBolas);
	
	QString resolucion("Resolucion");
	resolucion = "Resolucion de la pantalla " + QString::number(anchura)+ "x" +  QString::number(altura);
	
	lbBolas->setText(bolas);
	lbResolucion->setText(resolucion);
	
	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(lbResolucion);
	layout->addWidget(lbBolas);
	
	setLayout(layout);

}
void DInformacion::slotEjemplo(){

	
	
}
