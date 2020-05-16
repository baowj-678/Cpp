#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <windows.h>

void test()
{
    int i = 0;
    while (i < 10000000)
    {
        i++;
    }
}

void method1()
{
    clock_t start = clock();
    test(); //待测试函数
    clock_t end = clock();
    double runtime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("方法一：%f", runtime);
}

void method2()
{
    LARGE_INTEGER beginTime;
    LARGE_INTEGER endTime;
    LARGE_INTEGER frequency;
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&beginTime);
    test(); //待测试函数
    QueryPerformanceCounter(&endTime);
    double runtime = (double)(endTime.QuadPart - beginTime.QuadPart) / frequency.QuadPart;
    printf("方法二：%f", runtime);
}

int main()
{
    method1();
    printf("\n");
    Sleep(1000);
    method2();
    getchar();
}
