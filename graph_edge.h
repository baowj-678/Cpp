#pragma once
#ifndef _GRAPH_EDGE_
#define _GRAPH_EDGE_
#define		INF		-1
#define		NIL		-1
typedef int EdgeDistance;

class Edge
{
private:
	EdgeDistance distance;
	int from;
	int to;
	Edge* next;

public:
	Edge();
	Edge(EdgeDistance d, int f, int t);
	void setNext(Edge* next);
	int getFrom();
	int getTo();
	EdgeDistance getDistance();
	Edge* getNext();
	bool cmp(Edge* A, Edge* B);

};



#endif // !_GRAPH_EDGE_
