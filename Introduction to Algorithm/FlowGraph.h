#pragma once
#include "graph_edge.h"
#include <vector>

typedef int Vertex;
typedef int Flow;

class FlowGraph
{
private:
    Distance** distanceMatrix;
    //adjacency list array
    GraphNode* adjList;
    //store edges array/list
    Edge** edges;
    //name to index map
    std::map<std::string, int>name2index;
    //index to name map
    std::map<int, std::string>index2name;
    int numVertex;
    int numEdge;

public:
	void inputFlowGraph();
	Flow FordFulkerson(Vertex s, Vertex t);
	Flow FordFulkersonMaxFlow(std::vector<Edge*> path, Flow** ResidualNetwork, bool* isVisited, Vertex s, Vertex t);
	void getEdgeMatrixSpace();
};


Edge*** edgeMatrix;
int numVertex;