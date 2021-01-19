/**
* Author: Bao Wenjie
* Link: https://leetcode-cn.com/problems/accounts-merge/
* Date: 2021/1/18
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace::std;

bool cmp(const string& a, const string& b)
{
    return a > b;
}

class Solution {
public:
    const int MAXN = 10000 + 100;
    void Union(vector<int>& UF, int x, int y)
    {
        int x_root = Find(UF, x);
        int y_root = Find(UF, y);
        UF[y_root] = x_root;

    }

    int Find(vector<int>& UF, int x)
    {
        int tmp = x;
        while (x != -1 && UF[x] != x)
        {
            x = UF[x];
        }
        if (x == -1)
        {
            x = tmp;
            UF[x] = tmp;
        }
        while (UF[tmp] != tmp)
        {
            int tmp_ = UF[tmp];
            UF[tmp] = x;
            tmp = tmp_;
        }
        return x;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<int> UF(MAXN, -1);
        vector<vector<string>> ans;
        unordered_map<string, int> email2idx;
        unordered_map<int, string> idx2name;
        unordered_map<string, int> name2idx;
        int i = 0;
        for (vector<string>& account : accounts)
        {
            auto idx_ = email2idx.find(account[1]);
            for (int j = 2; j < account.size(); j++)
            {
                auto tmp_ = email2idx.find(account[i]);
                if (tmp_ == email2idx.end())
                {
                    email2idx[account[i]] = i++;
                }
                else
                {
                    Union(UF, idx_->second, tmp_->second);
                }
            }
            int idx = Find(UF, idx_->second);
            idx2name[idx] = account[0];
        }
        for (int j(0); j < i; j++)
        {
            int idx = Find(UF, j);
            string& name = idx2name[idx];
            auto idx_ = name2idx.find(name);
            if (idx_ == name2idx.end())
            {
                vector<string> ans_vec;
                ans_vec.push_back(name);

            }


        }
    }
};

int main()
{
    vector<vector<string>> accounts = { {"Alex", "Alex5@m.co", "Alex4@m.co", "Alex0@m.co"},
                                        {"Ethan", "Ethan3@m.co", "Ethan3@m.co", "Ethan0@m.co"},
                                        {"Kevin", "Kevin4@m.co", "Kevin2@m.co", "Kevin2@m.co"},
                                        {"Gabe", "Gabe0@m.co", "Gabe3@m.co", "Gabe2@m.co"},
                                        {"Gabe", "Gabe3@m.co", "Gabe4@m.co", "Gabe2@m.co"} };
    Solution so;
    so.accountsMerge(accounts);
}