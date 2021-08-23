#include <iostream>
#include <vector>
#include <map>
using namespace::std;


class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
    	map<int, int> m;
    	for(int i = 0; i < deliciousness.size(); i++)
    	{
    		int tmp = deliciousness[i];
    		if(m.find(tmp) != m.end())
    		{
    			m[tmp] = 1;
			}
			else
			{
				m[tmp] ++;
			}
		}
		long long cnt = 0;
		for(int i = 0; i < deliciousness.size(); i++)
		{
			int tmp = deliciousness[i], tmp_;
			for(int j = 1; j <= 21; j++)
			{
				tmp_ = (1 << j) - tmp;
				if(m.find() != m.end())
				{
					if(tmp_ != tmp)
						cnt += m[tmp_];
					else
						cnt += (m[tmp_] - 1);
				}
			}
		}
		return cnt % 1000000007;
    }
};
