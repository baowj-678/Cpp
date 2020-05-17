#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Gobang.h"

class Gobang : public QMainWindow
{
	Q_OBJECT

public:
	Gobang(QWidget *parent = Q_NULLPTR);

private:
	Ui::GobangClass ui;
};
