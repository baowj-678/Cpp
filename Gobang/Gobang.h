#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Gobang.h"
#include "Player.h"
#include "Game.h"

class Gobang : public QMainWindow
{
	Q_OBJECT

public:
	Gobang(QWidget *parent = Q_NULLPTR);

private:
	Ui::GobangClass ui;
	Game game;


private:
	void mousePressEvent(QMouseEvent* event);
	void drawChessman(Player* player, QPoint* point);
	void paintEvent(QPaintEvent* event);
};
