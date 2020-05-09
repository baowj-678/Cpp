#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <windows.h>

void test()
{
    int i = 0;
    while (i < 100000)
    {
        i++;
    }
}

void method_1()
{
    clock_t start = clock();
    test(); //´ý²âÊÔº¯Êý
    clock_t end = clock();
    double runtime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%f", runtime);
}

void method_2()
{
    LARGE_INTEGER BegainTime;
    LARGE_INTEGER EndTime;
    LARGE_INTEGER Frequency;
    QueryPerformanceFrequency(&Frequency);
    QueryPerformanceCounter(&BegainTime);
    test(); //´ý²âÊÔº¯Êý
    QueryPerformanceCounter(&EndTime);
    double runtime = (double)(EndTime.QuadPart - BegainTime.QuadPart) / Frequency.QuadPart;

    printf("%f", runtime);
}

int main()
{
    method_1();
    printf("\n");
    Sleep(1000);
    method_2();
    getchar();
}
