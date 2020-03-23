#include <stdio.h>
#include <time.h>
#define MAX 1000

//河内塔问题：移动n层的塔，总的移动次数是多少？
int Hanoi[MAX];
int HanoiTower(int n, char x, char y, char z)
{

	if (n == 1)
	{
		//cout << x << "->" << z << endl;
		return 1;
	}
	int last = HanoiTower(n - 1, x, z, y) + 1;
	//cout << x << "->" << z << endl;
	return last + HanoiTower(n - 1, y, x, z);
}

int HanoiTowerDong(int n, char x, char y, char z)
{
	int first = 1;
	for (int i(1); i < n; i++)
	{
		first = 2 * first + 1;
	}
	return first;

}

int main()
{
	int n;
	n = 30;
	clock_t begin, end;
	begin = clock();
	printf("%d\n",HanoiTower(n, 'a', 'b', 'c'));
	printf("%d",HanoiTowerDong(n, 'a', 'b', 'c'));
	end = clock();
	//printf("%d:%d, %f\n", 9, n,(double)(end - begin)/CLOCKS_PER_SEC);
	return 0;
}