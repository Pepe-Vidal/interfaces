#include <QApplication>
#include <QLabel>
#include <QDialog>
#include <unistd.h>

#include "dtransferencia.h"


int main(int argc, char *argv[])
{
     QApplication app(argc, argv);
     
     
     DTransferencia *dialogo = new DTransferencia();
     
     
     dialogo->show();
     
     return app.exec();
     
 }

