#pragma once
#include "graph_const.h"

enum Color
{
	Black,
	Gray,
	White
};

enum YesOrNo
{
	Yes,
	No
};

class GraphNode 
{
private:
	Vertex vertex;
	//Distance distance;
	GraphNode* next;
public:
	GraphNode(int vertex);
	GraphNode(int vertex, int length);
	GraphNode();
	Vertex getVertex();
	int printVertex();
	//Distance getDistance();
	GraphNode* getNext();
	void setVertex(int vertex);
	void setColor(Color color);
	//void setDistance(int length);
	void setNext(GraphNode* next);
};
