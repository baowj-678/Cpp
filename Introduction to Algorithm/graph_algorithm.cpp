#include "graph.h"
#include <algorithm>
#include <vector>

using namespace::std;
GraphNode* Graph::MSTkruskal()
{
	vector<Edge> heap(this->edges, this->edges + this->num_e);
	make_heap(heap.begin(), heap.end(), Edge::cmp);
	sort_heap(heap.begin(), heap.end(), Edge::cmp);
	return nullptr;
}
GraphNode* Graph::MSTprim()
{
	return nullptr;
}