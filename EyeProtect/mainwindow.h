#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "SuspendWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    SuspendWindow* suspendWindow;

private slots:
    void on_MyButton_clicked();
};
#endif // MAINWINDOW_H
