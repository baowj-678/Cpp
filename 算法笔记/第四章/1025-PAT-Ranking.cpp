/**
* Author: Bao Wenjie
* Date: 2021/1/15
* Link: https://pintia.cn/problem-sets/994805342720868352/problems/994805474338127872
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace::std;
struct Student {
	char id[15];
	int score;
	int location_num;
	int local_rank;
};
Student stu[300];

bool cmp(Student& a, Student& b)
{
	if (a.score != b.score)
		return a.score > b.score;
	else
		return strcmp(a.id, b.id) < 0;
}
int main()
{
	int n, k, num = 0;
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d", &k);
		for (int j = 0; j < k; j++)
		{
			scanf_s("%s", stu[num].id, 15);
			scanf_s("%d", &stu[num].score);
			stu[num].location_num = i;
			num++;
		}
		sort(stu + num - k, stu + num, cmp);
		stu[num - k].local_rank = 1;
		for (int j = num - k + 1; j < num; j++)
		{
			if (stu[j].score == stu[j - 1].score)
			{
				stu[j].local_rank = stu[j - 1].local_rank;
			}
			else
			{
				stu[j].local_rank = k - (num - j) + 1;
			}
		}
	}
	printf("%d\n", num);
	sort(stu, stu + num, cmp);
	int r = 1;
	for (int i = 0; i < num; i++)
	{
		if (i > 0 && stu[i].score != stu[i - 1].score)
		{
			r = i + 1;
		}
		printf("%s ", stu[i].id);
		printf("%d %d %d\n", r, stu[i].location_num, stu[i].local_rank);
	}
	return 0;
}