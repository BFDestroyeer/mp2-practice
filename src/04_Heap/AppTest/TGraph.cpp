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
        throw TException(BadId, __LINE__);
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
    if (edges_count >= vertices_count * (vertices_count - 1) / 2) throw TException(ContainerIsFull, __LINE__);
    if ((edge.from >= vertices_count) || (edge.to >= vertices_count)) throw TException(BadEdge, __LINE__);
    if (edge.from == edge.to) throw TException(BadEdge, __LINE__);
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
    if (vertices_count == 0) return true;

    THeap<size_t> queue(2, vertices_count);
    bool* group = new bool[vertices_count];
    for (size_t i = 0; i < vertices_count; i++)
    {
        group[i] = 0;
    }
    
    queue.insert(0);
    group[0] = true;

    while (!queue.empty())
    {
        size_t vertex = queue.getMinKey();
        for (size_t i = 0; i < edges_count; i++)
        {
            if (edges[i].incident(vertex) && !group[edges[i][vertex]])
            {
                queue.insert(edges[i][vertex]);
                group[edges[i][vertex]] = true;
            }
        }
        queue.removeMinKey();
    }

    for (size_t i = 0; i < vertices_count; i++)
    {
        if (!group[i])
        {
            delete[] group;
            return false;
        }
    }
    delete[] group;
    return true;
}

TEdge TGraph::operator[](size_t id) const
{
    if (id < edges_count)
    {
        return edges[id];
    }
    else
    {
        throw TException(BadId, __LINE__);
    }
}

std::ostream& operator<<(std::ostream& out, const TGraph& graph)
{
    for (int i = 0; i < graph.edges_count; i++)
    {
        out << graph.edges[i] << " ";
    }
    return out;
}