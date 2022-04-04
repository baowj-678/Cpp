#include <iostream>

using namespace std;

class BIT
{
public:
	BIT(int n);
	~BIT();
	int query(int right);
	int query(int left, int right);
	void update(int index, int val);
	int lowbit(int x);

private:
	int len;
	int* array;
};

BIT::BIT(int n)
{
	this->len = n;
	this->array = new(int[n]);
	memset(this->array, 0, sizeof(int) * n);
}


BIT::~BIT()
{
	free(this->array);
}


int BIT::query(int right)
{
	int res = 0;
	for (int i = right; i >= 0; i -= this->lowbit(i))
	{
		res += this->array[i];
	}
	return res;
}

int BIT::query(int left, int right)
{
	return query(right) - query(left);
}

void BIT::update(int index, int val)
{
	int oldVal = this->query(index, index);
	int addVal = val - oldVal;
	for (int i = index; i < this->len; i += this->lowbit(i))
	{
		this->array[i] += addVal;
	}
}

int BIT::lowbit(int x)
{
	return (-x) & x;
}