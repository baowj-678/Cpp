#ifndef _GRAPH_
#define _GRAPH_
#include "graph_const.h"
#include "graph_node.h"
#include "graph_edge.h"
#include <string>
#include <map>

class Graph 
{
public:
    Graph(bool isOriented, int v, int e);
    ~Graph();
    //set adjacency matrix using 0-1 for not connecting and connecting
    void inputBoolMatrix();
    //set adjacency matrix using distance,-1 for INF
    void inputDistanceMatrix();
    //print adjacency matrix(distance)
    void printDistanceMatrix(int w = 4);
    // false:input manually; true:0-1,1-2...
    void setNameIndexMap(int isDefault = true);
    //print bool matrix
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
    void getTwoVertexShortPath();
    //
    Distance getAdjDistance(Vertex a, Vertex b);
    

private:
    //is oriented graph
    bool isOriented;
    //boolean adjacency matrix
    bool** booleanMatrix;
    //distance adjacency matrix
    Distance** distanceMatrix;
    //adjacency list array
    GraphNode* adjList;
    //store edges
    Edge** edges;
    //name to index map
    std::map<std::string, int>name2index;
    //index to name map
    std::map<int, std::string>index2name;
    int numVertex;
    int numEdge;


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
    void printPathFromPiMatrix(int** ans, Vertex from, Vertex to);
    int** BellmanFordInner(Vertex u, Vertex s);
    Distance** allPairsShortPathExtendAlgorithm();
};


#endif // !_GRAPH_
