#include <stdio.h>
#include <malloc.h>
#define G	8
#define LENGTH	5
typedef struct Element
{
	int element;
	struct Element* next;
} Cluster;

//每个cluster的element链表
typedef struct Element* index;
//类链表
index indexs[100];
//类的个数：从0-cluster_length-1;
int cluster_num;
//得分矩阵
double T[100][100];
//序列矩阵
char Sequence[100][200];
//序列矩阵大小信息
int Matrix_size[100][2];
//匹配分数矩阵
double D[24][24] = {
	{2,-2,0,0,-2,0,0,1,-1,-1,-2,-1,-1,-4,1,1,1,-6,-3,0,0,0,0,-8},
	{-2,6,0,-1,-4,1,-1,-3,2,-2,-3,3,0,-4,0,0,-1,2,-4,-2,-1,0,-1,-8},
	{0,0,2,2,-4,1,1,0,2,-2,-3,1,-2,-4,-1,1,0,-4,-2,-2,2,1,0,-8},
	{0,-1,2,4,-5,2,3,1,1,-2,-4,0,-3,-6,-1,0,0,-7,-4,-2,3,3,-1,-8},
{-2,-4,-4,-5,12,-5,-5,-3,-3,-2,-6,-5,-5,-4,-3,0,-2,-8,0,-2,-4,-5,-3,-8},
{0,1,1,2,-5,4,2,-1,3,-2,-2,1,-1,-5,0,-1,-1,-5,-4,-2,1,3,-1,-8},
{0,-1,1,3,-5,2,4,0,1,-2,-3,0,-2,-5,-1,0,0,-7,-4,-2,3,3,-1,-8},
{1,-3,0,1,-3,-1,0,5,-2,-3,-4,-2,-3,-5,-1,1,0,-7,-5,-1,0,0,-1,-8},
{-1,2,2,1,-3,3,1,-2,6,-2,-2,0,-2,-2,0,-1,-1,-3,0,-2,1,2,-1,-8},
{-1,-2,-2,-2,-2,-2,-2,-3,-2,5,2,-2,2,1,-2,-1,0,-5,-1,4,-2,-2,-1,-8},
{-2,-3,-3,-4,-6,-2,-3,-4,-2,2,6,-3,4,2,-3,-3,-2,-2,-1,2,-3,-3,-1,-8},
{-1,3,1,0,-5,1,0,-2,0,-2,-3,5,0,-5,-1,0,0,-3,-4,-2,1,0,-1,-8},
{-1,0,-2,-3,-5,-1,-2,-3,-2,2,4,0,6,0,-2,-2,-1,-4,-2,2,-2,-2,-1,-8},
{-4,-4,-4,-6,-4,-5,-5,-5,-2,1,2,-5,0,9,-5,-3,-3,0,7,-1,-4,-5,-2,-8},
{1,0,-1,-1,-3,0,-1,-1,0,-2,-3,-1,-2,-5,6,1,0,-6,-5,-1,-1,0,-1,-8},
{1,0,1,0,0,-1,0,1,-1,-1,-3,0,-2,-3,1,2,1,-2,-3,-1,0,0,0,-8},
{1,-1,0,0,-2,-1,0,0,-1,0,-2,0,-1,-3,0,1,3,-5,-3,0,0,-1,0,-8},
{-6,2,-4,-7,-8,-5,-7,-7,-3,-5,-2,-3,-4,0,-6,-2,-5,17,0,-6,-5,-6,-4,-8},
{-3,-4,-2,-4,0,-4,-4,-5,0,-1,-1,-4,-2,7,-5,-3,-3,0,10,-2,-3,-4,-2,-8},
{0,-2,-2,-2,-2,-2,-2,-1,-2,4,2,-2,2,-1,-1,-1,0,-6,-2,4,-2,-2,-1,-8},
{0,-1,2,3,-4,1,3,0,1,-2,-3,1,-2,-4,-1,0,0,-5,-3,-2,3,2,-1,-8},
{0,0,1,3,-5,3,3,0,2,-2,-3,0,-2,-5,0,0,-1,-6,-4,-2,2,3,-1,-8},
{0,-1,0,-1,-3,-1,-1,-1,-1,-1,-1,-1,-1,-2,-1,0,0,-4,-2,-1,-1,-1,-1,-8},
{-8,-8,-8,-8,-8,-8,-8,-8,-8,-8,-8,-8,-8,-8,-8,-8,-8,-8,-8,-8,-8,-8,-8,1},
};
//
double S[100][100];
double M[100][100];


void MSA();
//计算cluster a和cluster b之间的的得分，a、b表示其索引，m、n表示其长度
double getClusterScore(index indexs[], int a, int b, int m, int n);
//求三个数的最大值
double max_three(int a, int b, int c);
//求两个数的最大值
double max_two(int a, int b);
//计算A、B的分数，m、n表示序列的长度
double getSequenceScore(char A[], char B[], int m, int n);
double getD(int i, int j);
double getWeight(index B, index C, int i, int j);
//将j类联合到i类
void align(int i, int j);
//寻找得分矩阵中最大的元素m<n
void find_max(int* m, int* n);


int main()
{
	cluster_num = 5;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < LENGTH; j++)
		{
			Sequence[i][j] = i;
		}
	}

	for (int i = 2; i < cluster_num; i++)
	{
		for (int j = 0; j < LENGTH; j++)
		{
			Sequence[i][j] = i-1;
		}
	}
	MSA();
}

//计算cluster a和cluster b之间的的得分，a、b表示其索引，m、n表示其长度
double getClusterScore(index indexs[], int a, int b, int m, int n)
{
	index A = indexs[a];
	index B = indexs[b];
	int i, j;
	//初始化S
	for (j = 0; j < n; j++)
	{
		S[m - 1][j] = getWeight(A, B, m - 1, j);
	}
	for (i = 0; i < m; i++)
	{
		S[i][n - 1] = getWeight(A, B, i, n - 1);
	}
	//初始化M
	double max = S[m - 1][n - 1];
	for (j = n - 1; j >= 0; j--)
	{
		if (S[m - 1][j] > max)
			max = S[m - 1][j];
		M[m - 1][j] = max;
	}
	max = S[m - 1][n - 1];
	for (i = m - 1; i >= 0; i--)
	{
		if (S[i][n - 1])
			max = S[i][n - 1];
		M[i][n - 1] = max;
	}

	for (i = m - 2; i >= 0; i--)
	{
		for (j = n - 1; j >= 0; j--)
		{
			double w = getWeight(A, B, i, j);
			S[i][j] = w + max_two(S[i + 1][j + 1], M[i + 1][j + 1] - G);
			M[i][j] = max_three(S[i][j], M[i + 1][j], M[i][j + 1]);
		}
	}
	return M[0][0];
}

//求三个数的最大值
double max_three(int a, int b, int c)
{
	if (a > b)
	{
		if (a > c)
		{
			return a;
		}
		else
		{
			return c;
		}
	}
	else
	{
		if (b > c)
			return b;
		else
		{
			return c;
		}
	}
}

//求两个数的最大值
double max_two(int a, int b)
{
	return a > b ? a : b;
}


//计算A、B的分数，m、n表示序列的长度
double getSequenceScore(char A[], char B[], int m, int n)
{
	
	int i, j, k;
	//初始化S
	for (j = 0; j < n; j++)
	{
		S[m - 1][j] = getD(A[m - 1], B[j]);
	}
	for (i = 0; i < m; i++)
	{
		S[i][n - 1] = getD(A[i], B[n - 1]);
	}
	//初始化M
	double max = S[m - 1][n - 1];
	for (j = n - 1; j >= 0; j--)
	{
		if (S[m - 1][j] > max)
			max = S[m - 1][j];
		M[m - 1][j] = max;
	}
	max = S[m - 1][n - 1];
	for (i = m - 1; i >= 0; i--)
	{
		if (S[i][n - 1])
			max = S[i][n - 1];
		M[i][n - 1] = max;
	}

	for (i = m - 2; i >= 0; i--)
	{
		for (j = n - 1; j >= 0; j--)
		{
			double w = getD(A[i], B[j]);
			S[i][j] = w + max_two(S[i + 1][j + 1], M[i + 1][j + 1] - G);
			M[i][j] = max_three(S[i][j], M[i + 1][j], M[i][j + 1]);
		}
	}
	return M[0][0];
}

double getD(int i, int j)
{
	return D[i][j];
}

double getWeight(index B, index C, int i, int j)
{
	double w = 0;
	int P = B->element;
	int Q = C->element;
	index R = B->next;
	while (R != NULL)
	{
		index S = C->next;
		while (S != NULL)
		{
			w += getD(Sequence[R->element][i], Sequence[S->element][j]);
			S = S->next;
		}
		R = R->next;
	}
	w /= (P * Q);
	return w;
}

//寻找得分矩阵中最大的元素m<n
void find_max(int* m, int* n)
{
	int i, j;
	double max = T[0][1];
	*m = 0;
	*n = 1;
	for (i = 0; i < cluster_num; i++)
	{
		for (j = 0; j < cluster_num; j++)
		{
			if (T[i][j] > max&& i != j)
			{
				*m = i;
				*n = j;
				max = T[i][j];
			}
		}
	}
	if (*m > * n)
	{
		int temp = *n;
		*n = *m;
		*m = temp;
	}
	return;
}

//将j类联合到i类
void align(int i, int j)
{
	index A = indexs[i];
	index B = indexs[j];
	while (A->next != NULL)
	{
		A = A->next;
	}
	//更改A类相关的得分矩阵
	int k;
	for (k = 0; k < cluster_num; k++)
	{
		if (k != i && k != j)
		{
			T[k][i] = T[i][k] = (indexs[i]->element * T[i][k] + indexs[j]->element * T[j][k]) / (indexs[i]->element + indexs[j]->element);
		}
	}
	T[i][i] = getClusterScore(indexs, i, i, LENGTH, LENGTH);
	//将B类加到A类后面
	A->next = B->next;
	indexs[i]->element += B->element;
	//将最后一类移动到B类的位置
	B->next = indexs[cluster_num - 1]->next;
	B->element = indexs[cluster_num - 1]->element;
	cluster_num--;
	//将最后一类得分矩阵移到B类位置
	T[j][j] = T[cluster_num][cluster_num];
	for (k = 0; k < cluster_num; k++)
	{
		if (k != j)
		{
			T[k][j] = T[k][cluster_num];
			T[j][k] = T[cluster_num][k];
		}
	}
}
void MSA()
{
	//初始化类
	int i = 0, j;
	for (i = 0; i < cluster_num; i++)
	{
		//初始化类的索引
		index temp = (index)malloc(sizeof(Cluster));
		if (temp != NULL)
		{
			indexs[i] = temp;
			temp->element = 1;
			temp->next = NULL;
		}
		temp = (index)malloc(sizeof(Cluster));
		if (temp != NULL)
		{
			indexs[i]->next = temp;
			temp->element = i;
			temp->next = NULL;
		}
	}
	//初始化得分矩阵
	for (i = 0; i < cluster_num; i++)
	{
		for (j = 0; j < cluster_num; j++)
		{
			T[i][j] = getSequenceScore(Sequence[i], Sequence[j], i, j);
		}
	}
	while (cluster_num > 1)
	{
		//找到最大元素索引i<j
		find_max(&i, &j);

		printf("%d %d %d \n", i, j, cluster_num);
		//联合i、j
		align(i, j);
		

		int k = 0;
		for (k = 0; k < cluster_num; k++)
		{
			index temp = indexs[k]->next;
			printf("[");
			while (temp != NULL)
			{
				printf("%d ", temp->element);
				temp = temp->next;
			}
			printf("] ");
		}
		printf("\n");
	}
}