#include "Gobang.h"
#include <qpainter.h>
#include <qevent.h>
#include <qdebug.h>
#include <qpen>

Gobang::Gobang(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

    QPoint point(100, 100);
    drawChessman(game.getPlayerOne(), &point);
    // 创建 pixmap
    //QPixmap pixmap = QPixmap(100, 100);
    //pixmap.fill(Qt::gray);
    //QPainter painter(&pixmap);
    //painter.drawRect(10, 10, 80, 80);
    //painter.drawText(20, 30, "Hello World");

    // 使用 pixmap
    //ui.label->setPixmap(pixmap);
}

/**
* @brief 鼠标点击事件响应
* @param event  鼠标事件
*
* @return void
*/
void Gobang::mousePressEvent(QMouseEvent* event)
{
    qDebug() << event->x() << " " << event->y() << "\n";
}


/**
* @brief    绘制棋子
* @param player 下该步的玩家
* @param point  绘制该步棋的像素坐标
*
* @return void
*/
void Gobang::drawChessman(Player* player, QPoint* point)
{
    this->update();
}


/**
* @brief    绘图事件调用
* @param event  绘图事件
* @return void
*/
void Gobang::paintEvent(QPaintEvent* event)
{
    QPainter painter(this->ui.board);
    QPen pen;

    pen.setColor(Qt::black);
    pen.setWidth(5);
    painter.drawEllipse(100, 100, 10, 10);
}
// 31 43, 92