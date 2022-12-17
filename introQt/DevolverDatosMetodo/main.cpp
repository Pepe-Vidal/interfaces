#include <QApplication>
#include <QLabel>
#include <QDialog>
#include <unistd.h>

#include "dtransferencia.h"
#include "dinicio.h"


int main(int argc, char *argv[])
{
     QApplication app(argc, argv);
     
     
     DInicio *dinicio = new DInicio();
     
     
     dinicio->show();
     
     return app.exec();
     
 }

