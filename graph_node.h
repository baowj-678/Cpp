#pragma once
#ifndef _GRAPH_NODE_
#define _GRAPH_NODE_
#define		INF		-1
#define		YES		1
#define		NO		0
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
	int distance;
	GraphNode* next;
public:
	GraphNode(int vertex);
	GraphNode(int vertex, int length);
	GraphNode();
	int getVertex();
	int printVertex();
	Color getColor();
	int getLength();
	GraphNode* getNext();
	void setVertex(int vertex);
	void setColor(Color color);
	void setLength(int length);
	void setNext(GraphNode* next);
};


#endif // !_GRAPH_NODE_
