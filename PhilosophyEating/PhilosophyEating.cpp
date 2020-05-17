#include "PhilosophyEating.h"
#include <random>
#include <qpainter.h>
#include <qdebug.h>
#include <qpalette.h>

#define COLOR_AVAI	QColor(0, 0, 0)
#define COLOR_1		QColor(255, 0, 0)
#define COLOR_2		QColor(0, 255, 0)
#define COLOR_3		QColor(255, 165, 0)
#define COLOR_4		QColor(128, 0, 128)
#define COLOR_5		QColor(0, 0, 255)

#define COLOR_T_1		QColor(255, 0, 0, 100)
#define COLOR_T_2		QColor(0, 255, 0, 100)
#define COLOR_T_3		QColor(255, 165, 0, 100)
#define COLOR_T_4		QColor(128, 0, 128, 100)
#define COLOR_T_5		QColor(0, 0, 255, 100)

HANDLE philosophers[PHI_NUM];
int chopsticksStatus[CHOPS_NUM];
int philosophyStatus[PHI_NUM][2];
CRITICAL_SECTION mutex[CHOPS_NUM];
PhilosophyEating* pe;

void beginEating(PhilosophyEating* pe);



//deadLockSolution
void thinking(int philosopherID);
void eating(int philosopherID);
void getChopsticksDeadLock(int philosopherID, int chopstickID);
void putChopsticksDeadLock(int philosopherID, int chopstickID);
void setChopstickToPhi(QLabel* label, QColor c);
DWORD WINAPI philosopherDeadLock(LPVOID lpParameter);

PhilosophyEating::PhilosophyEating(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	chops[0] = ui.chop1;
	chops[1] = ui.chop2;
	chops[2] = ui.chop3;
	chops[3] = ui.chop4;
	chops[4] = ui.chop5;

	phis[0] = ui.phi1;
	phis[1] = ui.phi2;
	phis[2] = ui.phi3;
	phis[3] = ui.phi4;
	phis[4] = ui.phi5;

	color[0] = COLOR_1;
	color[1] = COLOR_2;
	color[2] = COLOR_3;
	color[3] = COLOR_4;
	color[4] = COLOR_5;
	color[5] = COLOR_AVAI;

	pe = this;
	connect(this, SIGNAL(sendSignal(QLabel * label, QColor c)), this, SLOT(setChopstickToPhi(QLabel * label, QColor c)));
	
	for (int i(0); i < 5; i++)
	{
		setChopstickToPhi(chops[i], color[i]);
		setChopstickToPhi(phis[i], color[i]);
	}
	int i = 0;
	beginEating(this);
}

DWORD WINAPI philosopherDeadLock(LPVOID lpParameter)
{
	int id = (int)lpParameter;
	//pInfo pinfo = (pInfo)lpParameter;
	//int id = pinfo->id;
	//qDebug() << "in:" << pinfo->id;
	PhilosophyEating* handle = pe;
	int leftID = id;
	int rightID = (id + 1) % PHI_NUM;
	while (true)
	{
		emit(handle->sendSignal(handle->phis[id], handle->color[5]));
		thinking(id);
		emit(handle->sendSignal(handle->phis[id], handle->color[id]));
		getChopsticksDeadLock(id, leftID);
		emit(handle->sendSignal(handle->chops[leftID], handle->color[id]));
		getChopsticksDeadLock(id, rightID);
		emit(handle->sendSignal(handle->chops[rightID], handle->color[id]));
		eating(id);
		putChopsticksDeadLock(id, leftID);
	    emit handle->sendSignal(handle->chops[leftID], handle->color[5]);
		putChopsticksDeadLock(id, rightID);
		emit handle->sendSignal(handle->chops[rightID], handle->color[5]);
	}
}

void thinking(int philosopherID)
{
	qDebug() << "**************************Thinking**********************\n";
	
	Sleep((rand() % 4 + 1) * 100);
	qDebug() << "**************************Finish Thinking**********************\n";
}

void eating(int philosopherID)
{
	qDebug() << "*************************Eating**************************\n";
	Sleep((rand() % 4 + 1) * 100);
	qDebug() << "**************************Finish Eating************************\n";
}

void getChopsticksDeadLock(int philosopherID, int chopstickID)
{
	EnterCriticalSection(&(mutex[chopstickID]));
	chopsticksStatus[chopstickID] = philosopherID;
	qDebug() << chopstickID << "->" << philosopherID << "\n";
}

void putChopsticksDeadLock(int philosopherID, int chopstickID)
{
	LeaveCriticalSection(&(mutex[chopstickID]));
	chopsticksStatus[chopstickID] = CHOPS_AVAIl;
	qDebug() << chopstickID << "----Empty\n";
}

void beginEating(PhilosophyEating* pe)
{
	int i;
	Info info[5];
	for (i = 0; i < CHOPS_NUM; i++)
	{
		chopsticksStatus[i] = CHOPS_AVAIl;
		InitializeCriticalSection(&(mutex[i]));
	}
	for (i = 0; i < PHI_NUM; i++)
	{
		philosophyStatus[i][0] = PHI_EMPTY;
		philosophyStatus[i][1] = PHI_EMPTY;
	}
	DWORD ThreadID;
	for (i = 0; i < PHI_NUM; i++)
	{
		info[i].id = i;
		info[i].point = pe;
		qDebug() << "out:"<<info[i].id;
		philosophers[i] = CreateThread(NULL, 0, philosopherDeadLock, (LPVOID)(i), 0, &ThreadID);
	}
	//WaitForMultipleObjects(5, philosophers, false, INFINITE);

}





/*****************************************************************************/
void PhilosophyEating::setChopstickToPhi(QLabel* label, QColor c)
{
	qDebug() << "yes";
	QPalette label_palette;
	label_palette.setColor(QPalette::Background, c);
	label->setAutoFillBackground(true);
	label->setPalette(label_palette);
}