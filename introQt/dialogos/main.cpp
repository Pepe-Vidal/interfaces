#include <QApplication>
#include <QLabel>
#include <QDialog>
#include <unistd.h>

#include "dencuesta.h"


int main(int argc, char *argv[])
{
     QApplication app(argc, argv);
     
     
     DEncuesta *dialogo = new DEncuesta();
     
     
     dialogo->show();
     
     return app.exec();
     
 }

