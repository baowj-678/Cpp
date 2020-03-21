#include "graph_node.h"


GraphNode::GraphNode(int vertex) 
{
	this->vertex = vertex;
	this->distance = 1;
	this->next = nullptr;
	this->color = White;
}

GraphNode::GraphNode(int vertex, int length)
{
	this->color = White;
	this->vertex = vertex;
	this->distance = length;
	this->next = nullptr;
}
GraphNode::GraphNode()
{
	this->vertex = -1;
	this->distance = -1;
	this->color = White;
	this->next = nullptr;
}

void GraphNode::setVertex(int vertex)
{
	this->vertex = vertex;
}

void GraphNode::setColor(Color color)
{
	this->color = color;
}

int GraphNode::getVertex()
{
	return this->vertex;
}

Color GraphNode::getColor()
{
	return this->color;
}

void GraphNode::setLength(int length)
{
	this->distance = length;
}

int GraphNode::getLength()
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