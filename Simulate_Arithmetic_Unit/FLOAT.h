/**
* s_float、u_float定义及实现
* @Author: Bao Wenjie
* @Email: bwj_678@qq.com
* @Date: 2020/10/2
*/
#pragma once


struct s_float
{
	unsigned long long num : 52; // 小数
	unsigned long long e : 11;   // 阶码
	unsigned long long f : 1;    // 符号
};

typedef struct s_float s_float;

union u_float
{
	s_float s;
	double num;
};

typedef union u_float u_float;