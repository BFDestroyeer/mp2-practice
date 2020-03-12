#include "TKruskalsAlgorithm.h"

TGraph TKruskalsAlgorithm::findTree(const TGraph& graph)
{
    TSet vertices(graph.vertices_count);
    for (int i = 0; i < graph.vertices_count; i++)
        vertices.createSubset(i);
    THeap<TEdge> edges(2, graph.edges_count, graph.edges_count, graph.edges);

    TGraph result(graph.vertices_count);

    while ((result.edges_count != result.vertices_count -1))
    {
        TEdge temp = edges.getMinKey();
        edges.removeMinKey();
        if (vertices.getSubsetName(temp.from) != vertices.getSubsetName(temp.to))
        {
            vertices.uniteSubsets(temp.from, temp.to);
            result.insertEdge(temp);
        }
    }

    return result;
}