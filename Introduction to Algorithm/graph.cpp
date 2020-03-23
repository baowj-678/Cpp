#include "graph.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <queue>

Graph::Graph(bool isOriented, int v, int e)
{
	this->num_v = v;
	this->num_e = e;
	this->adj_list = NULL;
	this->distanceMatrix = NULL;
	this->edges = nullptr;
	this->isOriented = isOriented;
}

Graph::~Graph()
{
	this->destroyListSpace();
	this->destroyDistanceMatrixSpace();
	this->destroyEdgeSpace();

}

Distance** Graph::getDistanceMatrixSpace()
{
	this->distanceMatrix = new Distance * [this->num_v];
	if (this->distanceMatrix == nullptr)
		return nullptr;
	for (int i(0); i < this->num_v; i++)
	{
		this->distanceMatrix[i] = new Distance[this->num_v];
		if (this->distanceMatrix[i] == nullptr)
		{
			this->distanceMatrix = nullptr;
			return nullptr;
		}
	}
	return distanceMatrix;
}

bool Graph::destroyDistanceMatrixSpace()
{
	if (this->distanceMatrix == nullptr)
		return true;
	for (int i(0); i < this->num_v; i++)
	{
		if(this->distanceMatrix[i] != nullptr)
		delete[]this->distanceMatrix[i];
	}
	delete[]this->distanceMatrix;
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

//void Graph::setAdjBoolMatrix()
//{
//	if (this->adjMatrix == nullptr)
//		this->getBoolMatrixSpace();
//	std::cout << "Please input adjacency matrix(0:not adjacency,1:yes)\n";
//	for (int i(0); i < this->num_v; i++)
//	{
//		for (int j(0); j < this->num_v; j++)
//		{
//			int temp;
//			std::cin >> temp;
//			if (temp == 1)
//			{
//				this->adjDistanceMatrix[i][j].setDistance(YES);
//			}
//			else
//			{
//				this->adjDistanceMatrix[i][j].setDistance(NO);
//			}
//		}
//	}
//}

void Graph::setDistanceMatrix()
{
	if (this->distanceMatrix == nullptr)
		this->getDistanceMatrixSpace();
	std::cout << "Please input adjacency matrix(distance, 21474836473:INF)\n";
	for (int i(0); i < this->num_v; i++)
	{
		for (int j(0); j < this->num_v; j++)
		{
			int temp;
			std::cin >> temp;
			this->distanceMatrix[i][j] = temp;
		}
	}
}

void Graph::printDistanceMatrix(int w)
{
	if (this->distanceMatrix == nullptr)
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
			std::cout << std::setiosflags(std::ios::left) << std::setw(w) << this->distanceMatrix[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
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

bool Graph::setListFromMatrix()
{
	if (this->distanceMatrix == NULL)
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
			int l = this->distanceMatrix[i][j];
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

Edge** Graph::getEdgeSpace()
{
	this->edges = new Edge*[this->num_e];
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
	if (this->distanceMatrix == nullptr)
		return;
	if (this->edges != nullptr)
		return;
	Edge* temp = nullptr;
	Edge* head = nullptr;
	this->num_e = 0;
	if (this->isOriented == true)
	{
		//oriented graph
		for (int i(0); i < this->num_v; i++)
		{
			for (int j(0); j < this->num_v; j++)
			{
				if (this->distanceMatrix[i][j] != INF)
				{
					temp = new Edge(distanceMatrix[i][j], i, j);
					temp->setNext(head);
					head = temp;
					this->num_e++;
				}
			}
		}
	}
	else
	{
		//not oriented graph
		for (int i(0); i < this->num_v; i++)
		{
			for (int j(i); j < this->num_v; j++)
			{
				if (this->distanceMatrix[i][j] != INF)
				{
					temp = new Edge(distanceMatrix[i][j], i, j);
					temp->setNext(head);
					head = temp;
					this->num_e++;
				}
			}
		}
	}
	if (this->num_e == 0)
		return;
	this->getEdgeSpace();
	for (int i = 0; head != nullptr; head = head->getNext(), i++)
	{
		this->edges[i] = head;
	}
}

void Graph::printEdges()
{
	std::cout << "\nEdges(From, Distance, To):\n";
	Edge** temp = this->edges;
	for (int i(0); i < this->num_e; i++)
	{
		std::cout << "(" << temp[i]->getFrom() + 1 << "," << temp[i]->getDistance() << "," << temp[i]->getTo() + 1 << ")  ";
	}
}

Distance Graph::getAdjDistance(Vertex a, Vertex b)
{
	return this->distanceMatrix[a][b];
}
using namespace::std;
int main()
{
	streambuf* backup;
	ifstream fin("C:\\Users\\WILL\\Desktop\\in.txt");
	backup = cin.rdbuf();
	cin.rdbuf(fin.rdbuf());
	Graph g = Graph(false, 5, 10);
	g.setDistanceMatrix();
	g.printDistanceMatrix();
	cin.rdbuf(backup);
	g.setEdgesFromMatrix();
	g.printEdges();
	//g.setAdjListFromMatrix();
	//g.printAdjList();
	//g.BFS(1);
}

/*
0 1 0 0 1
1 0 1 1 1
0 1 0 1 0
0 1 1 0 1
1 1 0 1 0
*/