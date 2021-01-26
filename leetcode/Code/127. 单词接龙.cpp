/**
 * Author: Bao Wenjie
 * Date: 2021/1/26
 * Link: https://leetcode-cn.com/problems/word-ladder/
 */


#include <string>

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace::std;


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int endInt = -1;
        vector<vector<int>> graph(wordList.size(), vector<int>());
    	for(int i = 0; i < wordList.size(); i++)
    	{
            string& tmp = wordList[i];
            if (tmp == endWord)
                endInt = i;
    		for(int j = i + 1; j < wordList.size(); j++)
    		{
    			if(canSwitch(tmp, wordList[j]))
    			{
                    graph[i].push_back(j);
                    graph[j].push_back(i);
    			}
    		}
    	}
        if (endInt == -1)
            return 0;
    	
        vector<bool> isVisited(wordList.size(), false);
        queue<int> Q;
    	for(int i = 0; i < wordList.size(); i++)
    	{
    		if(canSwitch(beginWord, wordList[i]))
    		{
                Q.push(i);
                isVisited[i] = true;
    		}
    	}
        Q.push(-1);
        int cnt = 1;
    	while(Q.size() > 1)
    	{
            int x = Q.front();
            Q.pop();
            if (x == -1)
            {
                Q.push(-1);
                cnt++;
            }
            else if(x == endInt)
            {
                cnt++;
                return cnt;
            }
            else
            {
            	for(int next:graph[x])
            	{
            		if(isVisited[next] == false)
            		{
                        Q.push(next);
                        isVisited[next] = true;
            		}
            	}
            }
    	}
        return 0;
    }
	
    bool canSwitch(string& first, string& second)
    {
        int cnt = 0;
        for (int i(0); i < first.size(); i++)
        {
            if (first[i] != second[i])
                cnt++;
        }
        return cnt == 1;
    }
};

int main()
{
    string begin = "hit";
    string end = "cog";
    vector<string> list = { "hot","dot","dog","lot","log","cog", "hit" };
    Solution so = Solution();
    cout<< so.ladderLength(begin, end, list);
}
