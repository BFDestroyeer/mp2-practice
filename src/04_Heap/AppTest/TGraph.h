#pragma once

#include <vector>

struct TEdge
{
    size_t first;
    size_t second;
};

class TGraph
{
    size_t size;
    std::vector<TEdge> edges;

public:
    TGraph(size_t size_, std::vector<TEdge> edges_);
    ~TGraph();

    TEdge operator[](size_t id);
};