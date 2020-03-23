#include <stdio.h>
int main()
{
	int i, t = 0;
	char a[] = '12345678912345678912.1234567891';
	char b[] = '98765432109876543210.0123456789';
	int s[32];
	s[0] = 0;
	for (i = 0; i < 32; i++)
	{
		s[i] = 0;
	}
	for (i = 30; i > 0; i--)
	{
		if (a[i] == '.')
			i--;
		int m, n, k;
		m = a[i] - '0' + t;
		n = b[i] - '0';
		k = m + n;
		if (k >= 10)
		{
			t = k / 10;
			s[i + 1] = k % 10;
		}
		else
		{
			s[i + 1] = k % 10;
			t = 0;
		}
		k = 0;
	}
	s[0] = t;
	for (i = 0; i < 32; i++)
	{
		if (i == 21)
		{
			printf(".");
		}
		else
		{
			printf("%d", s[i]);
		}
	}
	return 0;
}