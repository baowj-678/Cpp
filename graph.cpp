#include "graph.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <queue>
#define		NIL		-1
#define		INF		-1

Graph::Graph(int v, int e)
{
	this->num_v = v;
	this->num_e = e;
	this->adj_list = NULL;
	this->adj_matrix = NULL;
}

Graph::~Graph()
{
	this->destroyListSpace();
	this->destroyMatrixSpace();
}

GraphNode** Graph::getMatrixSpace()
{
	this->adj_matrix = new GraphNode * [this->num_v];
	if (this->adj_matrix == nullptr)
		return nullptr;
	for (int i(0); i < this->num_v; i++)
	{
		this->adj_matrix[i] = new GraphNode[this->num_v];
		if (this->adj_matrix[i] == nullptr)
		{
			this->adj_matrix = nullptr;
			return nullptr;
		}
	}
	return adj_matrix;
}

bool Graph::destroyMatrixSpace()
{
	if (this->adj_matrix == nullptr)
		return true;
	for (int i(0); i < this->num_v; i++)
	{
		if(this->adj_matrix[i] != nullptr)
		delete[]this->adj_matrix[i];
	}
	delete[]this->adj_matrix;
	return true;
}

GraphNode* Graph::getListSpace()
{
	this->adj_list = new GraphNode[this->num_v];
	return this->adj_list;
}
bool Graph::destroyListSpace()
{
	if (this->adj_list != nullptr)
		delete[]adj_list;
	return true;
}

void Graph::setMatrixIsAdj()
{
	if (this->adj_matrix == nullptr)
		this->getMatrixSpace();
	std::cout << "Please input adjacency matrix(0:not adjacency,1:yes)\n";
	for (int i(0); i < this->num_v; i++)
	{
		for (int j(0); j < this->num_v; j++)
		{
			int temp;
			std::cin >> temp;
			if (temp == 1)
			{
				this->adj_matrix[i][j].setLength(YES);
			}
			else
			{
				this->adj_matrix[i][j].setLength(NO);
			}
		}
	}
}

void Graph::setMatrixDistance()
{
	if (this->adj_matrix == nullptr)
		this->getMatrixSpace();
	std::cout << "Please input adjacency matrix(distance, -1:INF)\n";
	for (int i(0); i < this->num_v; i++)
	{
		for (int j(0); j < this->num_v; j++)
		{
			int temp;
			std::cin >> temp;
			this->adj_matrix[i][j].setLength(temp);
		}
	}
}

void Graph::printAdjMatrix(int w)
{
	if (this->adj_matrix == nullptr)
		return;

	std::cout << std::endl;
	for (int i(0); i <= this->num_v; i++)
		std::cout << std::setiosflags(std::ios::left) << std::setw(4) << i;
	std::cout << std::endl;
	for (int i(0); i < this->num_v; i++)
	{
		std::cout << std::setiosflags(std::ios::left) << std::setw(w) << i + 1;
		for (int j(0); j < this->num_v; j++)
		{
			std::cout << std::setiosflags(std::ios::left) << std::setw(w) << this->adj_matrix[i][j].getLength();
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int** Graph::BFS(int vertex)
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

void Graph::printAdjList(int w)
{
	if (this->adj_list == nullptr)
		return;
	GraphNode* temp = nullptr;
	for (int i(0); i < this->num_v; i++)
	{
		std::cout << (i + 1) << ":  ";
		for (temp = this->adj_list[i].getNext(); temp != nullptr; temp = temp->getNext())
		{
			std::cout << std::setiosflags(std::ios::left) << std::setw(w) << temp->getVertex() + 1;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

bool Graph::setAdjListFromMatrix()
{
	if (this->adj_matrix == NULL)
		return false;
	if (this->adj_list == NULL)
		this->getListSpace();
	GraphNode* temp = nullptr;
	GraphNode* tail = nullptr;
	for (int i(0); i < this->num_v; i++)
	{
		this->adj_list[i] = GraphNode(i, 0);
		tail = &adj_list[i];
		for (int j(0); j < this->num_v; j++)
		{
			int l = this->adj_matrix[i][j].getLength();
			if(l > 0)
			{
				temp = new GraphNode(j, l);
				tail->setNext(temp);
				tail = temp;
			}
		}
	}
	return true;
}

Edge* Graph::getEdgeSpace()
{
	this->edges = new Edge[this->num_e];
	return this->edges;
}

bool Graph::destroyEdgeSpace()
{
	if (this->edges == nullptr)
		return true;
	delete[]this->edges;
	return true;
}

void Graph::setEdgesFromMatrix()
{

}


GraphNode* Graph::MSTkruskal()
{
	return nullptr;
}
GraphNode* Graph::MSTprim()
{
	return nullptr;
}
using namespace::std;
//int main()
//{
//	streambuf* backup;
//	ifstream fin("C:\\Users\\WILL\\Desktop\\in.txt");
//	backup = cin.rdbuf();
//	cin.rdbuf(fin.rdbuf());
//	Graph g = Graph(5, 10);
//	g.setMatrixIsAdj();
//	cin.rdbuf(backup);
//	g.printAdjMatrix();
//	g.setAdjListFromMatrix();
//	g.printAdjList();
//	g.BFS(1);
//	
//}

/*
0 1 0 0 1
1 0 1 1 1
0 1 0 1 0
0 1 1 0 1
1 1 0 1 0
*/