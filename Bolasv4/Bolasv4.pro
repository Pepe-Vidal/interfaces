######################################################################
# Automatically generated by qmake (3.1) Tue Dec 13 20:32:26 2022
######################################################################

TEMPLATE = app
TARGET = Bolasv4
INCLUDEPATH += .

# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += bola.h \
           dinformacion.h \
           dpararbolas.h \
           drebotes.h \
           mainwindow.h \
           miboton.h \
           ui_dpararbolas.h \
           ui_drebotes.h \
           widgetbordes.h
FORMS += dpararbolas.ui drebotes.ui
SOURCES += bola.cpp \
           dinformacion.cpp \
           dpararbolas.cpp \
           drebotes.cpp \
           main.cpp \
           mainwindow.cpp \
           miboton.cpp \
           widgetbordes.cpp
QT += widgets 