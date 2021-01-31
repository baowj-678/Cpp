/**
 * Author: Bao Wenjie
 * Date: 2021/1/30
 * Link: https://leetcode-cn.com/problems/similar-string-groups/
 */

#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace::std;

class Solution {
public:
    void Union(vector<int>& UF, int x, int y)
    {
        int x_root = Find(UF, x);
        int y_root = Find(UF, y);
        UF[y_root] = x_root;
    }

    int Find(vector<int>& UF, int x)
    {
        int tmp = x;
        while(x != UF[x])
        {
            x = UF[x];
        }
        while(UF[tmp] != x)
        {
            int tmp_ = UF[tmp];
            UF[tmp] = x;
            tmp = tmp_;
        }
        return x;
    }

    bool canMatch(const string& a, const string& b)
    {
        int first = -1, second = -1;
        int cnt = 0;
        for(int i = 0; i < a.length(); i++)
        {
            if(a[i] != b[i])
            {
                if(first == -1)
                    first = i;
                else if(second == -1)
                    second = i;
                else
                    return false;
            }
        }
        if(first == -1)
        {
            return true;
        }
        else if(a[first] == b[second])
            return true;
        return false;
    }

    int numSimilarGroups(vector<string>& strs) {
        int length = strs.size();
        vector<int>UF(length, 0);
        for(int i = 0; i < length; i++)
            UF[i] = i;
        for(int i = 0; i < length; i++)
        {
            for(int j = i + 1; j < length; j++)
            {
                if(canMatch(strs[i], strs[j]))
                {
                    Union(UF, i, j);
                }
            }
        }
        set<int> S;
        for(int i = 0; i < length; i++)
        {
            int root = Find(UF, i);
            if(S.find(root) == S.end())
                S.insert(root);
        }
        return S.size();
    }
};


int main()
{
    vector<string> strs;
    strs.push_back("abc");
    strs.push_back("abc");
    Solution so;
    cout << so.numSimilarGroups(strs) << endl;
}