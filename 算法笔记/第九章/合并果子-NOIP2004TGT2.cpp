/**
 * @file 合并果子-NOIP2004TGT2.cpp
 * @author your name (you@domain.com)
 * @brief http://codeup.cn/problem.php?cid=100000617&pid=4
 * @version 0.1
 * @date 2021-03-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <cstdio>
#include <vector>
#include <queue>

using namespace::std;


int main()
{
    int n;
    priority_queue<long long, vector<long long>, greater<long long>> q;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        q.push(tmp);
    }
    long long x, y;
    long long ans = 0;
    while(q.size() > 1)
    {
        x = q.top();
        q.pop();
        y = q.top();
        q.pop();
        q.push(x + y);
        ans += (x + y);
    }
    printf("%lld\n", ans);
    return 0;
}