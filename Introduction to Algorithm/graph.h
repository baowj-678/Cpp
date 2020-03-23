#ifndef _GRAPH_
#define _GRAPH_
#include "graph_node.h"
#include "graph_edge.h"
class Graph 
{
public:
    Graph(bool isOriented, int v, int e);
    ~Graph();
    //set adjacency matrix using 0-1 for not connecting and connecting
    void setMatrixIsAdj();
    //set adjacency matrix using distance,-1 for INF
    void setMatrixDistance();
    //print adjacency matrix(distance)
    void printAdjMatrix(int w = 4);
    //print adjacency list(distance)
    void printAdjList(int w = 4);
    bool setAdjListFromMatrix();
    //get values of edges
    void setEdgesFromMatrix();
    //print edges
    void printEdges();
    int** BFS(int vertex);
    int** DFS(int vertex);
    GraphNode* MSTkruskal();
    GraphNode* MSTprim();

private:
    //is oriented graph
    bool isOriented;
    //
    GraphNode** adj_matrix;
    //
    GraphNode* adj_list;
    //store edges
    Edge** edges;
    int num_v;
    int num_e;


    //functions
    GraphNode** getMatrixSpace();
    bool destroyMatrixSpace();
    GraphNode* getListSpace();
    bool destroyListSpace();
    Edge** getEdgeSpace();
    bool destroyEdgeSpace();
};


#endif // !_GRAPH_
