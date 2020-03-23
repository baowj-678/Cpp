#include <iostream>
#include <string>

using namespace::std;

class stack {
private:
	int mSize;
	int top;
	int* bottom;
public:
	stack(int mSize)
	{
		this->mSize = mSize;
		this->bottom = new int[mSize];
		this->top = 0;
	}

	bool push(int val)
	{
		if (this->top == this->mSize - 1)
			return false;
		else
		{
			this->top++;
			this->bottom[this->top] = val;
			return true;
		}
	}

	int pop(void)
	{
		if (this->top)
		{
			(this->top)--;
			return this->bottom[this->top + 1];
		}
		else
		{
			return -1;
		}
	}
	bool clear(void)
	{
		this->top = 0;
		return true;
	}

	bool reSize(int mSize)
	{
		delete []this->bottom;
		this->mSize = mSize;
		this->top = 0;
		this->bottom = new int[mSize];
		if (this->bottom)
			return true;
		else
			return false;
	}

};
int main()
{
	int n;
	cout << "please input the size of the stack:" << endl;
	cin >> n;
	stack stack_(n);
	string str;
	cout << "please input action:" << endl;
	cin >> str;
	if (str == "push")
	{
		cout << "please input number:" << endl;
		cin >> n;
	}
	while (str != "q")
	{
		if (str == "push")
			stack_.push(n);
		if (str == "pop")
			cout << stack_.pop() << endl;
		cout << "please input action:" << endl;
		cin >> str;
		if (str == "push")
		{
			cout << "please input number:" << endl;
			cin >> n;
		}
	}
}