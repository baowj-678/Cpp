#pragma once
#ifndef _GRAPH_NODE_
#define _GRAPH_NODE_
#define		INF		21474836473
#define		YES		1
#define		NO		0
typedef int Distance;

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
	int vertex;
	Distance distance;
	GraphNode* next;
public:
	GraphNode(int vertex);
	GraphNode(int vertex, int length);
	GraphNode();
	int getVertex();
	int printVertex();
	Distance getDistance();
	GraphNode* getNext();
	void setVertex(int vertex);
	void setColor(Color color);
	void setDistance(int length);
	void setNext(GraphNode* next);
};


#endif // !_GRAPH_NODE_
