
#include <iostream>
#include <vector>

using namespace::std;

vector<int> twoSum(vector<int>& nums, int target) {
	int first = 0, second = 0;
	bool is_find = false;
	vector<int>::iterator iter_f = nums.begin();
	

	for (; iter_f != nums.end(); iter_f++, first++)
	{
		second = 0;
		vector<int>::iterator iter_s = nums.begin();

		for (; iter_s != nums.end(); iter_s++, second++)
		{
			if (iter_f == iter_s)
			{
				continue;
			}

			if (*iter_f + *iter_s == target)
			{
				is_find = true;
				break;
			}
			
		}
		if (is_find)
			break;
	}
	//cout << "first:" << first << " " << "second:" << second << endl;
	vector<int> twoSum;
	twoSum.push_back(first);
	twoSum.push_back(second);
	return twoSum;
}

int main()
{
	vector<int> nums = { 3, 2, 4};
	int target = 6;
	vector<int> twosum = twoSum(nums, target);
	vector<int>::iterator iter = twosum.begin();
	for (; iter != twosum.end(); iter++)
	{

		cout << *iter << endl;
	}
}
