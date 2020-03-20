#pragma once
#ifndef _GRAPH_NODE_
#define _GRAPH_NODE_

class GraphNode 
{
private:
	int vertex;
	GraphNode* next;

public:
	GraphNode(int vertex);
	GraphNode();
	void setVerex(int vertex);
};


#endif // !_GRAPH_NODE_
