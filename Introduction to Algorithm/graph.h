#ifndef _GRAPH_
#define _GRAPH_
#include "graph_node.h"
#include "graph_edge.h"
#define		NIL		-1
#define		INF		21474836473
typedef int Vertex;
class Graph 
{
public:
    Graph(bool isOriented, int v, int e);
    ~Graph();
    //set adjacency matrix using 0-1 for not connecting and connecting
    void setBoolMatrix();
    //set adjacency matrix using distance,-1 for INF
    void setDistanceMatrix();
    //print adjacency matrix(distance)
    void printDistanceMatrix(int w = 4);
    //
    void printBooleanMatrix(int w = 4);
    //print adjacency list(distance)
    void printAdjList(int w = 4);
    bool setListFromMatrix();
    //get values of edges
    void setEdgesFromMatrix();
    //print edges
    void printEdges();
    int** BFS(Vertex vertex);
    int** DFS(Vertex vertex);
    int** DFSvisit(Vertex vertex, int time, Color color[], int** ans);
    GraphNode* MSTkruskal();
    GraphNode* MSTprim();
    void TopoLogicalSort();
    int** BellmanFord(Vertex u, Vertex s);
    //
    Distance getAdjDistance(Vertex a, Vertex b);

private:
    //is oriented graph
    bool isOriented;
    //boolean adjacency matrix
    bool** booleanMatrix;
    //distance adjacency matrix
    Distance** distanceMatrix;
    //
    GraphNode* adj_list;
    //store edges
    Edge** edges;
    int num_v;
    int num_e;


    //functions
    Distance** getDistanceMatrixSpace();
    bool destroyDistanceMatrixSpace();
    bool** getBooleanMatrixSpace();
    bool destroyBooleanMatrixSpace();
    GraphNode* getListSpace();
    bool destroyListSpace();
    Edge** getEdgeSpace();
    bool destroyEdgeSpace();
    void setBooleanFromDistance();
};


#endif // !_GRAPH_
