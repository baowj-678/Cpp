#include "PhilosophyEating.h"
#include <random>
#include <qdebug.h>

HANDLE philosophers[PHI_NUM];
int chopsticksStatus[CHOPS_NUM];
int philosophyStatus[PHI_NUM][2];
CRITICAL_SECTION mutex[CHOPS_NUM];

void beginEating();
//deadLockSolution
void thinking(int philosopherID);
void eating(int philosopherID);
void getChopsticksDeadLock(int philosopherID, int chopstickID);
void putChopsticksDeadLock(int philosopherID, int chopstickID);
DWORD WINAPI philosopherDeadLock(LPVOID lpParameter);

PhilosophyEating::PhilosophyEating(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	int i = 0;
	beginEating();
}

DWORD WINAPI philosopherDeadLock(LPVOID lpParameter)
{
	int id = (int)(lpParameter);
	int leftID = id;
	int rightID = (id + 1) % PHI_NUM;
	while (true)
	{
		thinking(id);
		getChopsticksDeadLock(id, leftID);
		getChopsticksDeadLock(id, rightID);
		eating(id);
		putChopsticksDeadLock(id, leftID);
		putChopsticksDeadLock(id, rightID);
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

void beginEating()
{
	int i;
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
		philosophers[i] = CreateThread(NULL, 0, philosopherDeadLock, LPVOID(i), 0, &ThreadID);
	}

}