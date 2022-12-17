/********************************************************************************
** Form generated from reading UI file 'calculadora.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULADORA_H
#define UI_CALCULADORA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DCalculadora
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLCDNumber *lcdResultado;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QPushButton *bUno;
    QPushButton *bTres;
    QPushButton *bNueve;
    QPushButton *bCero;
    QPushButton *bDos;
    QPushButton *bSiete;
    QPushButton *bComa;
    QPushButton *bOcho;
    QPushButton *bCinco;
    QPushButton *bCuatro;
    QPushButton *bSeis;
    QVBoxLayout *verticalLayout;
    QPushButton *bIgual;
    QPushButton *bSuma;

    void setupUi(QDialog *DCalculadora)
    {
        if (DCalculadora->objectName().isEmpty())
            DCalculadora->setObjectName(QString::fromUtf8("DCalculadora"));
        DCalculadora->resize(400, 300);
        verticalLayout_3 = new QVBoxLayout(DCalculadora);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lcdResultado = new QLCDNumber(DCalculadora);
        lcdResultado->setObjectName(QString::fromUtf8("lcdResultado"));

        verticalLayout_2->addWidget(lcdResultado);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        bUno = new QPushButton(DCalculadora);
        bUno->setObjectName(QString::fromUtf8("bUno"));

        gridLayout->addWidget(bUno, 7, 0, 1, 1);

        bTres = new QPushButton(DCalculadora);
        bTres->setObjectName(QString::fromUtf8("bTres"));

        gridLayout->addWidget(bTres, 7, 2, 1, 1);

        bNueve = new QPushButton(DCalculadora);
        bNueve->setObjectName(QString::fromUtf8("bNueve"));

        gridLayout->addWidget(bNueve, 5, 2, 1, 1);

        bCero = new QPushButton(DCalculadora);
        bCero->setObjectName(QString::fromUtf8("bCero"));

        gridLayout->addWidget(bCero, 8, 0, 1, 2);

        bDos = new QPushButton(DCalculadora);
        bDos->setObjectName(QString::fromUtf8("bDos"));

        gridLayout->addWidget(bDos, 7, 1, 1, 1);

        bSiete = new QPushButton(DCalculadora);
        bSiete->setObjectName(QString::fromUtf8("bSiete"));

        gridLayout->addWidget(bSiete, 5, 0, 1, 1);

        bComa = new QPushButton(DCalculadora);
        bComa->setObjectName(QString::fromUtf8("bComa"));

        gridLayout->addWidget(bComa, 8, 2, 1, 1);

        bOcho = new QPushButton(DCalculadora);
        bOcho->setObjectName(QString::fromUtf8("bOcho"));

        gridLayout->addWidget(bOcho, 5, 1, 1, 1);

        bCinco = new QPushButton(DCalculadora);
        bCinco->setObjectName(QString::fromUtf8("bCinco"));

        gridLayout->addWidget(bCinco, 6, 1, 1, 1);

        bCuatro = new QPushButton(DCalculadora);
        bCuatro->setObjectName(QString::fromUtf8("bCuatro"));

        gridLayout->addWidget(bCuatro, 6, 0, 1, 1);

        bSeis = new QPushButton(DCalculadora);
        bSeis->setObjectName(QString::fromUtf8("bSeis"));

        gridLayout->addWidget(bSeis, 6, 2, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        bIgual = new QPushButton(DCalculadora);
        bIgual->setObjectName(QString::fromUtf8("bIgual"));

        verticalLayout->addWidget(bIgual);

        bSuma = new QPushButton(DCalculadora);
        bSuma->setObjectName(QString::fromUtf8("bSuma"));

        verticalLayout->addWidget(bSuma);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(DCalculadora);

        QMetaObject::connectSlotsByName(DCalculadora);
    } // setupUi

    void retranslateUi(QDialog *DCalculadora)
    {
        DCalculadora->setWindowTitle(QCoreApplication::translate("DCalculadora", "Dialog", nullptr));
        bUno->setText(QCoreApplication::translate("DCalculadora", "1", nullptr));
        bTres->setText(QCoreApplication::translate("DCalculadora", "3", nullptr));
        bNueve->setText(QCoreApplication::translate("DCalculadora", "9", nullptr));
        bCero->setText(QCoreApplication::translate("DCalculadora", "0", nullptr));
        bDos->setText(QCoreApplication::translate("DCalculadora", "2", nullptr));
        bSiete->setText(QCoreApplication::translate("DCalculadora", "7", nullptr));
        bComa->setText(QCoreApplication::translate("DCalculadora", ",", nullptr));
        bOcho->setText(QCoreApplication::translate("DCalculadora", "8", nullptr));
        bCinco->setText(QCoreApplication::translate("DCalculadora", "5", nullptr));
        bCuatro->setText(QCoreApplication::translate("DCalculadora", "4", nullptr));
        bSeis->setText(QCoreApplication::translate("DCalculadora", "6", nullptr));
        bIgual->setText(QCoreApplication::translate("DCalculadora", "=", nullptr));
        bSuma->setText(QCoreApplication::translate("DCalculadora", "+", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DCalculadora: public Ui_DCalculadora {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULADORA_H
