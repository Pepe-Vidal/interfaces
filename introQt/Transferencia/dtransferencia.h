#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QSlider>
#include <QLineEdit>
#include <QString>


class DTransferencia : public QDialog{

Q_OBJECT

public:

	DTransferencia(QWidget *parent = nullptr);

	QLabel *lbDestino , *lbCant, *lbComision;
	QPushButton *btnAceptar;
	QPushButton *btnCancelar;
	QLineEdit *txtDestino, *txtCantidad;
	
public slots: 

	void slotActualizarBoton(const QString &);
	void slotActualizarComision(const QString &);
	//void slotSliderResultado(int);


};
