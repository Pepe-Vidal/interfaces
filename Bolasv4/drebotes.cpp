#include <QDialog>
#include <QGridLayout>
#include <QPushButton>
#include <QDebug>
#include <QString>
#include <QLabel>
#include "drebotes.h"
#include "widgetbordes.h"

DRebotes::DRebotes(Bola *bola, QWidget *parent): QDialog(parent){
	setupUi(this);

	WidgetBordes *wdb = new WidgetBordes(bola);
	QVBoxLayout *layout = new QVBoxLayout();

	layout->addWidget(wdb);

	frame->setLayout(layout);

}
void DRebotes::slotEjemplo(){

	
	
}
