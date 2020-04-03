#pragma once
#include "graph_edge.h"
#include <vector>

typedef int Vertex;
typedef int Flow;
class FlowGraph
{
private:
	Edge*** edgeMatrix;
	int numVertex;

public:
	void inputFlowGraph();
	Flow FordFulkerson(Vertex s, Vertex t);
	Flow FordFulkersonMaxFlow(std::vector<Edge*> path, Flow** ResidualNetwork, bool* isVisited, Vertex s, Vertex t);
	void getEdgeMatrixSpace();
};