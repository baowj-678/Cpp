#include <easyx.h>
#include <random>
#include <iostream>
#include <Windows.h>
#include <graphics.h>
#include <conio.h>

#define PHI_SUM		5
#define CHOP_SUM	5
#define CHOP_AVAI	-1
#define PHI_EMPTY	-1
#define LINE_WIDTH	5
#define BK_COLOR	BLACK
#define LINE_COLOR	WHITE

#define EAT_PIC		"./eat.jpg"
#define THINK_PIC	"./think.jpg"
#define CHOP_PIC	"./chop.jpg"

#define CHOP_SIZE	20
#define PHI_SIZE	50

#define CHOP1_POSI  350, 500
#define CHOP2_POSI  500, 500
#define CHOP3_POSI  550, 350
#define CHOP4_POSI  400, 250
#define CHOP5_POSI  280, 350

#define PHI1_POSI	425, 650
#define PHI2_POSI	685, 480
#define PHI3_POSI	545, 200
#define PHI4_POSI	200, 200
#define PHI5_POSI	200, 480

using namespace::std;


//坐标结构体
struct point 
{
	int x;
	int y;
};

//随眠函数
void thinking(int philosopherID);
void eating(int philosopherID);

//死锁解决方法函数
void getChopsticksDeadLock(int philosopherID, int chopstickID);
void putChopsticksDeadLock(int philosopherID, int chopstickID);
DWORD WINAPI philosopherDeadLock(LPVOID lpParameter);
void beginEating(bool isDeadLock);

//非死锁解法
void getChopsticks(int philosopherID, int chopstickID);
void putChopsticks(int philosopherID, int chopstickID);
DWORD WINAPI philosopher(LPVOID lpParameter);
//图形界面函数
void initGraph();
void drawEat(int philosopherID);
void drawThink(int philosopherID);
void drawGetChop(int chopID, int philosopherID);
void drawPutChop(int chopID, int philosopherID);

//全局变量
IMAGE chopImage;		//筷子图片
IMAGE phiEatImage;		//哲学家吃饭图片
IMAGE phiThinkImage;	//哲学家思考图片
struct point chopPosi[5];
struct point phiPosi[5];

//筷子互斥量
CRITICAL_SECTION mutex[CHOP_SUM];
//筷子状态互斥量
HANDLE leftMutex;
HANDLE rightMutex;
HANDLE philosophers[PHI_SUM];



int main()
{
	loadimage(&chopImage, _T(CHOP_PIC), 50, 33);
	loadimage(&phiEatImage, _T(EAT_PIC), 70, 70);
	loadimage(&phiThinkImage, _T(THINK_PIC), 70, 70);
	int x;
	bool isDeadLock;
	cout << "请输入：\n死锁：1\n非死锁：2\n";
	cin >> x;
	if (x == 1)
		isDeadLock = true;
	else
		isDeadLock = false;
	initGraph();
	beginEating(isDeadLock);
}

/************************************************************************************/
void initGraph()
{
	initgraph(1200, 750, SHOWCONSOLE);

	
	putimage(CHOP1_POSI, &chopImage);
	putimage(CHOP2_POSI, &chopImage);
	putimage(CHOP3_POSI, &chopImage);
	putimage(CHOP4_POSI, &chopImage);
	putimage(CHOP5_POSI, &chopImage);


	putimage(PHI1_POSI, &phiEatImage);
	putimage(PHI2_POSI, &phiEatImage);
	putimage(PHI3_POSI, &phiEatImage);
	putimage(PHI4_POSI, &phiEatImage);
	putimage(PHI5_POSI, &phiEatImage);

	chopPosi[0] = { CHOP1_POSI + 33};
	chopPosi[1] = { CHOP2_POSI };
	chopPosi[2] = { 50 + CHOP3_POSI};
	chopPosi[3] = { CHOP4_POSI };
	chopPosi[4] = { CHOP5_POSI };

	phiPosi[0] = { PHI1_POSI };
	phiPosi[1] = { PHI2_POSI };
	phiPosi[2] = { PHI3_POSI };
	phiPosi[3] = { PHI4_POSI };
	phiPosi[4] = { PHI5_POSI };

	setlinestyle(PS_SOLID, LINE_WIDTH);
}

void drawEat(int philosopherID)
{
	putimage(phiPosi[philosopherID].x, phiPosi[philosopherID].y, &phiEatImage);
}

void drawThink(int philosopherID)
{
	putimage(phiPosi[philosopherID].x, phiPosi[philosopherID].y, &phiThinkImage);
}

void drawGetChop(int chopID, int philosopherID)
{
	setlinecolor(LINE_COLOR);
	line(chopPosi[chopID].x, chopPosi[chopID].y, phiPosi[philosopherID].x, phiPosi[philosopherID].y);
}

void drawPutChop(int chopID, int philosopherID)
{
	setlinecolor(BK_COLOR);
	line(chopPosi[chopID].x, chopPosi[chopID].y, phiPosi[philosopherID].x, phiPosi[philosopherID].y);
}

/*****************************************************************************************/



DWORD WINAPI philosopherDeadLock(LPVOID lpParameter)
{
	int id = (int)lpParameter;
	int leftID = id;
	int rightID = ((id + 1) % PHI_SUM);
	while (true)
	{
		//思考
		drawThink(id);
		thinking(id);
		//获取左筷子
		getChopsticksDeadLock(id, leftID);
		drawGetChop(leftID, id);
		//获取右筷子
		getChopsticksDeadLock(id, rightID);
		drawGetChop(rightID, id);
		//吃饭
		drawEat(id);
		eating(id);
		drawPutChop(leftID, id);
		drawPutChop(rightID, id);
		//放下左筷子
		putChopsticksDeadLock(id, leftID);
		
		//放下右筷子
		putChopsticksDeadLock(id, rightID);
		
	}
}

void thinking(int philosopherID)
{
	Sleep((rand() % 4 + 1) * 100);
}

void eating(int philosopherID)
{
	Sleep((rand() % 4 + 1) * 100);
}


/*****************Dead Lock Solution*********************************************/



void getChopsticksDeadLock(int philosopherID, int chopstickID)
{
	EnterCriticalSection(&(mutex[chopstickID]));
}

void putChopsticksDeadLock(int philosopherID, int chopstickID)
{
	LeaveCriticalSection(&(mutex[chopstickID]));
}

void beginEating()
{
	int i;
	for (i = 0; i < CHOP_SUM; i++)
	{
		InitializeCriticalSection(&(mutex[i]));
	}
	rightMutex = CreateSemaphore(NULL, 4, 4, NULL);
	leftMutex = CreateSemaphore(NULL, 4, 4, NULL);

	DWORD ThreadID;
	for (i = 0; i < PHI_SUM; i++)
	{
		philosophers[i] = CreateThread(NULL, 0, philosopher, (LPVOID)(i), 0, &ThreadID);
	}
	WaitForMultipleObjects(5, philosophers, false, INFINITE);

}

void beginEatingDeadLock()
{
	int i;
	for (i = 0; i < CHOP_SUM; i++)
	{
		InitializeCriticalSection(&(mutex[i]));
	}
	rightMutex = CreateSemaphore(NULL, 4, 4, NULL);
	leftMutex = CreateSemaphore(NULL, 4, 4, NULL);

	DWORD ThreadID;
	for (i = 0; i < PHI_SUM; i++)
	{
		philosophers[i] = CreateThread(NULL, 0, philosopherDeadLock, (LPVOID)(i), 0, &ThreadID);
	}
	WaitForMultipleObjects(5, philosophers, false, INFINITE);

}

/**************************Not Dead Lock Solution**************************/


void getChopsticks(int philosopherID, int chopstickID)
{
	EnterCriticalSection(&(mutex[chopstickID]));
	//左手边
	//if (philosopherID == chopstickID)
	//{
	//	//WaitForSingleObject(leftMutex, INFINITE);
	//	EnterCriticalSection(&mutex[chopstickID]);
	//}
	////右手边
	//else
	//{
	//	//WaitForSingleObject(rightMutex, INFINITE);
	//	EnterCriticalSection(&mutex[chopstickID]);
	//}
}

void putChopsticks(int philosopherID, int chopstickID)
{
	LeaveCriticalSection(&(mutex[chopstickID]));
	//左手边
	//if (philosopherID == chopstickID)
	//{
	//	//ReleaseSemaphore(leftMutex, 1, NULL);
	//	LeaveCriticalSection(&mutex[chopstickID]);
	//}
	////右手边
	//else
	//{
	//	//ReleaseSemaphore(rightMutex, 1, NULL);
	//	LeaveCriticalSection(&mutex[chopstickID]);
	//}
}

DWORD WINAPI philosopher(LPVOID lpParameter)
{
	int id = (int)lpParameter;
	int leftID = id;
	int rightID = ((id + 1) % PHI_SUM);

	while (true)
	{
		//思考
		drawThink(id);
		thinking(id);
		//获取左筷子
		getChopsticks(id, leftID);
		drawGetChop(leftID, id);
		//获取右筷子
		getChopsticks(id, rightID);
		drawGetChop(rightID, id);
		//吃饭
		drawEat(id);
		eating(id);
		//放下左筷子
		drawPutChop(leftID, id);
		drawPutChop(rightID, id);
		putChopsticks(id, leftID);
		
		//放下右筷子
		putChopsticks(id, rightID);
	}
	return 0;
}

/*****************************************************************************/
