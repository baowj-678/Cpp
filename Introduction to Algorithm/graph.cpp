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


void Graph::inputDistanceMatrix()
{
	if (this->distanceMatrix == nullptr)
		this->getDistanceMatrixSpace();
	std::string input;
	std::cout << "Please input adjacency matrix(distance, inf)\n";
	for (int i(0); i < this->numVertex; i++)
	{
		for (int j(0); j < this->numVertex; j++)
		{
			std::cin >> input;
			if (input == "inf")
				this->distanceMatrix[i][j] = INF;
			else
				this->distanceMatrix[i][j] = atoi(input.c_str());
		}
	}
}

void Graph::inputBoolMatrix()
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
void Graph::printDistanceMatrix(int w, std::string out, Distance** distance)
{
	if (distance == NULL)
		distance = this->distanceMatrix;
	if (distance == NULL)
		return;
	std::cout << out;
	std::string inf = "inf";
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
			if(distance[i][j] == INF)
				std::cout << std::setiosflags(std::ios::left) << std::setw(w) << inf;
			else
				std::cout << std::setiosflags(std::ios::left) << std::setw(w) << distance[i][j];
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

bool Graph::destroyEdgeSpace()
{
	if (this->edges == nullptr)
		return true;
	delete[]this->edges;
	return true;
}

void Graph::setEdgesFromMatrix()
{
	if (this->edges != NULL)
		return;
	if (this->distanceMatrix == NULL)
		return;
	//set edge list
	Edge* head = NULL;
	Edge* temp = NULL;
	this->numEdge = 0;
	for (int i(0); i < this->numVertex; i++)
	{
		for (int j(0); j < this->numVertex; j++)
		{
			if (this->distanceMatrix[i][j] != INF)
			{
				temp = new Edge(this->distanceMatrix[i][j], i, j);
				temp->setNext(head);
				head = temp->getNext();
				this->numEdge++;
			}
		}
	}
	//set edge array
	this->getEdgeSpace();
	for (int i(0); i < this->numEdge; i++, head = head->getNext())
	{
		this->edges[i] = head;
	}
}

void Graph::getEdgeSpace()
{
	if (this->edges != NULL)
		delete[]this->edges;
	this->edges = new Edge * [this->numEdge];
}

void Graph::printEdges()
{
	//
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
//int main()
//{
//	streambuf* backup;
//	ifstream fin("C:\\Users\\WILL\\Desktop\\in.txt");
//	backup = cin.rdbuf();
//	cin.rdbuf(fin.rdbuf());
//	Graph g = Graph(true, 5, 10);
//	g.setNameIndexMap(true);
//	g.inputDistanceMatrix();
//	g.printDistanceMatrix(5);
//	cin.rdbuf(backup);
//	//g.getTwoVertexShortPath();
//	g.getAllPairShortPath();
//	
//}

/*
0 1 0 0 1
1 0 1 1 1
0 1 0 1 0
0 1 1 0 1
1 1 0 1 0
*/