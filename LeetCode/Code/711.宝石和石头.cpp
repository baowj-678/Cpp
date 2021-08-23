#include <iostream>
#include <string>

using namespace::std;

int numJewelsInStones(string J, string S) 
{
	int sum = 0;
	for (int i(0); i < J.length(); i++)
	{
		for (int j(0); j < S.length(); j++)
		{
			if (J[i] == S[j])
				sum++;
		}
	}
	return sum;
}


int main()
{
	string J;
	string S;
	cin >> J >> S;
	int sum = numJewelsInStones(J, S);
	cout << sum << endl;
	return 0;
}



//Í¨¹ý