/********************************************************************************
** Form generated from reading UI file 'dexamen.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEXAMEN_H
#define UI_DEXAMEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DExamen
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *cbFichero;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *lPrimeraLinea;
    QLabel *label_3;
    QPushButton *btCargar;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DExamen)
    {
        if (DExamen->objectName().isEmpty())
            DExamen->setObjectName(QString::fromUtf8("DExamen"));
        DExamen->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(DExamen);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(DExamen);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        cbFichero = new QComboBox(DExamen);
        cbFichero->setObjectName(QString::fromUtf8("cbFichero"));

        horizontalLayout->addWidget(cbFichero);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(DExamen);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lPrimeraLinea = new QLabel(DExamen);
        lPrimeraLinea->setObjectName(QString::fromUtf8("lPrimeraLinea"));

        horizontalLayout_2->addWidget(lPrimeraLinea);


        verticalLayout->addLayout(horizontalLayout_2);

        label_3 = new QLabel(DExamen);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        btCargar = new QPushButton(DExamen);
        btCargar->setObjectName(QString::fromUtf8("btCargar"));

        verticalLayout->addWidget(btCargar);


        verticalLayout_2->addLayout(verticalLayout);

        buttonBox = new QDialogButtonBox(DExamen);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(DExamen);
        QObject::connect(buttonBox, SIGNAL(accepted()), DExamen, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DExamen, SLOT(reject()));

        QMetaObject::connectSlotsByName(DExamen);
    } // setupUi

    void retranslateUi(QDialog *DExamen)
    {
        DExamen->setWindowTitle(QCoreApplication::translate("DExamen", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DExamen", "Fichero", nullptr));
        label_2->setText(QCoreApplication::translate("DExamen", "Primera Linea", nullptr));
        lPrimeraLinea->setText(QString());
        label_3->setText(QCoreApplication::translate("DExamen", "Pepe Vidal", nullptr));
        btCargar->setText(QCoreApplication::translate("DExamen", "Cargar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DExamen: public Ui_DExamen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEXAMEN_H
