/********************************************************************************
** Form generated from reading UI file 'dprincipal.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DPRINCIPAL_H
#define UI_DPRINCIPAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DPrincipal
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *bOpcionA;
    QPushButton *bOpcionB;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *bConsultar;
    QLineEdit *leConsultar;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *checkBox;
    QSpacerItem *verticalSpacer;
    QPlainTextEdit *pteTextoResultado;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *bVerificar;
    QLineEdit *leVerificar;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DPrincipal)
    {
        if (DPrincipal->objectName().isEmpty())
            DPrincipal->setObjectName(QString::fromUtf8("DPrincipal"));
        DPrincipal->resize(400, 300);
        verticalLayout_4 = new QVBoxLayout(DPrincipal);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        bOpcionA = new QPushButton(DPrincipal);
        bOpcionA->setObjectName(QString::fromUtf8("bOpcionA"));

        horizontalLayout->addWidget(bOpcionA);

        bOpcionB = new QPushButton(DPrincipal);
        bOpcionB->setObjectName(QString::fromUtf8("bOpcionB"));

        horizontalLayout->addWidget(bOpcionB);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        bConsultar = new QPushButton(DPrincipal);
        bConsultar->setObjectName(QString::fromUtf8("bConsultar"));

        horizontalLayout_2->addWidget(bConsultar);

        leConsultar = new QLineEdit(DPrincipal);
        leConsultar->setObjectName(QString::fromUtf8("leConsultar"));

        horizontalLayout_2->addWidget(leConsultar);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(verticalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        checkBox = new QCheckBox(DPrincipal);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        verticalLayout_2->addWidget(checkBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_3->addLayout(verticalLayout_2);

        pteTextoResultado = new QPlainTextEdit(DPrincipal);
        pteTextoResultado->setObjectName(QString::fromUtf8("pteTextoResultado"));

        horizontalLayout_3->addWidget(pteTextoResultado);


        verticalLayout_3->addLayout(horizontalLayout_3);


        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        bVerificar = new QPushButton(DPrincipal);
        bVerificar->setObjectName(QString::fromUtf8("bVerificar"));

        horizontalLayout_4->addWidget(bVerificar);

        leVerificar = new QLineEdit(DPrincipal);
        leVerificar->setObjectName(QString::fromUtf8("leVerificar"));

        horizontalLayout_4->addWidget(leVerificar);


        verticalLayout_4->addLayout(horizontalLayout_4);

        buttonBox = new QDialogButtonBox(DPrincipal);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_4->addWidget(buttonBox);


        retranslateUi(DPrincipal);
        QObject::connect(buttonBox, SIGNAL(accepted()), DPrincipal, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DPrincipal, SLOT(reject()));

        QMetaObject::connectSlotsByName(DPrincipal);
    } // setupUi

    void retranslateUi(QDialog *DPrincipal)
    {
        DPrincipal->setWindowTitle(QCoreApplication::translate("DPrincipal", "Dialog", nullptr));
        bOpcionA->setText(QCoreApplication::translate("DPrincipal", "opcion A", nullptr));
        bOpcionB->setText(QCoreApplication::translate("DPrincipal", "opcion B", nullptr));
        bConsultar->setText(QCoreApplication::translate("DPrincipal", "Consultar", nullptr));
        checkBox->setText(QCoreApplication::translate("DPrincipal", "CheckBox", nullptr));
        bVerificar->setText(QCoreApplication::translate("DPrincipal", "Verificar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DPrincipal: public Ui_DPrincipal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DPRINCIPAL_H
