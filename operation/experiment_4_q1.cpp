#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <queue>
#include <set>
#include <time.h> 

#define TRUE 1
#define FALSE 0
#define INVALID -1

#define ALL_INSTRUCTION 320
#define ALL_PAGE 32
#define QUICK_PAGE  8
#define clear_period 50

//页表项
typedef struct {
    int pageIndex;     //页号
    int pageFrameIndex;//页框号
    int counter;       //一个周期内访问该页的次数
    int time;          //最近访问时间
}PageFrame;
typedef PageFrame* pPageFrame;

//页表
PageFrame pf[32];


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

//产生指令队列
for (int i = 0; i < ALL_INSTRUCTION; i += 1)
{
    commands[i] = rand()%320 + 1;
}
//将指令序列变成页地址流
for (int i = 0; i < ALL_INSTRUCTION; i++)
{
    page[i] = commands[i] / 10;
    offset[i] = commands[i] % 10;
}

    //用户内存工作区从 4 个页面到 32 个页面
    for (int i = 4; i < 32; i++)
    {
        printf("%2d page frames ", i);
        //计算用 FIFO 置换时，第 i 个页面时的命中率
        FIFO(i);
        //计算用 LRU 置换时，第 i 个页面时的命中率
        LRU(i);
        //
        OPT(i);
        printf("\n");
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
}


void FIFO(int pfTotal)
{
    //初始化相关数据结构
    initialize(pfTotal);
    std::queue<int> Q;
    int PageCount = 0;
    //现有内存页面数
    int errorTime = 0;
    //缺页次数
    for (int i = 0; i < ALL_INSTRUCTION; i++)
    {
        //页面失效
        if (pf[page[i]].pageFrameIndex == INVALID)
        {
            //失效次数
            errorTime += 1;
            //无空闲页面
            if (PageCount >= pfTotal)
            {
                //淘汰页面
                int outPage = Q.front();
                Q.pop();
                pf[outPage].pageFrameIndex = INVALID;
                //调入页面
                int inPage = page[i];
                pf[inPage].pageFrameIndex = inPage;
                Q.push(inPage);
            }
            else
            {
                int inPage = page[i];
                pf[inPage].pageFrameIndex = inPage;
                Q.push(inPage);
                PageCount++;
            }
        }
    }
    printf("FIFO: %6.4f", 1 - (float)errorTime / ALL_INSTRUCTION);
}

void LRU(int pfTotal)
{
    initialize(pfTotal);
    int PageCount = 0;
    //现有内存页面数
    int presentTime = 0;
    //当前时间
    int errorTime = 0;
    //缺页次数
    for (int i = 0; i < ALL_INSTRUCTION; i++)
    {
        //页面失效
        if (pf[page[i]].pageFrameIndex == INVALID)
        {
            //失效次数
            errorTime++;
            //无空闲页面
            if (PageCount >= pfTotal) {
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
                pf[page[i]].pageFrameIndex = page[i];
                PageCount++;
            }
        }
        //更新访问时间
        pf[page[i]].time = presentTime;
        presentTime++;
    }
    printf(" LRU: %6.4f ", 1 - (float)errorTime / ALL_INSTRUCTION);
}


void OPT(int pfTotal)
{
    initialize(pfTotal);
    int errorTime = 0;
    //缺页次数
    int PageCount = 0;
    //现有内存页面数
    for (int i = 0; i < ALL_INSTRUCTION; i++)
    {
        //页面缺失
        if (pf[page[i]].pageFrameIndex == INVALID)
        {
            //失效次数
            errorTime++;
            //内存页框已满
            if (PageCount >= pfTotal)
            {
                std::set<int> pages;
                //淘汰的页面
                int outPage = 0;
                for (int j = 0; j < 32; j++)
                {
                    if (pf[j].pageFrameIndex != INVALID)
                        pages.insert(j);
                }
                for (int j = i; j < ALL_INSTRUCTION; j++)
                {
                    //page[i]在set中
                    if (pages.size() > 1)
                    {
                        pages.erase(page[j]);
                    }
                    //只剩最后一个
                    else
                    {
                        break;
                    }
                }
                outPage = *pages.begin();
                pf[outPage].pageFrameIndex = INVALID;
                pf[page[i]].pageFrameIndex = page[i];
            }
            //
            else
            {
                pf[page[i]].pageFrameIndex = page[i];
                PageCount++;
            }
        }
    }
    printf(" OPT: %6.4f ", 1 - (float)errorTime / ALL_INSTRUCTION);
}