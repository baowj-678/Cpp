#include "graph_node.h"


GraphNode::GraphNode(int vertex) 
{
	this->vertex = vertex;
	this->length = 1;
	this->next = nullptr;
	this->color = White;
}

GraphNode::GraphNode(int vertex, int length)
{
	this->color = White;
	this->vertex = vertex;
	this->length = length;
	this->next = nullptr;
}
GraphNode::GraphNode()
{
	this->vertex = -1;
	this->length = -1;
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
	this->length = length;
}

int GraphNode::getLength()
{
	return this->length;
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