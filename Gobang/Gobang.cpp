#include "Gobang.h"
#include <qpainter.h>

Gobang::Gobang(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

    // 创建 pixmap
    QPixmap pixmap = QPixmap(100, 100);
    pixmap.fill(Qt::gray);
    QPainter painter(&pixmap);
    painter.drawRect(10, 10, 80, 80);
    painter.drawText(20, 30, "Hello World");

    // 使用 pixmap
    //ui.label->setPixmap(pixmap);
}
