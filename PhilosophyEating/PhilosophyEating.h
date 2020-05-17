#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PhilosophyEating.h"
#include <stdio.h>
#include <Windows.h>
#define		PHI_NUM		5
#define		CHOPS_NUM	5
#define		CHOPS_AVAIl	-1
#define		PHI_EMPTY	-1



class PhilosophyEating : public QMainWindow
{
	Q_OBJECT

public:
	PhilosophyEating* handle;
	PhilosophyEating(QWidget *parent = Q_NULLPTR);
	//notDeadLockSolution
	QColor color[6];
	QLabel* chops[5];
	QLabel* phis[6];
signals:
	void sendSignal(QLabel* label, QColor c);

public slots:
	void setChopstickToPhi(QLabel* label, QColor c);

private:
	Ui::PhilosophyEatingClass ui;
};


struct info
{
	int id;
	PhilosophyEating* point;
};
typedef struct info Info;
typedef struct info* pInfo;