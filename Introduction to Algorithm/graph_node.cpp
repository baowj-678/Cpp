#include "graph_node.h"


GraphNode::GraphNode(int vertex) 
{
	this->vertex = vertex;
	this->distance = 1;
	this->next = nullptr;
}

GraphNode::GraphNode(int vertex, int length)
{
	this->vertex = vertex;
	this->distance = length;
	this->next = nullptr;
}
GraphNode::GraphNode()
{
	this->vertex = -1;
	this->distance = -1;
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

void GraphNode::setDistance(int length)
{
	this->distance = length;
}

int GraphNode::getDistance()
{
	return this->distance;
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