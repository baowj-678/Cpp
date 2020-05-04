#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <queue>

#define TRUE 1
#define FALSE 0
#define INVALID -1

#define ALL_INSTRUCTION 320
#define ALL_PAGE 32
#define QUICK_PAGE  8
#define clear_period 50

//页框
typedef struct {
    int pageIndex;     //页号
    int pageFrameIndex;//页面号
    int counter;       //一个周期内访问该页的次数
    int time;          //最近访问时间
}PageFrame;
typedef PageFrame* pPageFrame;

//页表
PageFrame pf[32];

////页面控制结构
//typedef struct pfc_struct {
//    int pn;
//    int pfn;
//    struct pfc_struct* next;
//}pfc_type;
//
//pfc_type pfc[32];
////空闲页头指针，忙页头指针，忙页尾指针
//pfc_type* freepf_head, * busypf_head, * busypf_tail;
////缺页次数


int quickPageCount;
//快表页框数
int errorTime;
//指令流数组
int commands[ALL_INSTRUCTION];
//每条指令的页和页内偏移
int page[ALL_INSTRUCTION], offset[ALL_INSTRUCTION];

void initialize(int total_pf);
void OPT(int total_pf);
void FIFO(int total_pf);
void LRU(int total_pf);

int main()
{
    //用进程号作为初始化随机数队列的种子
    srand(10 * GetCurrentProcessId());
    int s = (rand() % 320) + 1;
    //产生指令队列
    for (int i = 0; i < ALL_INSTRUCTION; i++)
    {
        commands[i] = s;
        commands[i + 1] = commands[i] + 1;
        commands[i + 2] = (s * rand()) % 320 + 1;
        commands[i + 3] = commands[i + 2] + 1;

        //将指令序列变成页地址流
        for (int i = 0; i < ALL_INSTRUCTION; i++)
        {
            page[i] = commands[i] / 10;
            offset[i] = commands[i] % 10;
        }
        //用户内存工作区从 4 个页面到 32 个页面
        for (int i = 4; i < 32; i++)
        {
            printf("%2d page frames", i);
            //计算用 FIFO 置换时，第 i 个页面时的命中率
            FIFO(i);
            //计算用 LRU 置换时，第 i 个页面时的命中率
            LRU(i);
            printf("\n");
        }
    }
    getchar();
}


void initialize(int total_pf)
{
    for (int i = 0; i < ALL_PAGE; i++)
    {
        pf[i].pageIndex = i;
        pf[i].pageFrameIndex = INVALID;
        pf[i].counter = 0;
        pf[i].time = -1;
    }
//    for (int i = 0; i < total_pf - 1; i++)
//    {
//        pfc[i].next = &pfc[i + 1];
//        pfc[i].pfn = i;
//    }
//    pfc[total_pf - 1].next = NULL;
//    pfc[total_pf - 1].pfn = total_pf - 1;
//    freepf_head = &pfc[0];
}


void FIFO(int total_pf)
{
    //初始化相关数据结构
    initialize(total_pf);
    std::queue<int> Q;
    int errorTime = 0;
    //pfc_type* p;
    for (int i = 0; i < ALL_INSTRUCTION; i++)
    {
        //页面失效
        if (pf[page[i]].pageFrameIndex == INVALID) {
            //失效次数
            errorTime += 1;
            //无空闲页面
            if (quickPageCount >= 10)
            {
                int outPage = Q.front();
                pf[outPage].pageFrameIndex = INVALID;
                int inPage = page[i];
                pf[inPage].pageFrameIndex = inPage;
                Q.push(inPage);
            }
            else
            {
                int inPage = page[i];
                pf[inPage].pageFrameIndex = inPage;
                Q.push(inPage);
                quickPageCount++;
            }
        }
    }
    printf("FIFO: %6.4f", 1 - (float)errorTime / 320);
}

/**
 * 最近最少使用
 * total_pf: 用户进程的内存页数
 */
void LRU(int total_pf)
{
    initialize(total_pf);
    int presentTime = 0;
    for (int i = 0; i < ALL_INSTRUCTION; i++)
    {
        //页面失效
        if (pf[page[i]].pageFrameIndex == INVALID) {
            //失效次数
            errorTime++;
            //无空闲页面
            if (quickPageCount >= QUICK_PAGE) {
                int min = 32767;
                int temp;
                //找出 time 的最小值
                for (int j = 0; j < ALL_PAGE; j++)
                {
                    if (min > pf[j].time && pf[j].pageFrameIndex != INVALID) {
                        min = pf[j].time;
                        temp = j;
                    }
                }
                pf[temp].pageFrameIndex = INVALID;
                pf[page[i]].pageFrameIndex = page[i];
            }
            else
            {
                //命中，则增加该单元的访问次数
                pf[page[i]].pageFrameIndex = page[i];
            }
        }
        pf[page[i]].time = presentTime;
        presentTime++;
    }
    printf("LRU: %6.4f", 1 - (float)errorTime / 320);
}


void OPT(int numCommand)
{
    initialize(numCommand);
    for (int i = 0; i < ALL_INSTRUCTION; i++)
    {
        //页面缺失
        if (pf[page[i]].pageFrameIndex == INVALID)
        {
            //失效次数
            errorTime++;


        }
        //
    }
}