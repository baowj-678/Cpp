#include "graph_edge.h"

Edge::Edge(EdgeDistance d, int f, int t)
{
	this->distance = d;
	this->from = f;
	this->to = t;
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

int Edge::getFrom()
{
	return this->from;
}

int Edge::getTo()
{
	return this->to;
}

EdgeDistance Edge::getDistance()
{
	return this->distance;
}

Edge* Edge::getNext()
{
	return this->next;
}

bool Edge::cmp(Edge* A, Edge* B)
{
	return A->distance > B->distance;
}