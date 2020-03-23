#include <stdio.h>

#define M    (16)

static int pos[M];
static int cnt = 0;


static void print_board(int n)
{
	int i, j;

	for (j = 0; j < n; j++)
	{
		for (i = 0; i < n; i++)
		{
			if ((1 << i) & pos[j])
				printf("  1");
			else
				printf("  0");
		}
		printf("\n");
	}
	printf("\n");

	return;
}

static void search(int n, int row, int co, int tl, int tr)
{
	int bits, p;

	if (co == (1 << n) - 1) // all columns have been filled
	{
		cnt++;    //new success
		print_board(n);
		return;
	}

	bits = (~(co | tl | tr)) & ((1 << n) - 1);  //all of the available cells are set to 1
	while (bits)
	{
		p = bits & -bits;  //try the leftmost cell
		pos[row] = p;    //update the record
		bits &= (bits - 1);  //mark p as tested
		search(n, row + 1, co | p, (tl | p) << 1, (tr | p) >> 1);    //move downward to the next row
	}
	return;
}

int Q[8][8];
int Mid[8];
int X[8];
void Queen(int n)
{
	if (n == -1)
	{
		bool flag = true;
		for (int j = 0; j < 8; j++)
		{
			for (int k = j + 1; k < 8; k++)
			{
				int temp1 = X[k] - X[j];
				int temp2 = k - j;
				if (temp1 == temp2 || temp1 == -temp2)
				{
					flag = false;
					break;
				}
			}
			if (flag == false)
				break;
		}
		if (flag)
		{
			printf("%d\n", ++cnt);
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					printf("%d ", Q[i][j]);
				}
				printf("\n");
			}
			printf("\n");
		}
		return;
	}

	for (int i = 0; i < 8; i++)
	{
		if (Mid[i] == 0)
		{
			Q[n][i] = 1;
			Mid[i] = 1;
			X[n] = i;
			Queen(n - 1);
			Mid[i] = 0;
			Q[n][i] = 0;
		}
	}
	return;
}


void Queen0()
{
	for (int q1 = 0; q1 < 8; q1++)
	{
		Mid[q1] = 1;
		Q[0][q1] = 1;
		X[0] = q1;
		for (int q2 = 0; q2 < 8; q2++)
		{
			if (Mid[q2] == 1)
				continue;
			Mid[q2] = 1;
			Q[1][q2] = 1;
			X[1] = q2;
			for (int q3 = 0; q3 < 8; q3++)
			{
				if (Mid[q3] == 1)
					continue;
				Mid[q3] = 1;
				Q[2][q3] = 1;
				X[2] = q3;
				for (int q4 = 0; q4 < 8; q4++)
				{
					if (Mid[q4] == 1)
						continue;
					Mid[q4] = 1;
					Q[3][q4] = 1;
					X[3] = q4;
					for (int q5 = 0; q5 < 8; q5++)
					{
						if (Mid[q5] == 1)
							continue;
						Mid[q5] = 1;
						Q[4][q5] = 1;
						X[4] = q5;
						for (int q6 = 0; q6 < 8; q6++)
						{
							if (Mid[q6] == 1)
								continue;
							Mid[q6] = 1;
							Q[5][q6] = 1;
							X[5] = q6;
							for (int q7 = 0; q7 < 8; q7++)
							{
								if (Mid[q7] == 1)
									continue;
								Mid[q7] = 1;
								Q[6][q7] = 1;
								X[6] = q7;
								for (int q8 = 0; q8 < 8; q8++)
								{
									if (Mid[q8] == 1)
										continue;
									Mid[q8] = 1;
									Q[7][q8] = 1;
									X[7] = q8;

									bool flag = true;
									for (int j = 0; j < 8; j++)
									{
										for (int k = j + 1; k < 8; k++)
										{
											int temp1 = X[k] - X[j];
											int temp2 = k - j;
											if (temp1 == temp2 || temp1 == -temp2)
											{
												flag = false;
												break;
											}
										}
										if (flag == false)
											break;
									}
									if (flag)
									{
										printf("%d\n", ++cnt);
										for (int i = 0; i < 8; i++)
										{
											for (int j = 0; j < 8; j++)
											{
												printf("%d ", Q[i][j]);
											}
											printf("\n");
										}
										printf("\n");
									}
									Mid[q8] = 0;
									Q[7][q8] = 0;
								}
								Mid[q7] = 0;
								Q[6][q7] = 0;
							}
							Mid[q6] = 0;
							Q[5][q6] = 0;
						}
						Mid[q5] = 0;
						Q[4][q5] = 0;
					}
					Mid[q4] = 0;
					Q[3][q4] = 0;
				}
				Mid[q3] = 0;
				Q[2][q3] = 0;
			}
			Mid[q2] = 0;
			Q[1][q2] = 0;
		}
		Mid[q1] = 0;
		Q[0][q1] = 0;
	}
}


int main(void)
{
	int n = 8;

	/*search(n, 0, 0, 0, 0);

	printf("total number of solutions: %d\n", cnt);
	*/
	Queen0();
	
	return 0;
}