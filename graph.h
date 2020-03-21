#ifndef _GRAPH_
#define _GRAPH_
#include "graph_node.h"
class Graph 
{
public:
    Graph(int v, int e);
    ~Graph();
    void setMatrixIsAdj();
    void printAdjMatrix(int w = 4);
    void printAdjList(int w = 4);
    bool setAdjListFromMatrix();
    int** BFS(int vertex);
private:
    //variables
    GraphNode** adj_matrix;
    GraphNode* adj_list;
    int num_v;
    int num_e;

    //functions
    GraphNode** getMatrixSpace();
    bool destroyMatrixSpace();
    GraphNode* getListSpace();
    bool destroyListSpace();
};


#endif // !_GRAPH_
