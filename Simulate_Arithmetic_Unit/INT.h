/**
* s_int,u_int定义
* @Author: Bao Wenjie
* @Email: bwj_678@qq.com
* @Date: 2020/10/2
*/
#pragma once

struct s_int
{
	int x : 31; // 数字位
	int f : 1;  // 符号位
};

typedef struct s_int s_int;

union u_int
{
	s_int s;
	int x;
};

typedef union u_int u_int;
