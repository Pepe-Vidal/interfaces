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
#include <QListWidget>
#include <QStringList>

class DTransferencia : public QDialog{

Q_OBJECT

public:

	DTransferencia(QStringList,QWidget *parent = nullptr);
	QComboBox *cmbDestino;
	QLabel *lbDestino , *lbCant, *lbComision;
	QPushButton *btnAceptar;
	QPushButton *btnCancelar;
	QLineEdit *txtDestino, *txtCantidad;
	QListWidget *liswDestino;
	
	void setCuentas(QStringList);
	

public slots: 

	void slotActualizarBoton(const QString &);
	void slotActualizarComision(const QString &);
	void slotAceptar();
	//void slotSliderResultado(int);

signals:

	void senyalTransferenciaOrdenada(float, QString);

};

#endif 
