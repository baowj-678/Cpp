/**
* Description: 大整数类
* Author: Bao Wenjie
* Date: 2021/1/20
*/

#include <cstring>
#include <string>
#include <iostream>
#include "BigNum.h"
using namespace::std;

BigNum::BigNum()
{
	memset(this->num, 0, sizeof(this->num));
	this->len = 0;
	this->sign = true;
}

BigNum::~BigNum()
{
}

BigNum::BigNum(int x)
{
	string str = to_string(x);
	this->setNum(str.c_str());
}

BigNum::BigNum(long long x)
{
	string str = to_string(x);
	this->setNum(str.c_str());
}

void BigNum::setNum(const char str[])
{
	this->len = strlen(str);
	for (int i(0); i < this->len; i++)
	{
		this->num[i] = str[this->len - i - 1] - '0';
	}
}

/************************ 比较运算 ***********************************/
int compare(BigNum& a, BigNum& b)
{
	if (a.len > b.len)
		return 1;
	else if (a.len < b.len)
		return -1;
	else
	{
		for (int i = a.len - 1; i >= 0; i--)
		{
			if (a.num[i] > b.num[i])
				return 1;
			else if (a.num[i] < b.num[i])
				return -1;
		}
		return 0;
	}
}

bool operator< (BigNum& a, BigNum& b)
{
	if (a.sign == true && b.sign == false)
		return false;
	else if (a.sign == true && b.sign == true)
		return compare(a, b) == -1;
	else if (a.sign == false && b.sign == true)
		return true;
	else
		return compare(a, b) == 1;
}

bool operator> (BigNum& a, BigNum& b)
{
	if (a.sign == true && b.sign == false)
		return true;
	else if (a.sign == true && b.sign == true)
		return compare(a, b) == 1;
	else if (a.sign == false && b.sign == true)
		return false;
	else
		return compare(a, b) == -1;
}

bool operator<= (BigNum& a, BigNum& b)
{
	if (a.sign == true && b.sign == false)
		return false;
	else if (a.sign == true && b.sign == true)
	{
		int tmp = compare(a, b);
		return (tmp == -1 || tmp == 0);
	}
	else if (a.sign == false && b.sign == true)
		return true;
	else
	{
		int tmp = compare(a, b);
		return (tmp == 1 || tmp == 0);
	}
}

bool operator>= (BigNum& a, BigNum& b)
{
	if (a.sign == true && b.sign == false)
		return true;
	else if (a.sign == true && b.sign == true)
	{
		int tmp = compare(a, b);
		return (tmp == 1 || tmp == 0);
	}
	else if (a.sign == false && b.sign == true)
		return false;
	else
	{
		int tmp = compare(a, b);
		return (tmp == -1 || tmp == 0);
	}
}

bool operator== (BigNum& a, BigNum& b)
{
	return compare(a, b) == 0;
}


/************************* 四则运算 ****************************/
// 加法
BigNum add(BigNum& a, BigNum& b)
{
	BigNum c;
	int carry = 0;
	for (int i(0); i < a.len || i < b.len; i++)
	{
		int tmp = a.num[i] + b.num[i] + carry;
		c.num[c.len++] = tmp % 10;
		carry = tmp / 10;
	}
	if (carry != 0)
		c.num[c.len++] = carry;
	return c;
}

/**
* a >= b
*/
BigNum sub(BigNum& a, BigNum& b)
{
	BigNum c;
	for (int i = 0; i < a.len || i < b.len; i++)
	{
		if (a.num[i] < b.num[i])
		{
			a.num[i + 1]--;
			a.num[i] += 10;
		}
		c.num[c.len++] = a.num[i] - b.num[i];
	}
	while (c.len - 1 >= 1 && c.num[c.len - 1] == 0)
		c.len--;
	return c;
}

BigNum mulInt(BigNum& a, int b)
{
	BigNum c;
	int carry = 0;
	for (int i = 0; i < a.len; i++)
	{
		int tmp = a.num[i] * b + carry;
		c.num[c.len++] = tmp % 10;
		carry = tmp / 10;
	}
	while (carry!=0 && c.len <= MAX_BIG_NUM_LEN)
	{
		c.num[c.len++] = carry % 10;
		carry /= 10;
	}
	return c;
}

BigNum mul(BigNum& a, BigNum& b)
{
	BigNum c;
	for (int i = 0; i < b.len; i++)
	{
		BigNum tmp = mulInt(a, b.num[i]);
		c = add(c, tmp);
	}
	c.sign = a.sign ^ b.sign;
	return c;
}

BigNum operator+(BigNum& a, BigNum& b)
{
	if (a.sign == false && b.sign == false)
	{
		BigNum num = add(a, b);
		num.sign = false;
		return num;
	}
	else if (a.sign == true && b.sign == true)
	{
		BigNum num = add(a, b);
		num.sign = true;
		return num;
	}
	else if (a.sign == false && b.sign == true)
	{
		BigNum num = sub(b, a);
		return num;
	}
	else
	{
		BigNum num = sub(a, b);
		return num;
	}
}

BigNum divInt(BigNum& a, int b, int& r)
{
	BigNum c;
	c.len = a.len;
	for (int i = a.len - 1; i >= 0; i--)
	{
		r = r * 10 + a.num[i];
		if (r < b) c.num[i] = 0;
		else
		{
			c.num[i] = r / b;
			r = r % b;
		}
	}
	while (c.len - 1 >= 1 && c.num[c.len - 1] == 0)
	{
		c.len--;
	}
	return c;
}

ostream& operator<< (ostream& out, BigNum& num)
{
	string str;
	for (int i(num.len-1); i >= 0; i--)
	{
		str += to_string(num.num[i]);
	}
	out << str;
	return out;
}


istream& operator>> (istream& in, BigNum& num)
{
	string str;
	in >> str;
	num.setNum(str.c_str());
	return in;
}

int main()
{
	BigNum a, b;
	cin >> a>>b;
	a = a + b;
	cout << a;
}