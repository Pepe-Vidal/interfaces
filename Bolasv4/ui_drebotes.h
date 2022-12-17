/********************************************************************************
** Form generated from reading UI file 'drebotes.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DREBOTES_H
#define UI_DREBOTES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>

QT_BEGIN_NAMESPACE

class Ui_DRebotes
{
public:
    QDialogButtonBox *buttonBox;
    QFrame *frame;

    void setupUi(QDialog *DRebotes)
    {
        if (DRebotes->objectName().isEmpty())
            DRebotes->setObjectName(QString::fromUtf8("DRebotes"));
        DRebotes->resize(400, 300);
        buttonBox = new QDialogButtonBox(DRebotes);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        frame = new QFrame(DRebotes);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(49, 20, 321, 201));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        retranslateUi(DRebotes);
        QObject::connect(buttonBox, SIGNAL(accepted()), DRebotes, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DRebotes, SLOT(reject()));

        QMetaObject::connectSlotsByName(DRebotes);
    } // setupUi

    void retranslateUi(QDialog *DRebotes)
    {
        DRebotes->setWindowTitle(QCoreApplication::translate("DRebotes", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DRebotes: public Ui_DRebotes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DREBOTES_H
