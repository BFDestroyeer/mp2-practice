#pragma once

#include <iostream>

struct TEdge
{
    size_t from; //Исходящая вершина
    size_t to;   //Входящая вершина
    int weight;  //Вес ребра

    bool incident(size_t vertex);

    TEdge& operator=(const TEdge& temp);

    bool operator<(const TEdge& temp) const;
    bool operator==(const TEdge& temp) const;
    bool operator>(const TEdge& temp) const;
    bool operator<=(const TEdge& temp) const;
    bool operator>=(const TEdge& temp) const;

    friend std::ostream& operator<<(std::ostream& out, const TEdge& edge);
};


class TGraph
{
public:
    size_t vertices_count; //Количство вершин(нельзя поменять)
    size_t edges_count;    //Количество рёбер
    TEdge* edges;          //Массив рёбер

    TGraph(size_t vertices_count_ = 10, TEdge* edges_ = nullptr, size_t edges_count_ = 0);
    TGraph(const TGraph& temp);
    ~TGraph();

    //Вставка вершины
    void insertEdge(const TEdge& edge);

    size_t getVerticiesCount() const;
    size_t getEdgesCount() const;

    friend std::ostream& operator<<(std::ostream& out, const TGraph& graph);
};