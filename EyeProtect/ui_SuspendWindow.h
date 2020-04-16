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
#include <QtWidgets/QLCDNumber>

QT_BEGIN_NAMESPACE

class Ui_SuspendWindow
{
public:
    QLCDNumber *lcdNumber;

    void setupUi(QDialog *SuspendWindow)
    {
        if (SuspendWindow->objectName().isEmpty())
            SuspendWindow->setObjectName(QString::fromUtf8("SuspendWindow"));
        SuspendWindow->resize(271, 377);
        SuspendWindow->setMouseTracking(true);
        SuspendWindow->setStyleSheet(QString::fromUtf8(""));
        lcdNumber = new QLCDNumber(SuspendWindow);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(40, 20, 201, 121));
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
    } // retranslateUi

};

namespace Ui {
    class SuspendWindow: public Ui_SuspendWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUSPENDWINDOW_H
