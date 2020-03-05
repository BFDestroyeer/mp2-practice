#pragma once

#include <iostream>

struct TEdge
{
    size_t from;
    size_t to;
    int weight;

    bool operator<(const TEdge& temp) const;
    bool operator>(const TEdge& temp) const;
    friend std::ostream& operator<<(std::ostream& out, const TEdge& edge);
};



class TGraph
{
public:
    size_t vertices_count; //Количство вершин(нельзя поменять)
    size_t edges_count; //Количество рёбер
    TEdge* edges;

    TGraph(size_t vertices_count_ = 10, TEdge* edges_ = nullptr, size_t edges_count_ = 0);
    TGraph(const TGraph& temp);
    ~TGraph();

    void insertEdge(const TEdge& edge);

    friend std::ostream& operator<<(std::ostream& out, const TGraph& graph);
};