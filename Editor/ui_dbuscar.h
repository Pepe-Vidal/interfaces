/********************************************************************************
** Form generated from reading UI file 'dbuscar.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBUSCAR_H
#define UI_DBUSCAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DBuscar
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *leBuscar;
    QVBoxLayout *verticalLayout;
    QCheckBox *chMayusculas;
    QCheckBox *chAtras;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btBuscar;
    QPushButton *btCerrar;

    void setupUi(QDialog *DBuscar)
    {
        if (DBuscar->objectName().isEmpty())
            DBuscar->setObjectName(QString::fromUtf8("DBuscar"));
        DBuscar->resize(311, 107);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DBuscar->sizePolicy().hasHeightForWidth());
        DBuscar->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(DBuscar);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(DBuscar);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        leBuscar = new QLineEdit(DBuscar);
        leBuscar->setObjectName(QString::fromUtf8("leBuscar"));

        horizontalLayout->addWidget(leBuscar);


        verticalLayout_3->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        chMayusculas = new QCheckBox(DBuscar);
        chMayusculas->setObjectName(QString::fromUtf8("chMayusculas"));

        verticalLayout->addWidget(chMayusculas);

        chAtras = new QCheckBox(DBuscar);
        chAtras->setObjectName(QString::fromUtf8("chAtras"));

        verticalLayout->addWidget(chAtras);


        verticalLayout_3->addLayout(verticalLayout);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        btBuscar = new QPushButton(DBuscar);
        btBuscar->setObjectName(QString::fromUtf8("btBuscar"));

        verticalLayout_2->addWidget(btBuscar);

        btCerrar = new QPushButton(DBuscar);
        btCerrar->setObjectName(QString::fromUtf8("btCerrar"));

        verticalLayout_2->addWidget(btCerrar);


        horizontalLayout_2->addLayout(verticalLayout_2);


        retranslateUi(DBuscar);

        QMetaObject::connectSlotsByName(DBuscar);
    } // setupUi

    void retranslateUi(QDialog *DBuscar)
    {
        DBuscar->setWindowTitle(QCoreApplication::translate("DBuscar", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DBuscar", "Buscar :", nullptr));
        chMayusculas->setText(QCoreApplication::translate("DBuscar", "Mayusculas/Minusculas", nullptr));
        chAtras->setText(QCoreApplication::translate("DBuscar", "Hacia Atras", nullptr));
        btBuscar->setText(QCoreApplication::translate("DBuscar", "Buscar", nullptr));
        btCerrar->setText(QCoreApplication::translate("DBuscar", "Cerrar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DBuscar: public Ui_DBuscar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBUSCAR_H
