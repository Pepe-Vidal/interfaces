#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLCDNumber>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QSlider>
#include <QSpinBox>

int main(int argc, char *argv[])
{
     QApplication app(argc, argv);

     QWidget *window = new QWidget;
     window->setWindowTitle("Enter Your Age");

     QSpinBox *spinBox = new QSpinBox;
     QSlider *slider = new QSlider(Qt::Horizontal);
     
     QLabel *label = new QLabel;
     QLineEdit *line = new QLineEdit;
     
     QObject::connect(line, SIGNAL(textChanged(const QString)),
                      label, SLOT(setText(const QString)));
     
     QPushButton *buttonD = new QPushButton("Decimal");
     QPushButton *buttonH = new QPushButton("Exadecimal");

     
     spinBox->setRange(0, 130);
     slider->setRange(0, 130);

     QObject::connect(spinBox, SIGNAL(valueChanged(int)),
                      slider, SLOT(setValue(int)));
     QObject::connect(slider, SIGNAL(valueChanged(int)),
                      spinBox, SLOT(setValue(int)));

     
     QLCDNumber *qLCDNumber= new QLCDNumber();
     
     QObject::connect(spinBox, SIGNAL(valueChanged(int)),
                      qLCDNumber, SLOT(display(int)));
     QObject::connect(slider, SIGNAL(valueChanged(int)),
                      qLCDNumber, SLOT(display(int)));
                      
     spinBox->setValue(35);
     
     
     QObject::connect(buttonD, SIGNAL(clicked()),
                      qLCDNumber, SLOT(setDecMode()));
     QObject::connect(buttonH, SIGNAL(clicked()),
                      qLCDNumber, SLOT(setHexMode()));
                      

	 QHBoxLayout *layout = new QHBoxLayout;
	 
	 QVBoxLayout *layoutV1 = new QVBoxLayout;
	 
	 
	 QVBoxLayout *layoutV2 = new QVBoxLayout; 
	 
	 layoutV2->addWidget(line);
	 layoutV2->addWidget(label);
	 
     QHBoxLayout *layoutPrimero = new QHBoxLayout;
     QHBoxLayout *layoutSegundo = new QHBoxLayout;
     QHBoxLayout *layoutTercero = new QHBoxLayout;
     
     
     layoutSegundo->addWidget(qLCDNumber);
     
     layoutPrimero->addWidget(spinBox);
     layoutPrimero->addWidget(slider);
     
     layoutTercero->addWidget(buttonD);
     layoutTercero->addWidget(buttonH);
     
     
     
     layoutV1->addLayout(layoutPrimero);
     layoutV1->addLayout(layoutSegundo);
     layoutV1->addLayout(layoutTercero);
     
     layout->addLayout(layoutV1);
     layout->addLayout(layoutV2);
     
     window->setLayout(layout);

     window->show();

     return app.exec();
}

