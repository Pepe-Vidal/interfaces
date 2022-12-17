#include "widgetconfbola.h"
#include "dconfvisualbolas.h"


DConfVisualBolas::DConfVisualBolas(QVector<Bola*> *bolasPasadas,QWidget *parent): QDialog(parent){

	setupUi(this);
	tabBolas->clear();

	
	for(int i = 0; i < bolasPasadas->size(); i++){
	
		WidgetConfBola *wconfigBolas = new WidgetConfBola(bolasPasadas->at(i));
	
		tabBolas->addTab(wconfigBolas, bolasPasadas->at(i)->nombre);
		
		connect(wconfigBolas, SIGNAL(signalAlgoCambia()),
			this, SLOT(slotVerificar()));
	}
	
	connect(btnTodasCirculo, SIGNAL(clicked()),
			this, SLOT(slotTodasBolas()));
			
	
	
}

void DConfVisualBolas::slotVerificar(){

	for(int i = 0; i < tabBolas->count(); i++){
	
		WidgetConfBola *w = qobject_cast<WidgetConfBola *>(tabBolas->widget(i));
		
		
		if(!w->rbCirculo->isChecked()){
			
			btnTodasCirculo->setEnabled(true);
			return;
		}
		
		btnTodasCirculo->setEnabled(false);
		
	}

}
void DConfVisualBolas::slotTodasBolas(){

	
	for(int i = 0; i < tabBolas->count(); i++){
	
		WidgetConfBola *w = qobject_cast<WidgetConfBola *>(tabBolas->widget(i));
		
		w->rbCirculo->click(); 
	}

}
void DConfVisualBolas::slotEjemplo(){

	
	
}
