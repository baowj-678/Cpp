#include "graph.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <queue>

Graph::Graph(bool isOriented, int v, int e)
{
	this->numVertex = v;
	this->numEdge = e;
	this->adjList = NULL;
	this->distanceMatrix = NULL;
	this->booleanMatrix = NULL;
	this->edges = nullptr;
	this->isOriented = isOriented;
}

Graph::~Graph()
{
	this->destroyListSpace();
	this->destroyDistanceMatrixSpace();
	this->destroyBooleanMatrixSpace();
	this->destroyEdgeSpace();

}

Distance** Graph::getDistanceMatrixSpace()
{
	if (this->distanceMatrix == NULL)
		this->distanceMatrix = new Distance * [this->numVertex];
	else
		return this->distanceMatrix;

	if (this->distanceMatrix == NULL)
		return NULL;
	for (int i(0); i < this->numVertex; i++)
	{
		this->distanceMatrix[i] = new Distance[this->numVertex];
		if (this->distanceMatrix[i] == NULL)
		{
			this->distanceMatrix = NULL;
			return NULL;
		}
	}
	return this->distanceMatrix;
}

bool** Graph::getBooleanMatrixSpace()
{
	if (this->booleanMatrix == NULL)
		this->booleanMatrix = new bool* [this->numVertex];
	else
		return this->booleanMatrix;

	if (this->booleanMatrix == nullptr)
		return nullptr;
	for (int i(0); i < this->numVertex; i++)
	{
		this->booleanMatrix[i] = new bool[this->numVertex];
		if (this->booleanMatrix[i] == nullptr)
		{
			this->booleanMatrix = nullptr;
			return nullptr;
		}
	}
	return this->booleanMatrix;
}
bool Graph::destroyDistanceMatrixSpace()
{
	if (this->distanceMatrix != nullptr)
	{
		for (int i(0); i < this->numVertex; i++)
		{
			if (this->distanceMatrix[i] != nullptr)
				delete[]this->distanceMatrix[i];
		}
		delete[]this->distanceMatrix;
	}
	return true;
}

GraphNode* Graph::getListSpace()
{
	this->adjList = new GraphNode[this->numVertex];
	return this->adjList;
}
bool Graph::destroyListSpace()
{
	if (this->adjList != nullptr)
		delete[]adjList;
	return true;
}


void Graph::setDistanceMatrix()
{
	if (this->distanceMatrix == nullptr)
		this->getDistanceMatrixSpace();
	std::cout << "Please input adjacency matrix(distance, 2147483647:INF)\n";
	for (int i(0); i < this->numVertex; i++)
	{
		for (int j(0); j < this->numVertex; j++)
		{
			int temp;
			std::cin >> temp;
			this->distanceMatrix[i][j] = temp;
		}
	}
}

void Graph::setBoolMatrix()
{
	if (this->booleanMatrix == nullptr)
		this->getBooleanMatrixSpace();
	std::cout << "Please input adjacency boolean matrix(0:false, 1:true)\n";
	for (int i(0); i < this->numVertex; i++)
	{
		for (int j(0); j < this->numVertex; j++)
		{
			int temp;
			std::cin >> temp;
			if (temp == 0)
				this->booleanMatrix[i][j] = false;
			else
				this->booleanMatrix[i][j] = true;
		}
	}
}
void Graph::printDistanceMatrix(int w)
{
	if (this->distanceMatrix == nullptr)
		return;
	std::cout << "\nThe distance matrix is:\n";
	// print index
	if(this->index2name.empty() == false)
		for (int i(-1); i < this->numVertex; i++)
			std::cout << std::setiosflags(std::ios::left) << std::setw(w) << this->index2name[i];
	else
		for (int i(-1); i < this->numVertex; i++)
			std::cout << std::setiosflags(std::ios::left) << std::setw(w) << i;
	std::cout << std::endl;

	for (int i(0); i < this->numVertex; i++)
	{
		// print index
		if(this->index2name.empty() == false)
			std::cout << std::setiosflags(std::ios::left) << std::setw(w) << this->index2name[i];
		else
			std::cout << std::setiosflags(std::ios::left) << std::setw(w) << i;
		
		// print distance
		for (int j(0); j < this->numVertex; j++)
		{
			std::cout << std::setiosflags(std::ios::left) << std::setw(w) << this->distanceMatrix[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Graph::printBooleanMatrix(int w)
{
	if (this->booleanMatrix == nullptr)
		return;
	std::cout << "\nThe boolean matrix is:\n";
	// print index
	if (this->index2name.empty() == false)
		for (int i(-1); i < this->numVertex; i++)
			std::cout << std::setiosflags(std::ios::left) << std::setw(w) << this->index2name[i];
	else
		for (int i(-1); i < this->numVertex; i++)
			std::cout << std::setiosflags(std::ios::left) << std::setw(w) << i;
	std::cout << std::endl;

	for (int i(0); i < this->numVertex; i++)
	{
		// print index
		if (this->index2name.empty() == false)
			std::cout << std::setiosflags(std::ios::left) << std::setw(w) << this->index2name[i];
		else
			std::cout << std::setiosflags(std::ios::left) << std::setw(w) << i;

		// print distance
		for (int j(0); j < this->numVertex; j++)
		{
			std::cout << std::setiosflags(std::ios::left) << std::setw(w) << this->booleanMatrix[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

}

void Graph::printAdjList(int w)
{
	if (this->adjList == nullptr)
		return;
	GraphNode* temp = nullptr;
	for (int i(0); i < this->numVertex; i++)
	{
		std::cout << (i + 1) << ":  ";
		for (temp = this->adjList[i].getNext(); temp != nullptr; temp = temp->getNext())
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
	if (this->adjList == NULL)
		this->getListSpace();
	GraphNode* temp = nullptr;
	GraphNode* tail = nullptr;
	for (int i(0); i < this->numVertex; i++)
	{
		this->adjList[i] = GraphNode(i, 0);
		tail = &adjList[i];
		for (int j(0); j < this->numVertex; j++)
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
	this->edges = new Edge*[this->numEdge];
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
	this->numEdge = 0;
	if (this->isOriented == true)
	{
		//oriented graph
		for (int i(0); i < this->numVertex; i++)
		{
			for (int j(0); j < this->numVertex; j++)
			{
				if (this->distanceMatrix[i][j] != INF)
				{
					temp = new Edge(distanceMatrix[i][j], i, j);
					temp->setNext(head);
					head = temp;
					this->numEdge++;
				}
			}
		}
	}
	else
	{
		//not oriented graph
		for (int i(0); i < this->numVertex; i++)
		{
			for (int j(i); j < this->numVertex; j++)
			{
				if (this->distanceMatrix[i][j] != INF)
				{
					temp = new Edge(distanceMatrix[i][j], i, j);
					temp->setNext(head);
					head = temp;
					this->numEdge++;
				}
			}
		}
	}
	if (this->numEdge == 0)
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
	for (int i(0); i < this->numEdge; i++)
	{
		std::cout << "(" << temp[i]->getFrom() + 1 << "," << temp[i]->getDistance() << "," << temp[i]->getTo() + 1 << ")  ";
	}
}

Distance Graph::getAdjDistance(Vertex a, Vertex b)
{
	return this->distanceMatrix[a][b];
}
using namespace::std;

void Graph::setBooleanFromDistance()
{
	if (this->booleanMatrix == NULL)
		this->getBooleanMatrixSpace();

	for (int i(0); i < this->numVertex; i++)
	{
		for (int j(0); j < this->numVertex; j++)
		{
			if (this->getAdjDistance(i, j) == INF)
				this->booleanMatrix[i][j] = false;
			else
				this->booleanMatrix[i][j] = true;
		}
	}
}

bool Graph::destroyBooleanMatrixSpace()
{
	if (this->booleanMatrix != NULL)
	{
		for (int i(0); i < this->numVertex; i++)
		{
			if (this->booleanMatrix[i] != NULL)
				delete[]this->booleanMatrix[i];
		}
		delete[]this->booleanMatrix;
	}
	return true;
}

void Graph::setNameIndexMap(int isDefault)
{
	// default
	if (isDefault)
	{
		for (int i(0); i < this->numVertex; i++)
		{
			string name = to_string(i + 1);
			this->name2index[name] = i;
			this->index2name[i] = name;
		}
		return;
	}

	// input
	cout << "\nPlease input the NameIndexMap,like :(1 s)\n";
	int index;
	string name;
	for (int i(0); i < this->numVertex; i++)
	{
		cin >> index;
		cin >> name;
		this->name2index[name] = index - 1;
		this->index2name[index - 1] = name;
	}
}
int main()
{
	streambuf* backup;
	ifstream fin("C:\\Users\\WILL\\Desktop\\in.txt");
	backup = cin.rdbuf();
	cin.rdbuf(fin.rdbuf());
	Graph g = Graph(true, 5, 10);
	g.setNameIndexMap(false);
	g.setDistanceMatrix();
	g.printDistanceMatrix(15);
	cin.rdbuf(backup);
	g.getVertexDistance();
}

/*
0 1 0 0 1
1 0 1 1 1
0 1 0 1 0
0 1 1 0 1
1 1 0 1 0
*/