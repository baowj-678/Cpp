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

private:
	Ui::SuspendWindow ui;
	QTimer* hiddenTime;
	QTimer* updateTime;
	bool m_isWindowMoveable;
	QPoint m_point;



	void mouseMoveEvent(QMouseEvent* event);
	void mousePressEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);
	void updateShowTime();
	void setBackground(QString path);
	void setTime(QString minute, QString second);
private slots:
	void LeaveRec();
};
