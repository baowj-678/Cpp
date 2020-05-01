#include "FlowGraph.h"
#include "basic_array_function.h"
#include <iostream>
#include <algorithm>

Flow FlowGraph::FordFulkerson(Vertex s, Vertex t)
{
	if (this->edgeMatrix == NULL)
		this->inputFlowGraph();
	//get memory
	std::vector<Edge*> path;
	Flow maxFlow = 0;
	Flow extendFlow;
	bool* isVisited = new bool[this->numVertex];
	int i, j, k;
	Flow** ResidualNetwork = zerosTwoDimMatrix<Flow>(this->numVertex, this->numVertex);
	//initialize RsidualNetwork
	for (i = 0; i < this->numVertex; i++)
	{
		for (j = 0; i < this->numVertex; j++)
		{
			ResidualNetwork[i][j] = this->edgeMatrix[i][j]->getDistance();
		}
		isVisited[i] = false;
	}
	//
	for (i = 0; i < 1000; i++)
	{
		extendFlow = this->FordFulkersonMaxFlow(path, ResidualNetwork, isVisited, s, t);
		if (extendFlow > 0)
		{
			maxFlow += extendFlow;
			while (path.empty() == false)
			{
				Edge* temp = path.back();
				path.pop_back();
				ResidualNetwork[temp->getFrom()][temp->getTo()] -= extendFlow;
			}
		}
		else
		{
			break;
		}
	}
	delTwoDimMatrix<Flow>(ResidualNetwork, this->numVertex);
	delete[]isVisited;
	return maxFlow;
}

Flow FlowGraph::FordFulkersonMaxFlow(std::vector<Edge*> path, Flow** ResidualNetwork, bool* isVisited, Vertex s, Vertex t)
{
	int i;
	Flow maxFlow = 0;
	Edge* edge;
	Vertex m;
	for (i = 0; i < this->numVertex; i++)
	{
		edge = this->edgeMatrix[s][i];
		m = edge->getTo();
		if (isVisited[m] == false && ResidualNetwork[s][m] > 0)
		{
			if (m == t)
			{
				path.push_back(edge);
				return ResidualNetwork[s][m];
			}
			else
			{
				isVisited[m] = true;
				path.push_back(edge);
				maxFlow = this->FordFulkersonMaxFlow(path, ResidualNetwork, isVisited, m, t);
				if (maxFlow > 0)
				{
					return min(maxFlow, ResidualNetwork[s][m]);
				}
				else
				{
					path.pop_back();
					isVisited[m] = false;
				}
			}

		}
	}
	return maxFlow;
}

void FlowGraph::getEdgeMatrixSpace()
{
	if (this->edgeMatrix != NULL)
		return;
	this->edgeMatrix = new Edge * *[this->numVertex];
	if (this->edgeMatrix != NULL)
	{
		for (int i(0); i < this->numVertex; i++)
		{
			this->edgeMatrix[i] = new Edge * [this->numVertex];
		}
	}
	return;
}

void FlowGraph::inputFlowGraph()
{
	if (this->edgeMatrix == NULL)
		this->getEdgeMatrixSpace();
	Flow input;
	Edge* temp = NULL;
	std::cout << "Please input flow matrix(distance, 0)\n";
	for (int i(0); i < this->numVertex; i++)
	{
		for (int j(0); j < this->numVertex; j++)
		{
			std::cin >> input;
			this->edgeMatrix[i][j] = new Edge(input, i, j);
		}
	}
}
