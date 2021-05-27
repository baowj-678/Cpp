/**
 * @author: Bao Wenjie
 * @date: 2021/5/27
 * @link: https://www.luogu.com.cn/problem/P4316
 */

#include <cstdio>
#include <vector>
#define MAXN 10050
#define scanf scanf_s

struct edge
{
	int u;
	int w;
};
std::vector<edge>g [MAXN];

int cnt[MAXN];
double dp_[MAXN];
double dp[MAXN];
bool isV[MAXN];


double dfs(int x, int n)
{
	if (isV[x])
		return dp[x];
	double sum = 0;
	double sum_ = 0;
	for(edge tmp:g[x])
	{
		sum += ((dfs(tmp.u, n) + dp_[tmp.u] * tmp.w) / cnt[tmp.u]);
		sum_ += dp_[tmp.u]/cnt[tmp.u];
	}
	dp[x] = sum;
	dp_[x] = sum_;
	isV[x] = true;
	return sum;
}

int main()
{
	int n, m, u, v, w;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &u, &v, &w);
		cnt[u]++;
		struct edge tmp;
		tmp.u = u, tmp.w = w;
		g[v].push_back(tmp);
	}
	isV[1] = true;
	dp_[1] = 1;
	dfs(n, n);
	printf("%.2f\n", dp[n]);
	return 0;
}