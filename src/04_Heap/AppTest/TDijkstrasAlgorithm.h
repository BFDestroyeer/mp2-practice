#pragma once

#include "TGraph.h"
#include "THeap.h"

struct VertexDistance
{
    size_t vertex;
    int distance;

    bool operator<(const VertexDistance& temp);
    bool operator>(const VertexDistance& temp);
    bool operator==(const VertexDistance& temp);
};

static class TDijkstrasAlgorithm
{
    static TGraph findTree(const TGraph& graph, size_t root);
};

