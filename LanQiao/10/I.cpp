/**
 * Author: Bao Wenjie
 * Date: 2021/4/1
 * Description: ¿∂«≈±≠µ⁄ ÆΩÏIÃ‚ 
 */

#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>

using namespace::std;
int c[105];
int f[(1 << 20) + 5];
int main()
{
	int N, M, K;
	scanf("%d%d%d", &N, &M, &K);
	int tmp, num;
	for(int i = 0; i < N; i++)
	{
		num = 0;
		for(int j = 0; j < K; j++)
		{
			scanf("%d", &tmp);
			num |= (1 << --tmp);
		}
		c[i] = num;
	}
	memset(f, N+10, sizeof(f));
	f[0] = 0;
	for(int i = 0; i < N; i++)
	{
		num = c[i];
		for(int j = 0; j < (1 << M); j++)
		{
			f[num | j] = min(f[num | j], f[j] + 1);
		}
	}
	if(f[(1 << M)-1] > N)
		num = -1;
	else
		num = f[(1 << M)-1];
	printf("%d\n", num);
	return 0;
}
