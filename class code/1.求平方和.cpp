#include <stdio.h>
#include <time.h>

int sum(int n)
{
	return(n * (n + 1) * (2 * n + 1) / 6);
}

int Sum(int n)
{
	int s = 0;
	for (int i = 1; i <=  n; i++)
		s += i * i;
	return s;

}
int main()
{
	clock_t begin1, end1, begin2, end2;
	for(int i=1;i<16;i++)
	{
		int back1 = 0;
		int back2;
		int x = i * 100;
		begin1 = clock();
		for (int i = 0; i < 100000; i++)
			back1 = Sum(x);
		end1 = clock();
		begin2 = clock();
		for (int i = 0; i < 100000; i++)
			back2 = sum(x);
		end2 = clock();
		printf("%d\n", x);
		printf("迭代：%d, %d\n", back1);
		printf("迭代：%f\n", (double)(end1 - begin1) / CLOCKS_PER_SEC);
		printf("公式：%d\n", back2);
		printf("公式：%f\n", (double)(end2 - begin2) / CLOCKS_PER_SEC);
	}
	return 0;
}
//求平方和：从1到n之间的整数的平方相加，和是 多少？用C语言实现函数，输入n，返回结果
