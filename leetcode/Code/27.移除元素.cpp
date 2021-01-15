#include <iostream>
#include <vector>

using namespace::std;

int removeElement(vector<int>& nums, int val) {
	vector<int>::iterator iter = nums.begin();
	for (iter; iter != nums.end(); iter++)
	{
		if (*iter == val)
		{
			iter = nums.erase(iter);
			iter--;
		}
	}
	return nums.size();
}

void print(vector<int>& nums)
{
	vector<int>::iterator iter = nums.begin();
	for (iter; iter != nums.end(); iter++)
	{
		cout << *iter << " ";
	}
}
int main()
{
	int n;
	vector<int> nums;
	cin >> n;
	for (int i(0); i < n; i++)
	{
		int x;
		cin >> x;
		nums.push_back(x);
	}
	cout << "please input the number you want to delete:" << endl;
	int val;
	cin >> val;
	cout << removeElement(nums, val) << endl;
	print(nums);

}