//题目描述
//输入一个数n，然后输入n个数值各不相同，再输入一个值x，输出这个值在这个数组中的下标（从0开始，若不在数组中则输出 - 1）。
//
//输入
//测试数据有多组，输入n(1 <= n <= 200)，接着输入n个数，然后输入x。
//
//输出
//对于每组输入, 请输出结果。
//
//样例输入 Copy
//4
//1 2 3 4
//3
//样例输出 Copy
//2

//link http://codeup.cn/problem.php?cid=100000576&pid=1

#include <cstdio>

const int maxn = 210;
int nums[maxn];
int main()
{
	int n, x;
	for (int i(0); i < n; i++)
	{
		scanf("%d", nums + i);
	}
	scanf("%d", &x);
	for (int i(0); i < n; i++)
		if (nums[i] == x)
			return i;
	return -1;
}