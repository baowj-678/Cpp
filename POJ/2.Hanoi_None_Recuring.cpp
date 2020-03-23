#include <iostream>
#include <stack>

using namespace::std;
struct problem {
	int number;
	char start;
	char mid;
	char end;
	problem(int n, char start, char mid, char end) :number(n), start(start), mid(mid), end(end) {}

};

void hanoi(int n, char start, char mid, char end)
{
	stack<problem>stk;
	stk.push(problem(n, start, mid, end));
	while (!stk.empty())
	{
		if (stk.top().number == 1)
		{
			cout << stk.top().start << "->" << stk.top().end << endl;
			stk.pop();
		}
		else
		{
			problem temp = stk.top();
			stk.pop();
			stk.push(problem(temp.number - 1, temp.mid, temp.start, temp.end));
			stk.push(problem(1, temp.start, temp.mid, temp.end));
			stk.push(problem(temp.number - 1, temp.start, temp.end, temp.mid));
		}
	}
}
int main()
{
	int n;
	cout << "please input the number of the towers:" << endl;
	cin >> n;
	hanoi(n, 'A', 'B', 'C');
}

