#pragma once
#define MAX_BIG_NUM_LEN	1000

using std::istream;
using std::ostream;
class BigNum
{
public:
	BigNum();
	BigNum(int x);
	BigNum(long long x);
	~BigNum();
	void setNum(const char str[]);
	/***************** 比较运算 ************************/
	// 不考虑符号
	friend int compare(BigNum& a, BigNum& b);
	// 考虑符号
	friend bool operator< (BigNum& a, BigNum& b);
	friend bool operator> (BigNum& a, BigNum& b);
	friend bool operator<= (BigNum& a, BigNum& b);
	friend bool operator>= (BigNum& a, BigNum& b);
	friend bool operator== (BigNum& a, BigNum& b);
	/******************** 四则运算 *************************/
	// 不考虑符号（默认正数）
	friend BigNum add(BigNum& a, BigNum& b);
	friend BigNum sub(BigNum& a, BigNum& b);
	friend BigNum mulInt(BigNum& a, int b);
	friend BigNum mul(BigNum& a, BigNum& b);
	friend BigNum divInt(BigNum& a, int b, int& r);
	friend BigNum div(BigNum& a, BigNum& b);
	// 考虑符号
	friend BigNum operator+(BigNum& a, BigNum& b);
	friend BigNum operator-(BigNum& a, BigNum& b);
	/******************* 输入输出 ***************************/
	friend ostream& operator<< (ostream& os, BigNum& num);
	friend istream& operator>> (istream& in, BigNum& num);

private:
	// 0-1000：low-high
	int num[MAX_BIG_NUM_LEN];
	// false: negative; true: positive
	bool sign;
	int len;
};