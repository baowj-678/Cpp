#include <stdio.h>

double goldenSectionRecursion(int n)
{
	if (1 == n)
		return 1.;
	return 1. + 1. / goldenSectionRecursion(n - 1);
}

double goldenSectionLoop(int n)
{
	double goldenSection = 1.;
	for (n; n > 0; n--)
		goldenSection = 1. + 1. / goldenSection;
	return goldenSection;
}

int main()
{
	int n;
	scanf_s("%d", &n);
	printf_s("Recursion:%.19f\n", goldenSectionRecursion(n));
	printf_s("Loop:%.19f\n", goldenSectionLoop(n));

	return 0;
}