#ifndef _DTRANSFERENCIA_H
#define _DTRANSFERENCIA_H

#include <QDialog>
#include <QComboBox>
#include <QStringList>
#include <QPushButton>
#include <QLabel>
#include <QSlider>
#include <QLineEdit>
#include <QString>


class DTransferencia : public QDialog{

Q_OBJECT

public:

	DTransferencia(QStringList,QWidget *parent = nullptr);
	QComboBox *cmbDestino;
	QLabel *lbDestino , *lbCant, *lbComision;
	QPushButton *btnAceptar;
	QPushButton *btnCancelar;
	QLineEdit *txtDestino, *txtCantidad;
	
public slots: 

	void slotActualizarBoton(const QString &);
	void slotActualizarComision(const QString &);
	//void slotSliderResultado(int);


};

#endif 
