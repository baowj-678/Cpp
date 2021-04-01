/**
 * Author: Bao Wenjie
 * Date: 2021/3/18
 * Description: ¿∂«≈±≠µ⁄ ÆΩÏHÃ‚ 
 */

#include <cstdio>
#include <vector>
using namespace::std;



int main()
{
	int N;
	scanf("%d", &N);
	vector<int> num_vec(N, 0);
	int num_max = -99999, tmp;
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &tmp);
		num_vec[i] = tmp;
		num_max = max(num_max, tmp); 
	}
	vector<char> is_find(num_max + 1000, 0);
	for(int i = 0; i < N; i++)
	{
		tmp = num_vec[i];
		while(is_find[tmp] == 1)
		{
			tmp++;
		}
		num_vec[i] = tmp;
		is_find[tmp] = 1;
		printf("%d ", tmp);
	}
	return 0;
} 
