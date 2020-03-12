#include "TDijkstrasAlgorithm.h"

TGraph TDijkstrasAlgorithm::findTree(const TGraph& graph, size_t root)
{
    size_t* distance = new size_t[graph.getVerticiesCount()];
    size_t* parent = new size_t[graph.getVerticiesCount()];
    TGraph result;

    for (size_t i = 0; i < graph.getVerticiesCount(); i++)
    {
        parent[i] = 0;
    }
    for (size_t i = 0; i < graph.getVerticiesCount(); i++)
    {
        distance[i] = SIZE_MAX;
    }
    distance[root] = 0;

    THeap<size_t> queue(2, graph.getVerticiesCount(), graph.getVerticiesCount(), distance, false);

    while (!queue.empty())
    {
        size_t min = queue.getMinKey();
        for (size_t i = 0; i < graph.getEdgesCount(); i++)
        {
            
        }
        queue.removeMinKey();
    }
}