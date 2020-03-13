#include "TGraph.h"

bool TEdge::incident(size_t vertex)
{
    return ((from == vertex) || (to == vertex));
}

TEdge& TEdge::operator=(const TEdge& temp)
{
    from = temp.from;
    to = temp.to;
    weight = temp.weight;
    return *this;
}

bool TEdge::operator<(const TEdge& temp) const
{
    return (weight < temp.weight);
}

bool TEdge::operator==(const TEdge& temp) const
{
    return (weight == temp.weight);
}

bool TEdge::operator>(const TEdge& temp) const
{
    return (weight > temp.weight);
}

bool TEdge::operator<=(const TEdge& temp) const
{
    return (weight <= temp.weight);
}

bool TEdge::operator>=(const TEdge& temp) const
{
    return (weight >= temp.weight);
}

size_t TEdge::operator[](size_t id) const
{
    if (id == from)
    {
        return to;
    }
    else if (id == to)
    {
        return from;
    }
    else
    {
        throw "BAD ID";
    }
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
        insertEdge(edges_[i]);
    }
}

TGraph::TGraph(const TGraph& temp)
{
    edges_count = temp.edges_count;
    vertices_count = temp.vertices_count;
    edges = new TEdge[vertices_count * (vertices_count - 1) / 2];
    for (size_t i = 0; i < edges_count; i++)
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
    if (edges_count >= vertices_count * (vertices_count - 1) / 2) throw "FULL";
    if ((edge.from >= vertices_count) || (edge.to >= vertices_count)) throw "BAD EDGE";
    for (int i = 0; i < edges_count; i++)
    {
        if ((edges[i].incident(edge.from)) && (edges[i].incident(edge.to))) return;
    }
    edges[edges_count] = edge;
    edges_count++;
    return;
}

size_t TGraph::getVerticiesCount() const
{
    return vertices_count;
}

size_t TGraph::getEdgesCount() const
{
    return edges_count;
}

bool TGraph::connected() const
{
    //TODO:
    return true;
}

std::ostream& operator<<(std::ostream& out, const TGraph& graph)
{
    for (int i = 0; i < graph.edges_count; i++)
    {
        out << graph.edges[i] << " ";
    }
    return out;
}