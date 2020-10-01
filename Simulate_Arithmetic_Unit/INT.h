#pragma once

/**
* 数字基本存储结构
*/

struct s_int
{
	int f : 1; // 符号位
	int x : 31;// 数字位
};

typedef struct s_int s_int;

union u_int
{
	s_int s;
	int x;
};

typedef union u_int u_int;
