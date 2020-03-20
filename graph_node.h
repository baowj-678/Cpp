#pragma once
#ifndef _GRAPH_NODE_
#define _GRAPH_NODE_
#define BLACK	1
#define WHITE	0
#define GRAY	-1

typedef int Color;

class GraphNode 
{
private:
	int vertex;
	Color color;
	GraphNode* next;

public:
	GraphNode(int vertex);
	GraphNode();
	int getVertex();
	Color getColor();
	void setVertex(int vertex);
	void setColorWhite();
	void setColorGray();
	void setColorBlack();
};


#endif // !_GRAPH_NODE_
