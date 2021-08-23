#include <iostream>
#include <vector>

using namespace::std;

int removeDuplicates(vector<int>& nums) {
	vector<int>::iterator iter1 = nums.begin();
	while(iter1 != nums.end())
	{
		while ((iter1 + 1) != nums.end() && *iter1 == *(iter1 + 1))
		{
			nums.erase(iter1 + 1);
		}
		iter1++;
	}
	return nums.size();
}

int main()
{
	vector<int> nums;
	int n;
	cin >> n;
	for (int i(0); i < n; i++)
	{
		int y;
		cin >> y;
		nums.push_back(y);
	}

	cout << removeDuplicates(nums) << endl;
	for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++)
	{
		cout << *iter << " ";
	}
}

//accepted but too slow