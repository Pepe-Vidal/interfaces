/********************************************************************************
** Form generated from reading UI file 'widgetconfvelocidad.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETCONFVELOCIDAD_H
#define UI_WIDGETCONFVELOCIDAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetConfVelocidad
{
public:
    QSlider *slHorizontal;
    QSlider *slVertical;
    QCheckBox *cbColisionar;

    void setupUi(QWidget *WidgetConfVelocidad)
    {
        if (WidgetConfVelocidad->objectName().isEmpty())
            WidgetConfVelocidad->setObjectName(QString::fromUtf8("WidgetConfVelocidad"));
        WidgetConfVelocidad->resize(400, 300);
        slHorizontal = new QSlider(WidgetConfVelocidad);
        slHorizontal->setObjectName(QString::fromUtf8("slHorizontal"));
        slHorizontal->setGeometry(QRect(120, 230, 160, 16));
        slHorizontal->setTracking(true);
        slHorizontal->setOrientation(Qt::Horizontal);
        slHorizontal->setTickPosition(QSlider::TicksBothSides);
        slVertical = new QSlider(WidgetConfVelocidad);
        slVertical->setObjectName(QString::fromUtf8("slVertical"));
        slVertical->setGeometry(QRect(60, 50, 16, 160));
        slVertical->setOrientation(Qt::Vertical);
        slVertical->setTickPosition(QSlider::TicksBothSides);
        cbColisionar = new QCheckBox(WidgetConfVelocidad);
        cbColisionar->setObjectName(QString::fromUtf8("cbColisionar"));
        cbColisionar->setGeometry(QRect(150, 110, 92, 23));

        retranslateUi(WidgetConfVelocidad);

        QMetaObject::connectSlotsByName(WidgetConfVelocidad);
    } // setupUi

    void retranslateUi(QWidget *WidgetConfVelocidad)
    {
        WidgetConfVelocidad->setWindowTitle(QCoreApplication::translate("WidgetConfVelocidad", "Form", nullptr));
        cbColisionar->setText(QCoreApplication::translate("WidgetConfVelocidad", "colisiona", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetConfVelocidad: public Ui_WidgetConfVelocidad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETCONFVELOCIDAD_H
