#pragma once

#include "THeap.h"
#include "TSet.h"
#include "TGraph.h"

static class TKruskalsAlgorithm
{
public:
    //TSet vertices;
    //THeap<TEdge> edges;

    static TGraph findTree(const TGraph& graph);
};

