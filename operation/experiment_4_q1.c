#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define TRUE 1
#define FALSE 0
#define INVALID -1

#define ALL_INSTRUCTION 320 //共 320 条指令
#define ALL_PAGE 32 //虚拟页共 32
#define clear_period 50

//页框
typedef struct {
    int pageIndex;//页号
    int pageFrameIndex;//页面号
    int counter;//一个周期内访问该页的次数
    int time;//最近访问时间
}PageFrame;

//页表
PageFrame pf[32];

//页面控制结构
typedef struct pfc_struct {
    int pn;
    int pfn;
    struct pfc_struct* next;
}pfc_type;

pfc_type pfc[32];
//空闲页头指针，忙页头指针，忙页尾指针
pfc_type* freepf_head, * busypf_head, * busypf_tail;
//缺页次数
int disaffect;
//指令流数组
int a[ALL_INSTRUCTION];
//每条指令的页和页内偏移
int page[ALL_INSTRUCTION], offset[ALL_INSTRUCTION];

void initialize(int total_pf);
void FIFO(int total_pf);
void LRU(int total_pf);

int main()
{
    //用进程号作为初始化随机数队列的种子
    srand(10 * GetCurrentProcessId());
    int s = (float)319 * rand() / 32767 / 32767 / 2 + 1;
    //产生指令队列
    for (int i = 0; i < ALL_INSTRUCTION; i++)
    {
        if (s < 0 || s > 319)
        {
            printf("when i == %d,error: s == %d\n", i, s);
            exit(0);
        }
        //任意选一指令访问点 m
        a[i] = s;
        //顺序执行下一条指令
        a[i + 1] = a[i] + 1;
        //执行前地址指令 m
        a[i + 2] = (float)a[i] * rand() / 32868 / 32767 / 2;
        //顺序执行一条指令
        a[i + 3] = a[i + 2] + 1;
        s = (float)(318 - a[i + 2]) * rand() / 32767 / 32767 / 2 + a[i + 2] + 2;
        if ((a[i + 2] > 318) || (s > 319)) {
            printf("a[%d + 2],a number which is: %d and s = %d\n", i, a[i + 2], s);
        }
        //将指令序列变成页地址流
        for (int i = 0; i < ALL_INSTRUCTION; i++)
        {
            page[i] = a[i] / 10;
            offset[i] = a[i] % 10;
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
    for (int i = 0; i < total_pf - 1; i++)
    {
        pfc[i].next = &pfc[i + 1];
        pfc[i].pfn = i;
    }
    pfc[total_pf - 1].next = NULL;
    pfc[total_pf - 1].pfn = total_pf - 1;
    freepf_head = &pfc[0];
}


void FIFO(int total_pf)
{
    //初始化相关数据结构
    initialize(total_pf);
    busypf_head = busypf_tail = NULL;
    int disfeffect = 0;
    pfc_type* p;
    for (int i = 0; i < ALL_INSTRUCTION; i++)
    {
        //页面失效
        if (pf[page[i]].pageFrameIndex == INVALID) {
            //失效次数
            disfeffect += 1;
            //无空闲页面
            if (freepf_head == NULL) {
                p = busypf_head->next;
                pf[busypf_head->pn].pageFrameIndex = INVALID;
                //释放忙页面队列的第一个页面
                freepf_head = busypf_head;
                freepf_head->next = NULL;
                busypf_head = p;
            }
            //按 FIFO 方式调用新页面入内存
            p = freepf_head->next;
            freepf_head->next = NULL;
            freepf_head->pn = page[i];
            pl[page[i]].pfn = freepf_head->pfn;
            if (busypf_tail == NULL)
            {
                busypf_head = busypf_tail = freepf_head;
            }
            else
            {
                //free 页面减少一个
                busypf_tail->next = freepf_head;
                busypf_tail = freepf_head;
            }
            freepf_head = p;
        }
    }
    printf("FIFO: %6.4f", 1 - (float)disfeffect / 320);
}

/**
 * 最近最少使用
 * total_pf: 用户进程的内存页数
 */
void LRU(int total_pf)
{
    initialize(total_pf);
    int present_time = 0;
    int diseffect = 0;
    for (int i = 0; i < ALL_INSTRUCTION; i++)
    {
        //页面失效
        if (pl[page[i]].pfn == INVALID) {
            diseffect++;
            //无空闲页面
            if (freepf_head == NULL) {
                int min = 32767;
                int minj;
                //找出 time 的最小值
                for (int j = 0; j < ALL_PAGE; j++)
                {
                    if (min > pl[j].time && pl[j].pfn != INVALID) {
                        min = pl[j].time;
                        minj = j;
                    }
                    //腾出一个单元
                    freepf_head = &pfc[pl[minj].pfn];
                    pl[minj].pfn = INVALID;
                    pl[minj].time = -1;
                    freepf_head->next = NULL;
                }
                //有空闲页，改为有效
                pl[page[i]].pfn = freepf_head->pfn;
                pl[page[i]].time = present_time;
                //减少一个 free 页面
                freepf_head = freepf_head->next;
            }
            else
            {
                //命中，则增加该单元的访问次数
                pl[page[i]].time = present_time;
            }
        }
        present_time++;
    }
    printf("LRU: %6.4f", 1 - (float)diseffect / 320);
}