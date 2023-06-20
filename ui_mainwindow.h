/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QLabel *labSuccess;
    QLabel *labHelmet;
    QLabel *label_13;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *labMo;
    QLabel *label_12;
    QLabel *labCoat;
    QLabel *label_14;
    QLabel *labTotal;
    QWidget *widgetTop;
    QLabel *labTime;
    QLabel *label_3;
    QLabel *label;
    QWidget *widget_11;
    QLabel *labTemp;
    QLabel *labGongZ;
    QLabel *labName;
    QLabel *labCompany;
    QLabel *labGroup;
    QLabel *label_4;
    QWidget *widget_4;
    QLabel *label_6;
    QWidget *widget_5;
    QPushButton *btnPlate;
    QPushButton *btnRecord;
    QPushButton *btnSetting;
    QLabel *label_5;
    QLabel *label_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1080, 1920);
        MainWindow->setMinimumSize(QSize(1080, 1920));
        MainWindow->setMaximumSize(QSize(1080, 1920));
        MainWindow->setStyleSheet(QString::fromUtf8("QHeaderView::section,QTableCornerButton:section\n"
"{\n"
"    text-align:center;\n"
"    padding:3px;\n"
"    margin:0px;\n"
"    color:#DCDCDC;\n"
"    border:1px solid #242424;\n"
"    border-left-width:0px;\n"
"    border-right-width:1px;\n"
"    border-top-width:0px;\n"
"     border-bottom-width:1px;\n"
"    background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #646464,stop:1 #525252);\n"
" }"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("background-color: rgb(49, 54, 61);"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 1080, 1920));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        widget->setFont(font);
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(49, 54, 61);"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(547, 425, 503, 225));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(17, 134, 243);\n"
"border-radius: 13px;"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labSuccess = new QLabel(widget_2);
        labSuccess->setObjectName(QString::fromUtf8("labSuccess"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        labSuccess->setFont(font1);
        labSuccess->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        labSuccess->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labSuccess, 0, 0, 1, 1);

        labHelmet = new QLabel(widget_2);
        labHelmet->setObjectName(QString::fromUtf8("labHelmet"));
        labHelmet->setFont(font1);
        labHelmet->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 255, 255);"));
        labHelmet->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labHelmet, 0, 4, 1, 1);

        label_13 = new QLabel(widget_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Agency FB"));
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(9);
        label_13->setFont(font2);
        label_13->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Agency FB\";\n"
"color: rgb(255, 255, 255);"));
        label_13->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_13, 1, 4, 1, 1);

        label_10 = new QLabel(widget_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Agency FB\";\n"
"color: rgb(255, 255, 255);"));
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_10, 1, 0, 1, 1);

        label_11 = new QLabel(widget_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font2);
        label_11->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Agency FB\";\n"
"color: rgb(255, 255, 255);"));
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_11, 1, 1, 1, 1);

        labMo = new QLabel(widget_2);
        labMo->setObjectName(QString::fromUtf8("labMo"));
        labMo->setFont(font1);
        labMo->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        labMo->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labMo, 0, 1, 1, 1);

        label_12 = new QLabel(widget_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Agency FB\";\n"
"color: rgb(255, 255, 255);"));
        label_12->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_12, 1, 2, 1, 1);

        labCoat = new QLabel(widget_2);
        labCoat->setObjectName(QString::fromUtf8("labCoat"));
        labCoat->setFont(font1);
        labCoat->setStyleSheet(QString::fromUtf8("border-radius: 13px;\n"
"color: rgb(255, 255, 255);"));
        labCoat->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labCoat, 0, 3, 1, 1);

        label_14 = new QLabel(widget_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font2);
        label_14->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Agency FB\";\n"
"color: rgb(255, 255, 255);"));
        label_14->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_14, 1, 3, 1, 1);

        labTotal = new QLabel(widget_2);
        labTotal->setObjectName(QString::fromUtf8("labTotal"));
        labTotal->setFont(font1);
        labTotal->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        labTotal->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labTotal, 0, 2, 1, 1);

        widgetTop = new QWidget(widget);
        widgetTop->setObjectName(QString::fromUtf8("widgetTop"));
        widgetTop->setGeometry(QRect(0, 0, 1920, 103));
        widgetTop->setStyleSheet(QString::fromUtf8("background-color: rgb(88, 96, 101);"));
        labTime = new QLabel(widgetTop);
        labTime->setObjectName(QString::fromUtf8("labTime"));
        labTime->setGeometry(QRect(30, 39, 422, 29));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(16);
        font3.setBold(false);
        font3.setWeight(50);
        labTime->setFont(font3);
        labTime->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        labTime->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 125, 1020, 144));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(18);
        font4.setBold(false);
        font4.setItalic(false);
        font4.setWeight(9);
        label_3->setFont(font4);
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"border-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(0, 0, 0, 255), stop:0.05 rgba(14, 8, 73, 255), stop:0.36 rgba(28, 17, 145, 255), stop:0.6 rgba(126, 14, 81, 255), stop:0.75 rgba(234, 11, 11, 255), stop:0.79 rgba(244, 70, 5, 255), stop:0.86 rgba(255, 136, 0, 255), stop:0.935 rgba(239, 236, 55, 255));\n"
"font: 75 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(241, 100, 30);\n"
"border-radius: 10px;"));
        label_3->setAlignment(Qt::AlignCenter);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(28, 745, 1025, 505));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(80, 83, 87);"));
        widget_11 = new QWidget(widget);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));
        widget_11->setGeometry(QRect(28, 298, 503, 352));
        widget_11->setStyleSheet(QString::fromUtf8("background-color: rgb(86, 86, 86);\n"
"border-radius: 13px;"));
        labTemp = new QLabel(widget_11);
        labTemp->setObjectName(QString::fromUtf8("labTemp"));
        labTemp->setGeometry(QRect(0, 0, 258, 352));
        labTemp->setStyleSheet(QString::fromUtf8("border-radius: 13px;  border:2px solidl;\n"
"border-color: rgb(255, 255, 255);\n"
"background-color: rgb(127, 127, 127);"));
        labGongZ = new QLabel(widget_11);
        labGongZ->setObjectName(QString::fromUtf8("labGongZ"));
        labGongZ->setGeometry(QRect(280, 270, 201, 30));
        labGongZ->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 75 16pt \"Agency FB\";"));
        labName = new QLabel(widget_11);
        labName->setObjectName(QString::fromUtf8("labName"));
        labName->setGeometry(QRect(280, 50, 201, 30));
        labName->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 75 16pt \"Agency FB\";"));
        labCompany = new QLabel(widget_11);
        labCompany->setObjectName(QString::fromUtf8("labCompany"));
        labCompany->setGeometry(QRect(280, 120, 181, 30));
        labCompany->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 75 16pt \"Agency FB\";"));
        labGroup = new QLabel(widget_11);
        labGroup->setObjectName(QString::fromUtf8("labGroup"));
        labGroup->setGeometry(QRect(280, 200, 181, 30));
        labGroup->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 16pt \"Agency FB\";"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(547, 298, 503, 113));
        label_4->setStyleSheet(QString::fromUtf8("font: 75 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 13px;\n"
"background-color: rgb(86, 86, 86);"));
        label_4->setAlignment(Qt::AlignCenter);
        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(28, 672, 1025, 578));
        widget_4->setStyleSheet(QString::fromUtf8("background-color: rgb(60, 71, 78);\n"
"border-radius: 7px;"));
        label_6 = new QLabel(widget_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(26, 28, 174, 29));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 75 20pt \"Source Code Pro\";"));
        widget_5 = new QWidget(widget);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setGeometry(QRect(28, 1301, 1025, 578));
        widget_5->setStyleSheet(QString::fromUtf8("background-color: rgb(60, 71, 78);\n"
"border-radius: 7px;"));
        btnPlate = new QPushButton(widget_5);
        btnPlate->setObjectName(QString::fromUtf8("btnPlate"));
        btnPlate->setGeometry(QRect(870, 20, 93, 28));
        btnPlate->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Source Code Pro\";\n"
"color: rgb(255, 255, 255);"));
        btnRecord = new QPushButton(widget_5);
        btnRecord->setObjectName(QString::fromUtf8("btnRecord"));
        btnRecord->setGeometry(QRect(670, 20, 93, 28));
        btnRecord->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Source Code Pro\";\n"
"color: rgb(255, 255, 255);\n"
""));
        btnSetting = new QPushButton(widget_5);
        btnSetting->setObjectName(QString::fromUtf8("btnSetting"));
        btnSetting->setGeometry(QRect(770, 20, 93, 28));
        btnSetting->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Source Code Pro\";\n"
"color: rgb(255, 255, 255);"));
        label_5 = new QLabel(widget_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(0, 75, 1025, 503));
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgb(80, 83, 87);"));
        label_2 = new QLabel(widget_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(24, 29, 236, 29));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Source Code Pro"));
        font5.setPointSize(20);
        label_2->setFont(font5);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        widget_2->raise();
        widgetTop->raise();
        label_3->raise();
        widget_11->raise();
        label_4->raise();
        widget_4->raise();
        label->raise();
        widget_5->raise();
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        labSuccess->setText(QApplication::translate("MainWindow", "0", nullptr));
        labHelmet->setText(QString());
        label_13->setText(QApplication::translate("MainWindow", "\345\256\211\345\205\250\345\270\275", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "\345\275\223\345\244\251\346\257\224\345\257\271", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "\351\231\214\347\224\237\344\272\272", nullptr));
        labMo->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "\346\200\273\344\272\272\346\225\260", nullptr));
        labCoat->setText(QString());
        label_14->setText(QApplication::translate("MainWindow", "\345\217\215\345\205\211\350\241\243", nullptr));
        labTotal->setText(QApplication::translate("MainWindow", "0", nullptr));
        labTime->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "\344\270\255\345\273\272\344\270\211\345\261\200\344\270\200\345\205\254\345\217\270\345\273\272\347\255\221\350\256\276\350\256\241\351\231\242", nullptr));
        label->setText(QString());
        labTemp->setText(QString());
        labGongZ->setText(QApplication::translate("MainWindow", "\345\267\245\347\247\215\357\274\232", nullptr));
        labName->setText(QApplication::translate("MainWindow", "\345\247\223\345\220\215\357\274\232", nullptr));
        labCompany->setText(QApplication::translate("MainWindow", "\345\205\254\345\217\270\357\274\232", nullptr));
        labGroup->setText(QApplication::translate("MainWindow", "\347\217\255\347\273\204\357\274\232", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\346\226\260\346\261\237\346\271\276-FD\345\234\260\345\235\227\345\225\206\345\212\236\351\241\271\347\233\256", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "AI\351\255\224\345\261\217", nullptr));
        btnPlate->setText(QApplication::translate("MainWindow", "\345\271\263\345\217\260", nullptr));
        btnRecord->setText(QApplication::translate("MainWindow", "\345\216\206\345\217\262\350\256\260\345\275\225", nullptr));
        btnSetting->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        label_5->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "\344\270\255\345\273\272\344\270\211\345\261\200\342\200\224\345\205\254\345\217\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
