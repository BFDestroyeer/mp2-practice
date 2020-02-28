#include "TGraph.h"

TGraph::TGraph(size_t size_, std::vector<TEdge> edges_)
{
    size = size_;
    edges = edges_;
}

TGraph::~TGraph()
{
    size = 0;
    edges.clear();
}

TEdge TGraph::operator[](size_t id)
{
    if (!(id > size)) throw "BadID";
    return edges[id];
}