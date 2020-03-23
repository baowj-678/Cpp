#include "graph.h"
#include "basic_array_function.h"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>

using namespace::std;
GraphNode* Graph::MSTkruskal()
{
	vector<Edge> heap(this->edges, this->edges + this->num_e);
	make_heap(heap.begin(), heap.end(), Edge::cmp);
	sort_heap(heap.begin(), heap.end(), Edge::cmp);
	return nullptr;
}
GraphNode* Graph::MSTprim()
{
	return nullptr;
}

int** Graph::BFS(Vertex vertex)
{
	if (this->adj_list == nullptr)
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
		ans[i] = new int[this->num_v];
	}
	Color* color = new Color[this->num_v];
	for (int i(0); i < this->num_v; i++)
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
		GraphNode* temp = this->adj_list[u].getNext();
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
	for (int i(0); i < this->num_v; i++)
	{
		std::cout << std::setiosflags(std::ios::right) << std::setw(4) << i + 1;
	}
	std::cout << std::endl;
	std::cout << std::setiosflags(std::ios::left) << std::setw(10) << "distance:";
	for (int i(0); i < this->num_v; i++)
	{
		std::cout << std::setiosflags(std::ios::right) << std::setw(4) << ans[0][i];
	}
	std::cout << std::endl;
	std::cout << std::setiosflags(std::ios::left) << std::setw(10) << "last_node:";
	for (int i(0); i < this->num_v; i++)
	{
		std::cout << std::setiosflags(std::ios::right) << std::setw(4) << ans[1][i] + 1;
	}
	std::cout << std::endl;
	return ans;
}

int** Graph::DFS(Vertex vertex)
{
	Color* color = new Color[this->num_v];
	for (int i(0); i < this->num_v; i++)
		color[i] = White;
	int** ans = zerosTwoDimMatrix<int>(2, this->num_v);
	this->DFSvisit(vertex, 0, color, ans);
	delete[]color;
	return ans;
}

int** Graph::DFSvisit(int u, int time, Color color[], int** ans)
{
	color[u] = Gray;
	time++;
	ans[0][u] = time;
	GraphNode* temp = NULL;
	for (temp = this->adj_list[u].getNext(); temp != NULL; temp = temp->getNext())
	{
		int v = temp->getVertex();
		if (color[v] == White)
		{
			ans[1][v] = u;
			this->DFSvisit(v, time, color, ans);
		}
	}
	color[u] = Black;
}

void Graph::TopoLogicalSort()
{

}

int** Graph::BellmanFord(Vertex s, Vertex v)
{
	int** ans = zerosTwoDimMatrix<int>(2, this->num_v);
	for (int i(0); i < this->num_v; i++)
	{
		ans[0][i] = INF;
		ans[1][i] = NIL;
	}
	ans[0][s] = 0;
	if (this->edges == NULL)
		this->setEdgesFromMatrix();
	for (int i(1); i < this->num_v; i++)
	{
		for (int j(0); j < this->num_e; j++)
		{
			Edge* temp = this->edges[j];
			Distance newValue = ans[0][temp->getFrom()] == INF ? INF : ans[0][temp->getFrom()] + this->getAdjDistance(temp->getFrom(), temp->getTo());
			if (newValue < ans[0][temp->getTo()])
			{
				ans[0][temp->getTo()] = newValue;
				ans[1][temp->getTo()] = temp->getFrom();
			}
		}
	}
	for (int i(0); i < this->num_e; i++)
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