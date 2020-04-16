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
    QLabel *label;
    QLCDNumber *lcdNumber;

    void setupUi(QDialog *SuspendWindow)
    {
        if (SuspendWindow->objectName().isEmpty())
            SuspendWindow->setObjectName(QString::fromUtf8("SuspendWindow"));
        SuspendWindow->resize(320, 540);
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
        frame->setGeometry(QRect(0, 0, 320, 540));
        frame->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"    background-color:#ffffff;\n"
"    border:none;\n"
"    border-radius:13px;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 230, 201, 171));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft JhengHei"));
        font1.setPointSize(72);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        lcdNumber = new QLCDNumber(frame);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(30, 30, 191, 121));
        lcdNumber->setLayoutDirection(Qt::LeftToRight);
        lcdNumber->setFrameShape(QFrame::Box);
        lcdNumber->setLineWidth(0);
        lcdNumber->setMidLineWidth(-1);
        lcdNumber->setDigitCount(2);
        lcdNumber->setProperty("value", QVariant(0.000000000000000));

        retranslateUi(SuspendWindow);

        QMetaObject::connectSlotsByName(SuspendWindow);
    } // setupUi

    void retranslateUi(QDialog *SuspendWindow)
    {
        SuspendWindow->setWindowTitle(QCoreApplication::translate("SuspendWindow", "SuspendWindow", nullptr));
        label->setText(QCoreApplication::translate("SuspendWindow", "123", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SuspendWindow: public Ui_SuspendWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUSPENDWINDOW_H
