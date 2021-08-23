#include <stdio.h>
#include <stdlib.h>
int main()
{
	short int i = 5;
	do {
		i++;
	} 
	while (i++);
	printf("%hd", i);
}


int compute()
{
	char s[100];
	scanf_s("%s", s);
	int first = 0;
	int second = 0;
	int i = 0;
	while (s[i] != '\0' && s[i] != '+' && s[i] != '-')
	{
		i++;
	}
	if (s[i] == '+')
	{
		s[i] = '\0';
		printf_s("%d", atoi(s) + atoi(s + i + 1));
	}
	else if (s[i] == '-')
	{
		s[i] = '\0';
		printf_s("%d", atoi(s) - atoi(s + i + 1));
	}
	else
	{
		printf("Input error!");
	}
}

int shopping()
{
	int money_all = 240;
	int student_all = 40;
	int rice = 10;
	int dump = 6;
	int nud = 4;
	int rice_count = 0;
	int dump_count = 0;
	int nud_count = 0;

	for (rice_count = 0; rice_count <= money_all / rice; rice_count++)
	{
		for (dump_count = 0; dump_count <= money_all / dump; dump_count++)
		{
			for (nud_count = 0; nud_count <= money_all / nud; nud_count++)
			{
				if (rice_count * rice + dump * dump_count + nud * nud_count == money_all && rice_count + dump_count + nud_count == student_all)
				{
					printf_s("·¹£º%d, Ë®½È:%d, Ãæ£º%d", rice_count, dump_count, nud_count);
				}
			}
		}
	}
}

#define N 30
int main()
{
	int i, n, fail, score[N];
	printf("Input the Number of student");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &score[i]);
	}
}

int GetFailNum(int score[], int n)
{
	int fail = 0;
	for (int i = 0; i < n; i++)
	{
		if (score[i] < 60)
			fail++;
	}
	return fail;
}