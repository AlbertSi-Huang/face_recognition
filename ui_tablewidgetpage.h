/********************************************************************************
** Form generated from reading UI file 'tablewidgetpage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLEWIDGETPAGE_H
#define UI_TABLEWIDGETPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TableWidgetPage
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QSpinBox *spinBox;
    QTableWidget *logTabWidget;
    QLabel *label;

    void setupUi(QWidget *TableWidgetPage)
    {
        if (TableWidgetPage->objectName().isEmpty())
            TableWidgetPage->setObjectName(QString::fromUtf8("TableWidgetPage"));
        TableWidgetPage->resize(514, 452);
        pushButton = new QPushButton(TableWidgetPage);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 250, 93, 28));
        pushButton_2 = new QPushButton(TableWidgetPage);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(130, 350, 93, 28));
        pushButton_3 = new QPushButton(TableWidgetPage);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(150, 250, 93, 28));
        pushButton_4 = new QPushButton(TableWidgetPage);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(100, 200, 93, 28));
        pushButton_5 = new QPushButton(TableWidgetPage);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(290, 180, 93, 28));
        spinBox = new QSpinBox(TableWidgetPage);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(240, 230, 91, 22));
        logTabWidget = new QTableWidget(TableWidgetPage);
        logTabWidget->setObjectName(QString::fromUtf8("logTabWidget"));
        logTabWidget->setGeometry(QRect(30, 0, 256, 192));
        label = new QLabel(TableWidgetPage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(270, 330, 72, 15));

        retranslateUi(TableWidgetPage);

        QMetaObject::connectSlotsByName(TableWidgetPage);
    } // setupUi

    void retranslateUi(QWidget *TableWidgetPage)
    {
        TableWidgetPage->setWindowTitle(QApplication::translate("TableWidgetPage", "Form", nullptr));
        pushButton->setText(QApplication::translate("TableWidgetPage", "PushButton", nullptr));
        pushButton_2->setText(QApplication::translate("TableWidgetPage", "PushButton", nullptr));
        pushButton_3->setText(QApplication::translate("TableWidgetPage", "PushButton", nullptr));
        pushButton_4->setText(QApplication::translate("TableWidgetPage", "PushButton", nullptr));
        pushButton_5->setText(QApplication::translate("TableWidgetPage", "PushButton", nullptr));
        label->setText(QApplication::translate("TableWidgetPage", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TableWidgetPage: public Ui_TableWidgetPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLEWIDGETPAGE_H
