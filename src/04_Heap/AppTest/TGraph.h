#pragma once

#include <iostream>

#include "THeap.h"
#include "TException.h"

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

    size_t operator[](size_t id) const;

    friend std::ostream& operator<<(std::ostream& out, const TEdge& edge);
};


class TGraph
{
private:
    size_t vertices_count; //Количство вершин(нельзя поменять)
    size_t edges_count;    //Количество рёбер
    TEdge* edges;          //Массив рёбер

public:
    TGraph(size_t vertices_count_ = 10, TEdge* edges_ = nullptr, size_t edges_count_ = 0);
    TGraph(const TGraph& temp);
    ~TGraph();

    //Вставка вершины
    void insertEdge(const TEdge& edge);

    size_t getVerticiesCount() const;
    size_t getEdgesCount() const;

    bool connected() const;

    TEdge operator[](size_t id) const;

    friend std::ostream& operator<<(std::ostream& out, const TGraph& graph);

    friend class TKruskalsAlgorithm;
};