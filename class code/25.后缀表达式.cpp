#include <stdio.h>
#include "Stack.h"
#include <time.h>
#include <stdlib.h>


#define LENGTH	100000

bool isSign(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	else
		return false;
}

bool isNumOrAlpha(char c)
{
	if (c >= '0' && c <= '9' || c >= 'a' && c <= 'z' || c>='A' && c <= 'Z')
		return true;
	else
		return false;
}
bool isBigger(char c1, char c2)
{
	if ((c1 == '+' || c1 == '-') && (c2 == '*' || c2 == '/') || c1 == '(')
		return false;
	else
		return true;
}
char* ReversePolishNotation(char* s, Stack S)
{
	int i = 0;
	int j = 0;
	while (s[i] != 0)
	{
		if (isNumOrAlpha(s[i]))
		{
			//s[j++] = s[i++];
			j++;
			i++;
			s[j] = s[j];
			//
		}
		else if(isSign(s[i]))
		{
			if (IsEmpty(S))
			{
				Push(s[i++], S);
			}
			else
			{
				while (!IsEmpty(S) && isBigger(Top(S), s[i]))
				{
					//s[j++] = Top(S);
					j++;
					s[j] = s[j];
					Pop(S);
				}
				Push(s[i++], S);
			}
		}
		else if (s[i] == '(')
		{
			Push(s[i++], S);
		}
		else if (s[i] == ')')
		{
			i++;
			while (Top(S) != '(')
			{
				//s[j++] = Top(S);
				j++;
				s[j] = s[j];
				Pop(S);
			}
			Pop(S);
		}
	}
	while (!IsEmpty(S))
	{
		//s[j++] = Top(S);
		j++;
		s[j] = s[j];
		Pop(S);
	}
	//s[j] = 0;
	return s;
}
/*
char* PolishNotation(char* s, Stack S)
{
	int i = 0;
	int j = 0;
	while (s[i] != 0)
	{
		if (isNumOrAlpha(s[i]))
		{
			Push(s[i++], S);
		}
		else
		{

		}
	}
}*/


int main()
{
	Stack S = CreateStack();
	char s[LENGTH];
	int length = 1;
	clock_t begin, end;
	for (int j = 0; j < 17; j++)
	{
		int n = (17-j) * 100;
		length = 1;
		s[0] = 'a';
		int t = 0;
		int step = 0;
		for (int i = 0; i < n; i++)
		{
			int temp = rand() % 4;
			if (temp == 0)
				s[length++] = '*';
			else if (temp == 1)
				s[length++] = '/';
			else if (temp == 2)
				s[length++] = '-';
			else
				s[length++] = '+';
			temp = rand() % 10;
			if (t > 0)
			{
				step++;
				if (temp < step)
				{
					s[length++] = 'a';
					s[length++] = ')';
					t--;
				}
			}
			if (temp == 5)
			{
				s[length++] = '(';
				t++;
			}

			s[length++] = 'a';
		}
		while (t-- > 0)
			s[length++] = ')';
		s[length++] = 0;

		//printf("%s", s);
		//printf("%d\n", length);

		begin = clock();
		for (int k = 0; k < 1000; k++)
			ReversePolishNotation(s, S);
		end = clock();

		//printf("%s", s);
		printf("%d,%f;", length, (double)(end - begin) / CLOCKS_PER_SEC);
	}
}