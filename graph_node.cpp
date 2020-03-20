#include "graph_node.h"


GraphNode::GraphNode(int vertex) 
{
	this->vertex = vertex;
	this->next = nullptr;
	this->color = WHITE;
}

GraphNode::GraphNode()
{
	this->vertex = 0;
	this->color = WHITE;
	this->next = nullptr;
}

void GraphNode::setVertex(int vertex)
{
	this->vertex = vertex;
}

void GraphNode::setColorBlack()
{
	this->color = BLACK;
}

void GraphNode::setColorGray()
{
	this->color = GRAY;
}

void GraphNode::setColorWhite()
{
	this->color = WHITE;
}

int GraphNode::getVertex()
{
	return this->vertex;
}

Color GraphNode::getColor()
{
	return this->color;
}