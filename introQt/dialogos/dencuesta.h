#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QSlider>


class DEncuesta : public QDialog{

Q_OBJECT

public:

	DEncuesta(QWidget *parent = nullptr);

	QLabel *label1;
	QLabel *label2;
	QPushButton *btnSi;
	QPushButton *btnNo;
	QSlider *slider;
	
public slots: 

	void slotMierda();
	void slotSliderResultado(int);


};
