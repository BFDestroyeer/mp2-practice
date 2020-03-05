#include "TGraph.h"

bool TEdge::operator<(const TEdge& temp) const
{
    return weight < temp.weight;
}

bool TEdge::operator>(const TEdge& temp) const
{
    return weight > temp.weight;
}

std::ostream& operator<<(std::ostream& out, const TEdge& edge)
{
    out << "(" << edge.from << ", " << edge.to << ")";
    return out;
}

TGraph::TGraph(size_t vertices_count_, TEdge* edges_ , size_t edges_count_ )
{
    vertices_count = vertices_count_;
    edges_count = edges_count_;
    edges = new TEdge[vertices_count * (vertices_count - 1) / 2];
    for (int i = 0; i < edges_count; i++)
    {
        edges[i] = edges_[i];
    }
}

TGraph::TGraph(const TGraph& temp)
{
    edges_count = temp.edges_count;
    vertices_count = temp.vertices_count;
    edges = new TEdge[vertices_count * (vertices_count - 1) / 2];
    for (int i = 0; i < edges_count; i++)
    {
        edges[i] = temp.edges[i];
    }
}

TGraph::~TGraph()
{
    delete[] edges;
}

void TGraph::insertEdge(const TEdge& edge)
{
    if (edges_count < vertices_count * (vertices_count - 1) / 2)
    {
        for (int i = 0; i < edges_count; i++)
        {
            if (
                ((edges[i].from == edge.from) && (edges[i].to == edge.to))
                ||
                ((edges[i].from == edge.to) && (edges[i].to == edge.from))
                )
            {
                return;
            }
        }
        edges[edges_count] = edge;
        edges_count++;
        return;
    }
    throw "CANT";
}

std::ostream& operator<<(std::ostream& out, const TGraph& graph)
{
    for (int i = 0; i < graph.edges_count; i++)
    {
        out << graph.edges[i] << " ";
    }
    return out;
}