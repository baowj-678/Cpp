/**
 * @author: Bao Wenjie
 * @date: 2021/6/3
 * @link: https://www.luogu.com.cn/problem/P1100
 */
#include <cstdio>
#include <stdint.h>
#define scanf scanf_s


int main()
{
	
	uint32_t x;
	uint16_t h, l;
	scanf("%d", &x);
	h = x >> 16;
	l = x;
	x = h | l << 16;
	printf("%u\n", x);
}