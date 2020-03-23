#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MAX 100
#define INF 99999


typedef struct graph
{
    char vexs[MAX];       // 顶点集合
    int vexnum;           // 顶点数
    int edgnum;           // 边数
    int matrix[MAX][MAX]; // 邻接矩阵
}Graph, * PGraph;

// 边的结构体
typedef struct EdgeData
{
    char start; // 边的起点
    char end;   // 边的终点
    int weight; // 边的权重
}EData;



//G：图，root起始节点，prev每个节点最短路的前驱节点，dist每个节点的最短路
void dijkstra(Graph G, int root, int prev[], int dist[])
{
    int i, j, k;
    int min;
    int tmp;
    int flag[MAX];      // flag[i]=1表示"顶点vs"到"顶点i"的最短路径已成功获取。

    // 初始化
    for (i = 0; i < G.vexnum; i++)
    {
        flag[i] = 0;              // 顶点i的最短路径还没获取到。
        prev[i] = 0;              // 顶点i的前驱顶点为0。
        dist[i] = G.matrix[root][i];// 顶点i的最短路径为"顶点vs"到"顶点i"的权。
    }

    // 对"顶点vs"自身进行初始化
    flag[root] = 1;
    dist[root] = 0;

    // 遍历G.vexnum-1次；每次找出一个顶点的最短路径。
    for (i = 1; i < G.vexnum; i++)
    {
        // 寻找当前最小的路径；k为顶点
        min = MAX;
        for (j = 0; j < G.vexnum; j++)
        {
            if (flag[j] == 0 && dist[j] < min)
            {
                min = dist[j];
                k = j;
            }
        }
        // 标记"顶点k"为已经获取到最短路径
        flag[k] = 1;

        // 更新修正当前最短路径和前驱顶点
        for (j = 0; j < G.vexnum; j++)
        {

            tmp = (G.matrix[k][j] == INF ? INF : (min + G.matrix[k][j])); // 防止溢出
            if (flag[j] == 0 && (tmp < dist[j]))
            {
                dist[j] = tmp;
                prev[j] = k;
            }
        }
    }

    // 打印dijkstra最短路径的结果
    printf("dijkstra(%c): \n", G.vexs[root]);
    for (i = 0; i < G.vexnum; i++)
        printf("  shortest(%d, %d)=%d\n", G.vexs[root], G.vexs[i], dist[i]);
}

int main()
{
    char vexs[100];
    int matrix[100][100];
    int vlen = 7;
    int i, j;
    printf("Please input the number of points\n");
    scanf_s("%d", &vlen);
    for (i = 0; i < vlen; i++)
        vexs[i] = i;
    printf("Please input the matrix of graph, -1 represents the MAX\n");
    for (i = 0; i < vlen; i++)
    {
        for (j = 0; j < vlen; j++)
        {
            scanf_s("%d", &matrix[i][j]);
        }
    }

    Graph* pG;

    // 输入"顶点数"和"边数"
    if ((pG = (Graph*)malloc(sizeof(Graph))) == NULL)
        return NULL;
    memset(pG, 0, sizeof(Graph));

    // 初始化"顶点数"
    pG->vexnum = vlen;
    // 初始化"顶点"
    for (i = 0; i < pG->vexnum; i++)
        pG->vexs[i] = vexs[i];

    // 初始化"边"
    for (i = 0; i < pG->vexnum; i++)
        for (j = 0; j < pG->vexnum; j++)
            pG->matrix[i][j] = (matrix[i][j] == -1)? INF : matrix[i][j];

    // 统计边的数目
    for (i = 0; i < pG->vexnum; i++)
        for (j = 0; j < pG->vexnum; j++)
            if (i != j && pG->matrix[i][j] != INF)
                pG->edgnum++;
    pG->edgnum /= 2;
    int prev[MAX] = { 0 };
    int dist[MAX] = { 0 };

    dijkstra(*pG, 0, prev, dist);
}