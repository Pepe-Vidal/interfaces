#include <QApplication>
#include <QLabel>
#include <QDialog>
#include <QDebug>
#include <unistd.h>

#include "editor.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Editor *editor = new Editor();

    editor->show();


    return app.exec();
}
