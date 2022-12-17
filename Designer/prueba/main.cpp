#include <QApplication>
#include <QLabel>
#include <QDialog>
#include <unistd.h>

#include "dcalculadora.h"


int main(int argc, char *argv[])
{
     QApplication app(argc, argv);

     DCalculadora *dcalculadora = new DCalculadora();
     dcalculadora->show();
     
     return app.exec();
     
 }

