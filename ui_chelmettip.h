/********************************************************************************
** Form generated from reading UI file 'chelmettip.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHELMETTIP_H
#define UI_CHELMETTIP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CHelmetTip
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;

    void setupUi(QWidget *CHelmetTip)
    {
        if (CHelmetTip->objectName().isEmpty())
            CHelmetTip->setObjectName(QString::fromUtf8("CHelmetTip"));
        CHelmetTip->resize(400, 300);
        CHelmetTip->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 127);"));
        horizontalLayout = new QHBoxLayout(CHelmetTip);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(CHelmetTip);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 75 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 0, 0);"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);


        retranslateUi(CHelmetTip);

        QMetaObject::connectSlotsByName(CHelmetTip);
    } // setupUi

    void retranslateUi(QWidget *CHelmetTip)
    {
        CHelmetTip->setWindowTitle(QApplication::translate("CHelmetTip", "Form", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CHelmetTip: public Ui_CHelmetTip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHELMETTIP_H
