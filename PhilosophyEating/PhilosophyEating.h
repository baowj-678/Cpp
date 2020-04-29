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
	PhilosophyEating(QWidget *parent = Q_NULLPTR);

	//notDeadLockSolution


private:
	Ui::PhilosophyEatingClass ui;
};
