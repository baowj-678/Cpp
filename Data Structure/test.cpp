#include <stdio.h>
#include <math.h>

void change(char s[])
{
	int i = 0;
	while (s[i] != 0)
	{
		if (s[i] == 'a')
			s[i] = 'A';
		if (s[i] == 'D')
			s[i] = 'd';
		i++;
	}
}
void  main(void)
{
	char s[] = "abcdefghijklmnopqrstuvwxyz";
#define CHANGE	1
#ifdef CHANGE
	if (CHANGE == 1)
		change(s);
#endif
	printf("%s", s);
}


