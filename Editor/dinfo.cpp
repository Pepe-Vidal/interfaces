#include "dinfo.h"
#include <QDialog>
#include <QDebug>

DInfo::DInfo(QTextDocument *doc, QWidget *parent): QDialog(parent){

	setupUi(this);
	
	documento = doc;
	setFocusPolicy(Qt::ClickFocus);
}
void DInfo::showEvent(QShowEvent *event){

	qDebug() << documento->blockCount();
	qDebug() << documento->lineCount();
	
	QString numLineas = QString::number(documento->lineCount());
	lLineas->setText(numLineas);
	
}
void DInfo::focusInEvent(QFocusEvent *event){

	qDebug() << documento->blockCount();
	qDebug() << documento->lineCount();
	
	QString numLineas = QString::number(documento->lineCount());
	lLineas->setText(numLineas);
}
void DInfo::mostrarNumeroLineas(){

	
	
}
void DInfo::slotTextoModificado(){

	
	qDebug() << documento->blockCount();
	qDebug() << documento->lineCount();
	
	QString numLineas = QString::number(documento->lineCount());
	lLineas->setText(numLineas);
}
