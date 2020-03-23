
#include <stdio.h>
#include <stdlib.h>
struct bits
{
	unsigned char bit0;
	unsigned char bit1;
	unsigned char bit2;
	unsigned char bit3;
	unsigned char bit4;
	unsigned char bit5;
	unsigned char bit6;
	unsigned char bit7;
};
void f0(struct bits b);
void f1(struct bits b);
void f2(struct bits b);
void f3(struct bits b);
void f4(struct bits b);
void f5(struct bits b);
void f6(struct bits b);
void f7(struct bits b);

int main()
{
	unsigned int x, i, a[8], j;
	struct bits b;
	void (*p_fun[8])(struct bits);
	scanf_s("%d", &x); //Êä³öÎÞ·ûºÅ×Ö·ûx
	for (i = 0; x > 0; i++)
	{
		a[i] = x & 0x1;
		x = x >> 1;
	}

	b.bit0 = a[7] + '0';
	b.bit1 = a[6] + '0';
	b.bit2 = a[5] + '0';
	b.bit3 = a[4] + '0';
	b.bit4 = a[3] + '0';
	b.bit5 = a[2] + '0';
	b.bit6 = a[1] + '0';
	b.bit7 = a[0] + '0';
	p_fun[0] = f0;
	p_fun[1] = f1;
	p_fun[2] = f2;
	p_fun[3] = f3;
	p_fun[4] = f4;
	p_fun[5] = f5;
	p_fun[6] = f6;
	p_fun[7] = f7;
	if (b.bit0 == '1')
		f0(b);
	if (b.bit1 == '1')
		f1(b);
	if (b.bit2 == '1')
		f2(b);
	if (b.bit3 == '1')
		f3(b);
	if (b.bit4 == '1')
		f4(b);
	if (b.bit5 == '1')
		f5(b);
	if (b.bit6 == '1')
		f6(b);
	if (b.bit7 == '1')
		f7(b);
	return 0;
}
void f0(struct bits b)
{
	printf("the function0 %d is called!\n", b.bit0);
}
void f1(struct bits b)
{
	printf("the function1 %d is called!\n", b.bit1);
}
void f2(struct bits b)
{
	printf("the function2 %d is called!\n", b.bit2);
}
void f3(struct bits b)
{
	printf("the function3 %d is called!\n", b.bit3);
}
void f4(struct bits b)
{
	printf("the function4 %d is called!\n", b.bit4);
}
void f5(struct bits b)
{
	printf("the function5 %d is called!\n", b.bit5);
}
void f6(struct bits b)
{
	printf("the function6 %d is called!\n", b.bit6);
}
void f7(struct bits b)
{
	printf("the function7 %d is called!\n", b.bit7);
}