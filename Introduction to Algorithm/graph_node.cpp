#include "graph_node.h"


GraphNode::GraphNode(int vertex) 
{
	this->vertex = vertex;
	this->next = nullptr;
}

GraphNode::GraphNode(int vertex, int length)
{
	this->vertex = vertex;
	this->next = nullptr;
}
GraphNode::GraphNode()
{
	this->vertex = -1;
	this->next = nullptr;
}

void GraphNode::setVertex(int vertex)
{
	this->vertex = vertex;
}


int GraphNode::getVertex()
{
	return this->vertex;
}


int GraphNode::printVertex()
{
	return (this->vertex + 1);
}

void GraphNode::setNext(GraphNode* next)
{
	this->next = next;
}

GraphNode* GraphNode::getNext()
{
	return this->next;
}