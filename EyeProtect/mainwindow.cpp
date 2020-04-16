#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_MyButton_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_MyButton_clicked()
{
    
    this->suspendWindow = new SuspendWindow();
    this->suspendWindow->show();
    this->hide();
}



