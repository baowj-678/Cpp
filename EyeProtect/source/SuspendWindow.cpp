#include "SuspendWindow.h"
#include <qevent.h>
#include <Windows.h>
#include <qdebug.h>
#include "qdatetime.h"

#define WORK_TIME	20
#define REST_TIME	3
#define	HIDDEN_SIZE	5

SuspendWindow::SuspendWindow(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	this->initializeWindow();
	this->hiddenTime = new QTimer();
	this->updateTime = new QTimer();
	connect(this->hiddenTime, SIGNAL(timeout()), this, SLOT(hideDialog()));
	connect(this->updateTime, SIGNAL(timeout()), this, SLOT(updateShowTime()));
	this->initializeTime();
	this->update();
}

SuspendWindow::~SuspendWindow()
{
	delete this->hiddenTime;
	delete this->updateTime;
}

void SuspendWindow::mouseMoveEvent(QMouseEvent* event)
{
	if (this->m_isWindowMoveable)
	{
		int dx = event->globalPos().x() - this->m_point.x();
		int dy = event->globalPos().y() - this->m_point.y();
		this->m_point = event->globalPos();
		int rightX = this->x() + dx + this->width();
		int topY = this->y() + dy;
		int bottomY = topY + this->height();
		int leftX = this->x() + dx;

		int newX, newY;
		if (leftX < 0)
			newX = 0;
		else if (rightX > this->s_width)
			newX = this->s_width - this->width();
		else
			newX = this->x() + dx;

		if (topY < -this->height() / 3)
		{
			newY = 0;
			this->backMainWindow(true);
		}
		else if (bottomY > this->s_height)
			newY = this->s_height - this->height();
		else
			newY = this->y() + dy;

		this->move(newX, newY);
	}
}

void SuspendWindow::mousePressEvent(QMouseEvent* event)
{
	//move window
	if (event->button() == Qt::LeftButton && this->m_isWindowMoveable == false)
	{
		this->m_isWindowMoveable = true;
		this->m_point = event->globalPos();
	}
}

void SuspendWindow::mouseDoubleClickEvent(QMouseEvent*)
{
	//pause
	if (this->updateTime->isActive())
	{
		this->updateTime->stop();
		this->setWindowOpacity(0.3);
	}
	else
	{
		this->updateTime->start(1000);
		this->setWindowOpacity(1);
	}

	if (this->isReminding)
	{
		this->resetTimer();
	}
}

void SuspendWindow::mouseReleaseEvent(QMouseEvent*)
{
	this->m_isWindowMoveable = false;
	int leftX = this->x();
	int rightX = leftX + this->width();
	if (leftX < HIDDEN_SIZE)
		this->positionInfo = 1;
	else if (rightX > this->s_width - HIDDEN_SIZE)
		this->positionInfo = 2;
	else
		this->positionInfo = 0;
}



void SuspendWindow::setBackground(QString path)
{
	QPixmap pixmap = QPixmap(path).scaled(this->size());
	QPalette palette(this->palette());
	palette.setBrush(QPalette::Background, QBrush(pixmap));
	this->setPalette(palette);
}

void SuspendWindow::setTime(int minute, int second)
{
	this->ui.lcdMinute->display(QString("%1").arg(minute, 2, 10, QChar('0')));
	this->ui.lcdSecond->display(QString("%1").arg(second, 2, 10, QChar('0')));
	this->update();
}

void SuspendWindow::initializeTime()
{
	this->correction = 0;
	this->minute = WORK_TIME;
	this->isReminding = false;
	this->changeWorkRest(true);
	this->second = 0;
	this->ui.lcdDivide->display("..");
	this->ui.lcdDivide->setAttribute(Qt::WA_TranslucentBackground);
	this->lastTime = new QTime;
	*this->lastTime = QTime::currentTime();
	this->setTime(this->minute, this->second);
	this->updateTime->start(1000);
}

void SuspendWindow::backMainWindow(bool)
{
	this->accept();
	this->a->exit(0);
}

void SuspendWindow::hideDialog()
{
	int newX = this->x();
	//left hide
	if (this->positionInfo == 1)
	{
		newX = HIDDEN_SIZE - this->width();
		this->move(newX, this->y());
	}
	//right
	else if (this->positionInfo == 2)
	{
		newX = this->s_width - HIDDEN_SIZE;
		this->move(newX, this->y());
	}
	//center
	else
	{
		this->ui.frame->setStyleSheet("QFrame{border:none;border-radius:13px;background-color:rgba(255, 255, 255, 0);}");
		this->update();
	}
	this->isHidden = true;
	this->hiddenTime->stop();
}

void SuspendWindow::leaveEvent(QEvent*)
{
	if (!this->isHidden)
		this->hiddenTime->start(1000);
}

void SuspendWindow::enterEvent(QEvent*)
{
	this->hiddenTime->stop();
	if (this->isHidden)
	{
		this->isHidden = false;
		//center
		if (this->positionInfo == 0)
		{
			if (this->isWorking)
			{
				this->ui.frame->setStyleSheet("QFrame{border:none;border-radius:13px;background-color:rgba(255, 255, 255, 255);}");
			}
			else
			{
				this->ui.frame->setStyleSheet("QFrame{border:none;border-radius:13px;background-color:rgba(0, 0, 0, 255);}");
			}
			this->update();
		}
		//right
		else if (this->positionInfo == 2)
		{
			this->move(this->s_width - this->width(), this->y());
		}
		//left
		else
		{
			this->move(0, this->y());
		}
		this->isHidden = false;
	}
}

void SuspendWindow::updateShowTime()
{
	/*if (this->correction >= 5)
	{
		int sum = 0;
		QTime current = QTime::currentTime();
		int dHour, dMinute, dSecond;
		if (current.hour() < this->lastTime->hour())
		{
			dHour = current.hour() + 24 - this->lastTime->hour();
		}
		else
		{
			dHour = current.hour() - this->lastTime->hour();
		}
		qDebug() << "start time:";
		qDebug() << this->lastTime->hour() << this->lastTime->minute() << this->lastTime->second();
		qDebug() << "now time:";
		qDebug() << current.hour() << current.minute() << current.second();
		dMinute = dHour * 60 + current.minute() - this->lastTime->minute();
		dSecond = current.second() - this->lastTime->second();
		qDebug() << dMinute << dSecond;
		qDebug() << dMinute*60 + dSecond;
		if (this->isWorking)
			sum = WORK_TIME;
		else
			sum = REST_TIME;
		if (dSecond > 0)
		{
			dSecond = 60 - dSecond;
			dMinute = sum - 1 - dMinute;
		}
		else if (dSecond < 0)
		{
			dSecond = -dSecond;
			dMinute = sum - dMinute;
		}
		this->minute = dMinute;
		this->second = dSecond;
		this->correction = 0;
	}
	else
	{*/
	this->second--;
	if (this->second < 0)
	{
		this->second = 59;
		this->minute--;
	}
	this->correction++;
	//}
	this->setTime(this->minute, this->second);
	if (this->minute <= 0 && this->second <= 0)
	{
		this->startRemind();
	}
}

void SuspendWindow::startRemind()
{
	if (this->isHidden)
	{
		//right
		if (this->positionInfo == 2)
		{
			this->move(this->s_width - this->width(), this->y());
		}
		else if (this->positionInfo == 0)
		{
			if (this->isWorking)
			{
				this->ui.frame->setStyleSheet("QFrame{border:none;border-radius:13px;background-color:rgba(255, 255, 255, 255);}");
			}
			else
			{
				this->ui.frame->setStyleSheet("QFrame{border:none;border-radius:13px;background-color:rgba(0, 0, 0, 255);}");
			}
			this->update();
		}
		//left
		else
		{
			this->move(0, this->y());
		}
		this->isHidden = false;
	}
	this->hiddenTime->stop();
	this->updateTime->stop();
	this->isReminding = true;
}

void SuspendWindow::initializeWindow()
{
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);
	this->setAttribute(Qt::WA_TranslucentBackground);
	this->m_isWindowMoveable = false;
	this->positionInfo = 0;
	this->s_width = GetSystemMetrics(SM_CXSCREEN);
	this->s_height = GetSystemMetrics(SM_CYSCREEN);
	this->isHidden = false;
}

void SuspendWindow::resetTimer()
{
	if (this->isWorking)
	{
		this->changeWorkRest(false);
		this->minute = REST_TIME;
		this->second = 0;
		this->correction = 0;
		this->setTime(this->minute, this->second);
		//black background
		this->ui.frame->setStyleSheet("QFrame{border:none;border-radius:13px;background-color:rgba(0, 0, 0, 255);}");
		this->update();
	}
	else
	{
		this->changeWorkRest(true);
		this->minute = WORK_TIME;
		this->second = 0;
		this->correction = 0;
		this->setTime(this->minute, this->second);
		//white
		this->ui.frame->setStyleSheet("QFrame{border:none;border-radius:13px;background-color:rgba(255, 255, 255, 255);}");
		this->update();
	}
	*this->lastTime = QTime::currentTime();
	this->isReminding = false;
	this->updateTime->start(1000);
}

void SuspendWindow::setApp(QApplication* a)
{
	this->a = a;
}

void SuspendWindow::changeWorkRest(bool isWorking)
{
	if (isWorking)
	{
		//rest
		this->isWorking = true;
		this->ui.label->setStyleSheet("QLabel{border:3px solid rgb(0, 0, 0);background:transparent;}");
		//this->ui.lcdMinute->setPalette(Qt::black);
		//this->ui.lcdSecond->setPalette(Qt::black);
		//this->ui.lcdDivide->setPalette(Qt::black);
		this->ui.lcdMinute->setStyleSheet("QLCDNumber{background:transparent;color:#000000}");
		this->ui.lcdSecond->setStyleSheet("QLCDNumber{background:transparent;color:#000000}");
		this->ui.lcdDivide->setStyleSheet("QLCDNumber{background:transparent;color:#000000}");
	}
	else
	{
		//work
		this->isWorking = false;
		this->ui.label->setStyleSheet("QLabel{border:3px solid rgb(255, 255, 255);background:transparent;}");
		//this->ui.lcdMinute->setPalette(Qt::white);
		//this->ui.lcdSecond->setPalette(Qt::white);
		//this->ui.lcdDivide->setPalette(Qt::white);
		this->ui.lcdMinute->setStyleSheet("QLCDNumber{background:transparent;color:#ffffff}");
		this->ui.lcdSecond->setStyleSheet("QLCDNumber{background:transparent;color:#ffffff}");
		this->ui.lcdDivide->setStyleSheet("QLCDNumber{background:transparent;color:#ffffff}");
	}
}