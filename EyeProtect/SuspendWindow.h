#pragma once
#include <QDialog>
#include "ui_SuspendWindow.h"
#include <qtimer.h>


class SuspendWindow : public QDialog
{
	Q_OBJECT

public:
	SuspendWindow(QWidget *parent = Q_NULLPTR);
	~SuspendWindow();
	void setApp(QApplication* a);

private:
	Ui::SuspendWindow ui;
	QApplication* a;
	QTimer* hiddenTime;
	QTimer* updateTime;
	QTime* lastTime;
	int minute;
	int second;

	int correction;
	bool isWorking;
	bool isReminding;
	bool m_isWindowMoveable;
	int positionInfo;//0:center, 1:left, 2:right
	bool isHidden;
	QPoint m_point;
	int s_height;
	int s_width;


	void mouseMoveEvent(QMouseEvent* event);
	void mousePressEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);
	void mouseDoubleClickEvent(QMouseEvent* event);
	void enterEvent(QEvent*);
	void leaveEvent(QEvent* event);
	void setBackground(QString path);
	void setTime(int minute = 0, int second = 0);
	void initializeTime();
	void backMainWindow(bool isClose);
	void initializeWindow();
	void startRemind();
	void resetTimer();
	void changeWorkRest(bool isWorking);
private slots:
	void hideDialog();
	void updateShowTime();
};
