#include "graph.h"
#include <iostream>
#include <iomanip>
Graph::Graph(int v, int e)
{
	this->v = v;
	this->e = e;
	this->adj_list = nullptr;
	this->adj_matrix = nullptr;
}

Graph::~Graph()
{
	this->destroyListSpace();
	this->destroyMatrixSpace();
}

GraphNode** Graph::getMatrixSpace()
{
	this->adj_matrix = new GraphNode * [this->v];
	if (this->adj_matrix == nullptr)
		return nullptr;
	for (int i(0); i < this->v; i++)
	{
		this->adj_matrix[i] = new GraphNode[this->v];
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
	for (int i(0); i < this->v; i++)
	{
		if(this->adj_matrix[i] != nullptr)
		delete[]this->adj_matrix[i];
	}
	delete[]this->adj_matrix;
	return true;
}
GraphNode* Graph::getListSpace()
{
	this->adj_list = new GraphNode[this->v];
	return this->adj_list;
}
bool Graph::destroyListSpace()
{
	if (this->adj_list != nullptr)
		delete[]adj_list;
	return true;
}

void Graph::setMatrix()
{
	std::cout << "Please input adjacency matrix\n";
	for (int i(0); i < this->v; i++)
	{
		for (int j(0); j < this->v; j++)
		{
			int temp;
			std::cin >> temp;
			this->adj_matrix[i][j].setVertex(temp);
		}
	}
}

void Graph::printAdjMatrix(int w =4)
{
	int width = w;
	for (int i(0); i <= this->v; i++)
		std::cout << i << std::setw(width);
	std::cout << std::endl;
	for (int i(0); i < this->v; i++)
	{
		std::cout << i + 1 << std::setw(width);
		for (int j(0); j < this->v; j++)
		{
			std::cout << this->adj_matrix[i][j].getVertex << std::setw(width);
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}