/********************************************************************************
** Form generated from reading UI file 'dconfigtodasbolas.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DCONFIGTODASBOLAS_H
#define UI_DCONFIGTODASBOLAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DConfigTodasBolas
{
public:
    QDialogButtonBox *buttonBox;
    QFrame *frame;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnAnterior;
    QPushButton *btnSiguiente;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *lbNombre;

    void setupUi(QDialog *DConfigTodasBolas)
    {
        if (DConfigTodasBolas->objectName().isEmpty())
            DConfigTodasBolas->setObjectName(QString::fromUtf8("DConfigTodasBolas"));
        DConfigTodasBolas->resize(478, 346);
        buttonBox = new QDialogButtonBox(DConfigTodasBolas);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(100, 290, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        frame = new QFrame(DConfigTodasBolas);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(20, 10, 441, 201));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        widget = new QWidget(DConfigTodasBolas);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 220, 170, 54));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnAnterior = new QPushButton(widget);
        btnAnterior->setObjectName(QString::fromUtf8("btnAnterior"));

        horizontalLayout->addWidget(btnAnterior);

        btnSiguiente = new QPushButton(widget);
        btnSiguiente->setObjectName(QString::fromUtf8("btnSiguiente"));

        horizontalLayout->addWidget(btnSiguiente);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        lbNombre = new QLabel(widget);
        lbNombre->setObjectName(QString::fromUtf8("lbNombre"));

        horizontalLayout_2->addWidget(lbNombre);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(DConfigTodasBolas);
        QObject::connect(buttonBox, SIGNAL(accepted()), DConfigTodasBolas, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DConfigTodasBolas, SLOT(reject()));

        QMetaObject::connectSlotsByName(DConfigTodasBolas);
    } // setupUi

    void retranslateUi(QDialog *DConfigTodasBolas)
    {
        DConfigTodasBolas->setWindowTitle(QCoreApplication::translate("DConfigTodasBolas", "Dialog", nullptr));
        btnAnterior->setText(QCoreApplication::translate("DConfigTodasBolas", "Anterior", nullptr));
        btnSiguiente->setText(QCoreApplication::translate("DConfigTodasBolas", "Siguiente", nullptr));
        label->setText(QCoreApplication::translate("DConfigTodasBolas", "Bola actual:", nullptr));
        lbNombre->setText(QCoreApplication::translate("DConfigTodasBolas", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DConfigTodasBolas: public Ui_DConfigTodasBolas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DCONFIGTODASBOLAS_H
