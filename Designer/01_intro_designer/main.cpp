#include <QApplication>
#include <QLabel>
#include <QDialog>
#include <unistd.h>

#include "dprincipal.h"


int main(int argc, char *argv[])
{
     QApplication app(argc, argv);

     DPrincipal *dprincipal = new DPrincipal();
     dprincipal->show();
     
     return app.exec();
     
 }

