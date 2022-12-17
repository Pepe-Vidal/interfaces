#ifndef _DINFOBOLA_H
#define _DINFOBOLA_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPaintEvent>
#include <QSpacerItem>
#include "bola.h"
class DInfoBola : public QDialog
{

	Q_OBJECT

public:
	DInfoBola(QWidget *parent = nullptr);

	Bola *bolaSel;

	QLabel *lbNombre;
	QLabel *lbVida;
	QLabel *lbPosicion;
	QLabel *lbDiametro;
	QLabel *lbVelocidad;

	QDoubleSpinBox *spnVelocidadX;
	QDoubleSpinBox *spnVelocidadY;

	QLineEdit *txtNombre;

	QVBoxLayout *layoutInfo;

	QHBoxLayout *layoutVida;
	QHBoxLayout *layoutNombre;
	QHBoxLayout *layoutPosicion;
	QHBoxLayout *layoutDiametro;
	QHBoxLayout *layoutVelocidad;

	QHBoxLayout *layout;

	QSpacerItem *horizontalSpacer;

	void paintEvent(QPaintEvent *event);
	void actualizarBola(Bola *);
	void actualizarLayout();

public slots:

	void slotEjemplo();
	void slotCambiarNombre(QString);
	void slotCambiarVelocidadX(double);
	void slotCambiarVelocidadY(double);
};

#endif