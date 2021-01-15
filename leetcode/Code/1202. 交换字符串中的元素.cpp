/**
* Author: Bao Wenjie
* Github: https://github.com/baowj-678
* Source: https://leetcode-cn.com/problems/smallest-string-with-swaps/
* Date: 2021/1/11
*/

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>

using namespace::std;
class Solution {
public:
    void union_(vector<int>& UF, int x, int y)
    {
        if (UF[x] == -1)
        {
            UF[x] = x;
        }
        if (UF[y] == -1)
        {
            UF[y] = find(UF, x);
        }
        else
        {
            y = find(UF, y);
            UF[y] = find(UF, x);
        }
    }

    int find(vector<int>& UF, int x)
    {
        int tmp = x;
        while (UF[x] != x && UF[x] != -1)
            x = UF[x];
        while (UF[tmp] != x && UF[x] != -1)
        {
            int y = UF[tmp];
            UF[tmp] = x;
            tmp = y;
        }
        return x;
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<int> UF(s.size() + 10, -1);
        for (vector<int> tmp : pairs)
        {
            union_(UF, tmp[0], tmp[1]);
        }
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> heap;
        for (int i(0); i < s.size(); i++)
        {
            int x = find(UF, i);
            if (x == -1)
                continue;
            if (heap.find(x) != heap.end())
            {
                heap.find(x)->second.push(s[i]);
            }
            else
            {
                priority_queue<int, vector<int>, greater<int>> tmp;
                tmp.push(s[i]);
                heap[x] = tmp;
            }
        }
        for (int i(0); i < s.size(); i++)
        {
            int x = find(UF, i);
            if (x == -1)
                continue;
            s[i] = heap.find(x)->second.top();
            heap.find(x)->second.pop();
        }
        return s;
    }
};


int main()
{
    string s = "otilzqqoj";
    vector<vector<int>> a{ {2, 3}, {7, 3}, {3, 8}, {1, 7},{1,  0}, {0, 4 },{0, 6},{3, 4}, {2, 5} };
    Solution so;
    cout << so.smallestStringWithSwaps(s, a);
}