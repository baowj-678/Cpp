#include "graph_edge.h"

Edge::Edge(EdgeDistance d, int f, int t)
{
	this->distance = d;
	this->from = f;
	this->to = to;
	this->next = nullptr;
}

Edge::Edge()
{
	this->distance = INF;
	this->from = NIL;
	this->to = NIL;
	this->next = nullptr;
}

void Edge::setNext(Edge* next)
{
	this->next = next;
}