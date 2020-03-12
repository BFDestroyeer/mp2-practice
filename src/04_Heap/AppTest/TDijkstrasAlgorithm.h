#pragma once

#include "TGraph.h"
#include "THeap.h"

static class TDijkstrasAlgorithm
{
    static TGraph findTree(const TGraph& graph, size_t root);
};

