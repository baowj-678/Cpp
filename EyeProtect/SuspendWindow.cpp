#include "SuspendWindow.h"
#include <qevent.h>
#include <qdebug.h>

SuspendWindow::SuspendWindow(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	this->setWindowOpacity(0.5);
	this->hiddenTime = new QTimer();
	this->updateTime = new QTimer();
	connect(this->hiddenTime, SIGNAL(timeout()), this, SLOT(LeaveRec()));
	connect(this->updateTime, SIGNAL(timeout()), this, SLOT(LeaveRec()));
	this->setBackground("D:/o.jpg");
	this->setWindowFlags(Qt::FramelessWindowHint);
	//this->setWindowFlags(Qt::CustomizeWindowHint);
	this->setTime("", "");
	this->m_isWindowMoveable = false;
}

SuspendWindow::~SuspendWindow()
{
}

void SuspendWindow::mouseMoveEvent(QMouseEvent* event)
{
	if (this->m_isWindowMoveable)
	{
		int dx = event->globalPos().x() - this->m_point.x();
		int dy = event->globalPos().y() - this->m_point.y();
		this->m_point = event->globalPos();
		this->move(this->x() + dx, this->y() + dy);
	}
	this->setWindowOpacity(0.5);
	this->hiddenTime->start(1000);
}

void SuspendWindow::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton && this->m_isWindowMoveable == false)
	{
		this->m_isWindowMoveable = true;
		this->m_point = event->globalPos();
	}
}

void SuspendWindow::mouseReleaseEvent(QMouseEvent* event)
{
	this->m_isWindowMoveable = false;
}

void  SuspendWindow::LeaveRec()
{
	this->setWindowOpacity(0.3);
	this->hiddenTime->stop();
}

void SuspendWindow::setBackground(QString path)
{
	QPixmap pixmap = QPixmap(path).scaled(this->size());
	QPalette palette(this->palette());
	palette.setBrush(QPalette::Background, QBrush(pixmap));
	this->setPalette(palette);
}

void SuspendWindow::setTime(QString minute, QString second)
{
	this->ui.lcdNumber->display(90);
}