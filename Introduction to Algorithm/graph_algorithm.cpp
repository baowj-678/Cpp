#include "graph.h"
#include "basic_array_function.h"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <vector>

using namespace::std;

GraphNode* Graph::MSTkruskal()
{
	//vector<Edge> heap(this->edges, this->edges + this->numEdge);
	//make_heap(heap.begin(), heap.end(), &(Edge::cmp));
	//sort_heap(heap.begin(), heap.end(), &(Edge::cmp));
	return nullptr;
}

GraphNode* Graph::MSTprim()
{
	return nullptr;
}

int** Graph::BFS(Vertex vertex)
{
	if (this->adjList == nullptr)
		return nullptr;
	//input vertex [0-...)
	vertex--;
	//get memory
	//ans[0][i] = d[i]
	//ans[1][i] = pi[i]
	int** ans = new int* [2];
	if (ans == NULL)
		return NULL;
	for (int i(0); i < 2; i++)
	{
		ans[i] = new int[this->numVertex];
	}
	Color* color = new Color[this->numVertex];
	for (int i(0); i < this->numVertex; i++)
	{
		color[i] = White;
		ans[0][i] = INF;
		ans[1][i] = NIL;
	}
	color[vertex] = Gray;
	ans[0][vertex] = 0;
	ans[1][vertex] = NIL;
	std::queue<int> Q;
	Q.push(vertex);
	for (; Q.empty() == false;)
	{
		int u = Q.front();
		Q.pop();
		GraphNode* temp = this->adjList[u].getNext();
		for (; temp != nullptr; temp = temp->getNext())
		{
			int v = temp->getVertex();
			if (color[v] == White)
			{
				color[v] = Gray;
				ans[0][v] = ans[0][u] + 1;
				ans[1][v] = u;
				Q.push(v);
			}
		}
		color[u] = Black;
	}
	std::cout << std::endl;
	std::cout << std::setiosflags(std::ios::left) << std::setw(10) << "name:";
	for (int i(0); i < this->numVertex; i++)
	{
		std::cout << std::setiosflags(std::ios::right) << std::setw(4) << i + 1;
	}
	std::cout << std::endl;
	std::cout << std::setiosflags(std::ios::left) << std::setw(10) << "distance:";
	for (int i(0); i < this->numVertex; i++)
	{
		std::cout << std::setiosflags(std::ios::right) << std::setw(4) << ans[0][i];
	}
	std::cout << std::endl;
	std::cout << std::setiosflags(std::ios::left) << std::setw(10) << "last_node:";
	for (int i(0); i < this->numVertex; i++)
	{
		std::cout << std::setiosflags(std::ios::right) << std::setw(4) << ans[1][i] + 1;
	}
	std::cout << std::endl;
	return ans;
}

int** Graph::DFS(Vertex vertex)
{
	Color* color = new Color[this->numVertex];
	for (int i(0); i < this->numVertex; i++)
		color[i] = White;
	int** ans = zerosTwoDimMatrix<int>(2, this->numVertex);
	this->DFSvisit(vertex, 0, color, ans);
	delete[]color;
	return ans;
}

int** Graph::DFSvisit(Vertex u, int time, Color color[], int** ans)
{
	color[u] = Gray;
	time++;
	ans[0][u] = time;
	GraphNode* temp = NULL;
	for (temp = this->adjList[u].getNext(); temp != NULL; temp = temp->getNext())
	{
		int v = temp->getVertex();
		if (color[v] == White)
		{
			ans[1][v] = u;
			this->DFSvisit(v, time, color, ans);
		}
	}
	color[u] = Black;
	return ans;
}

void Graph::TopoLogicalSort()
{

}

int** Graph::BellmanFordInner(Vertex s, Vertex v)
{
	// ans[0][i] = d[i]
	// ans[1][i] = pi[i]
	int** ans = zerosTwoDimMatrix<int>(2, this->numVertex);
	for (int i(0); i < this->numVertex; i++)
	{
		ans[0][i] = INF;
		ans[1][i] = NIL;
	}
	ans[0][s] = 0;
	if (this->edges == NULL)
		this->setEdgesFromMatrix();
	for (int i(1); i < this->numVertex; i++)
	{
		for (int j(0); j < this->numEdge; j++)
		{
			Edge* temp = this->edges[j];
			Distance from = ans[0][temp->getFrom()];
			Distance between = this->getAdjDistance(temp->getFrom(), temp->getTo());
			Distance newValue = (from == INF || between == INF) ? INF : from + between;
			if (newValue < ans[0][temp->getTo()])
			{
				ans[0][temp->getTo()] = newValue;
				ans[1][temp->getTo()] = temp->getFrom();
			}
		}
	}
	for (int i(0); i < this->numEdge; i++)
	{
		Edge* temp = this->edges[i];
		if (ans[0][temp->getTo()] > ans[0][temp->getFrom()] + this->getAdjDistance(temp->getFrom(), temp->getTo()))
		{
			delTwoDimMatrix<int>(ans, 2);
			return NULL;
		}
	}
	return ans;
}

void Graph::printPathFromPiMatrix(int** ans, Vertex from, Vertex to)
{
	Vertex* way = new Vertex[this->numVertex];
	int index = 0;
	way[index] = to;
	while (ans[1][to] != from)
	{
		to = ans[1][to];
		way[++index] = to;
	}
	way[++index] = from;
	cout << "\nThe shortest way is:\n";
	for (index; index > 0; index--)
		cout << this->index2name[way[index]] << " -> ";
	cout << this->index2name[way[0]] << endl << endl;
}

void Graph::getTwoVertexShortPath()
{
	while (true)
	{
		cout << "\nPlease input two vertexs' names('go out'to exit):\n";
		string from, to;
		cin >> from >> to;
		if (from == "go" && to == "out")
			break;
		Vertex f, t;
		f = this->name2index[from];
		t = this->name2index[to];
		int** ans = this->BellmanFordInner(f, t);
		if (ans == NULL)
			cout << "\nNo Answer!\n";
		else
		{
			cout << "\nThe shortest distance is:\n" << ans[0][t] << endl;
			this->printPathFromPiMatrix(ans, f, t);
			delTwoDimMatrix(ans, 2);
		}
	}
	cout << "\nExit Successfully!\n";
}

// all pairs short path Extend Algorithm
Distance** Graph::apspExtendAlgorithm()
{
	Distance** paths = zerosTwoDimMatrix<Distance>(this->numVertex, this->numVertex);
	Distance** copy = zerosTwoDimMatrix<Distance>(this->numVertex, this->numVertex);
	if (this->distanceMatrix == NULL)
	{
		this->inputDistanceMatrix();
	}
	int i, j, k, t;
	for (i = 0; i < this->numVertex; i++)
	{
		for (j = 0; j < this->numVertex; j++)
		{
			paths[i][j] = this->distanceMatrix[i][j];
		}
	}

	for (t = 1; t < this->numVertex; t++)
	{
		for (i = 0; i < this->numVertex; i++)
		{
			for (j = 0; j < this->numVertex; j++)
			{
				copy[i][j] = INF;
				for (k = 0; k < this->numVertex; k++)
				{
					if (paths[i][k] == INF || this->distanceMatrix[k][j] == INF)
						continue;
					else
					{
						Distance newDis = paths[i][k] + this->distanceMatrix[k][j];
						if (newDis < copy[i][j])
							copy[i][j] = newDis;
					}
				}
			}
		}
		for (i = 0; i < this->numVertex; i++)
		{
			for (j = 0; j < this->numVertex; j++)
			{
				paths[i][j] = copy[i][j];
			}
		}
	}
	delete[] copy;
	return paths;
}

// all pairs short path Floyd Warshall Algorithm
Distance** Graph::apspFloydWarshallAlgorithm()
{
	//initialize
	Distance** distance = zerosTwoDimMatrix<Distance>(this->numVertex, this->numVertex);
	Distance** copy = zerosTwoDimMatrix<Distance>(this->numVertex, this->numVertex);
	if (this->distanceMatrix == NULL)
	{
		this->inputDistanceMatrix();
	}
	int i, j, t;
	for (i = 0; i < this->numVertex; i++)
	{
		for (j = 0; j < this->numVertex; j++)
		{
			distance[i][j] = this->distanceMatrix[i][j];
		}
	}

	//
	for (t = 0; t < this->numVertex; t++)
	{
		for (i = 0; i < this->numVertex; i++)
		{
			for (j = 0; j < this->numVertex; j++)
			{
				if (distance[i][t] != INF && distance[t][j] != INF)
					copy[i][j] = min(distance[i][j], distance[i][t] + distance[t][j]);
				else
					copy[i][j] = distance[i][j];
			}
		}
		for (i = 0; i < this->numVertex; i++)
		{
			for (j = 0; j < this->numVertex; j++)
			{
				distance[i][j] = copy[i][j];
			}
		}
	}
	delete[] copy;
	return distance;
}

void Graph::getAllPairShortPath()
{
	Distance** distance;
	cout << "\nInput \n'1',for Extend algorithm;\n'2',for Floyd Warshall algorithm;\n'0',for exit:\n";
	int flag;
	cin >> flag;
	if (flag == 1)
		distance = this->apspExtendAlgorithm();
	else if (flag == 2)
		distance = this->apspFloydWarshallAlgorithm();
	else
		return;
	string out =  "\nThe shortest distance between vertexs are:\n";
	this->printDistanceMatrix(5, out, distance);
	delTwoDimMatrix<Distance>(distance, this->numVertex);
}

