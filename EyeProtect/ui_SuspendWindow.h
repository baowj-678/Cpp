/********************************************************************************
** Form generated from reading UI file 'SuspendWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUSPENDWINDOW_H
#define UI_SUSPENDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_SuspendWindow
{
public:
    QFrame *frame;
    QLCDNumber *lcdMinute;
    QLCDNumber *lcdSecond;
    QLCDNumber *lcdDivide;
    QLabel *label;

    void setupUi(QDialog *SuspendWindow)
    {
        if (SuspendWindow->objectName().isEmpty())
            SuspendWindow->setObjectName(QString::fromUtf8("SuspendWindow"));
        SuspendWindow->resize(310, 540);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(48);
        font.setBold(true);
        font.setWeight(75);
        SuspendWindow->setFont(font);
        SuspendWindow->setMouseTracking(true);
        SuspendWindow->setStyleSheet(QString::fromUtf8(""));
        frame = new QFrame(SuspendWindow);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 310, 540));
        frame->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"	background-color:rgba(255,255,255,255);\n"
"    border:none;\n"
"    border-radius:13px;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        lcdMinute = new QLCDNumber(frame);
        lcdMinute->setObjectName(QString::fromUtf8("lcdMinute"));
        lcdMinute->setGeometry(QRect(30, 80, 251, 121));
        lcdMinute->setLayoutDirection(Qt::LeftToRight);
        lcdMinute->setStyleSheet(QString::fromUtf8("QLCDNumber{background:transparent}"));
        lcdMinute->setFrameShape(QFrame::Box);
        lcdMinute->setLineWidth(4);
        lcdMinute->setMidLineWidth(0);
        lcdMinute->setDigitCount(2);
        lcdMinute->setProperty("value", QVariant(0.000000000000000));
        lcdSecond = new QLCDNumber(frame);
        lcdSecond->setObjectName(QString::fromUtf8("lcdSecond"));
        lcdSecond->setGeometry(QRect(30, 270, 251, 121));
        lcdSecond->setLayoutDirection(Qt::LeftToRight);
        lcdSecond->setStyleSheet(QString::fromUtf8("QLCDNumber{background:transparent}"));
        lcdSecond->setFrameShape(QFrame::Box);
        lcdSecond->setLineWidth(0);
        lcdSecond->setMidLineWidth(-1);
        lcdSecond->setDigitCount(2);
        lcdSecond->setProperty("value", QVariant(0.000000000000000));
        lcdDivide = new QLCDNumber(frame);
        lcdDivide->setObjectName(QString::fromUtf8("lcdDivide"));
        lcdDivide->setGeometry(QRect(25, 130, 251, 121));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(72);
        font1.setBold(true);
        font1.setWeight(75);
        font1.setKerning(true);
        lcdDivide->setFont(font1);
        lcdDivide->setLayoutDirection(Qt::LeftToRight);
        lcdDivide->setStyleSheet(QString::fromUtf8("QLCDNumber{background:transparent;}"));
        lcdDivide->setFrameShape(QFrame::Box);
        lcdDivide->setLineWidth(0);
        lcdDivide->setMidLineWidth(-2);
        lcdDivide->setDigitCount(2);
        lcdDivide->setProperty("value", QVariant(0.000000000000000));
        lcdDivide->setProperty("intValue", QVariant(0));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 64, 171, 371));
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"border:3px solid rgb(0, 0, 0);\n"
"background:transparent;\n"
"}"));
        label->setLineWidth(0);
        label->raise();
        lcdMinute->raise();
        lcdSecond->raise();
        lcdDivide->raise();

        retranslateUi(SuspendWindow);

        QMetaObject::connectSlotsByName(SuspendWindow);
    } // setupUi

    void retranslateUi(QDialog *SuspendWindow)
    {
        SuspendWindow->setWindowTitle(QCoreApplication::translate("SuspendWindow", "SuspendWindow", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SuspendWindow: public Ui_SuspendWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUSPENDWINDOW_H
