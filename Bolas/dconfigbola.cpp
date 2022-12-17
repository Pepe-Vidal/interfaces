#include <QDialog>
#include <QVBoxLayout>
#include <QPushButton>
#include <QDebug>
#include <QString>
#include <QLabel>
#include "dconfigbola.h"
#include "bola.h"


DConfigBola::DConfigBola(Bola *bola,QWidget *parent): QDialog(parent){

setWindowTitle("Configuración Bola-Examen Jose Vidal Castells");
	resize(400, 200);
	WidgetConfBola *wconfigBolas = new WidgetConfBola(bola);
	QVBoxLayout *layout = new QVBoxLayout();

	layout->addWidget(wconfigBolas);

	setLayout(layout);


}
void DConfigBola::slotEjemplo(){

	
	
}
