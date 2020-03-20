#ifndef _GRAPH_
#define _GRAPH_
#include "graph_node.h"
class Graph 
{
public:
    Graph(int v, int e);
    ~Graph();
    void setMatrix();
    void printAdjMatrix(int w = 4);
private:
    //variables
    GraphNode** adj_matrix;
    GraphNode* adj_list;
    int v;
    int e;

    //functions
    GraphNode** getMatrixSpace();
    bool destroyMatrixSpace();
    GraphNode* getListSpace();
    bool destroyListSpace();
};


#endif // !_GRAPH_
